/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:17:48 by bohlee            #+#    #+#             */
/*   Updated: 2024/03/06 14:33:58 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &target) { (void)target; }

PmergeMe	&PmergeMe::operator=(const PmergeMe &target) { (void)target; return *this; }

PmergeMe::~PmergeMe(void)
{
	vt.clear();
	dq.clear();
}

int		PmergeMe::jacobsthalNumber(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return jacobsthalNumber(n - 1) + 2 * jacobsthalNumber(n - 2);
}

void	PmergeMe::sort(int argc, char **argv) throw(std::exception)
{
	std::list<uint64_t>	lt;
	{
		double	num;
		char	*ptr;
	
		for (int i = 1; i < argc; i++)
		{
			num = strtod(argv[i], &ptr);
			if (*ptr != '\0'
					|| (static_cast<uint64_t>(num) != num)
					|| (num == 0 && !isdigit(*(argv[i]))))
				throw std::runtime_error("Error");
			vt.push_back(num);
			dq.push_back(num);
			lt.push_back(num);
		}
	}
	std::cout << "before:\t";
	for (std::list<uint64_t>::iterator it = lt.begin(); it != --lt.end(); it++)
		std::cout << *it << " ";
	std::cout << *(--lt.end()) << std::endl;
	lt.sort();
	std::cout << "after:\t";
	for (std::list<uint64_t>::iterator it = lt.begin(); it != --lt.end(); it++)
		std::cout << *it << " ";
	std::cout << *(--lt.end()) << std::endl;

	int size = argc - 1;
	int node;

	clock_t	dq_bf = clock();
	node = this->splitPair(1, size, dq);
	this->insertMerge(size, node, dq);
	clock_t	dq_af = clock();

	clock_t	vt_bf = clock();
	node = this->splitPair(1, size, vt);
	this->insertMerge(size, node, vt);
	clock_t	vt_af = clock();

	std::vector<uint64_t>::iterator vit = vt.begin();
	std::deque<uint64_t>::iterator dit = dq.begin();
	for (std::list<uint64_t>::iterator lit = lt.begin(); lit != lt.end(); lit++)
	{
		if (*lit != *dit || *lit != *vit)
		{
			std::cerr << "not sort!!" << std::endl;
			return ;
		}
		vit++;
		dit++;
	}
	std::cout << "Time to process a range of\t" << size << " elements with std::vector : " << 1000.0 * (vt_af - vt_bf) / CLOCKS_PER_SEC << " ms" << std::endl;
	std::cout << "Time to process a range of\t" << size << " elements with std::deque  : " << 1000.0 * (dq_af - dq_bf) / CLOCKS_PER_SEC << " ms" << std::endl;
}

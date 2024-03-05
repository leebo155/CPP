/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:17:48 by bohlee            #+#    #+#             */
/*   Updated: 2024/03/05 12:41:19 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &target) { (void)target; }

PmergeMe	&PmergeMe::operator=(const PmergeMe &target) { (void)target; return *this; }

PmergeMe::~PmergeMe(void)
{
	vt.clear();
	lt.clear();
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
			lt.push_back(num);
		}
	}
	std::cout << "vector: ";
	for (std::vector<uint64_t>::iterator it = vt.begin(); it != vt.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
//	std::cout << "list: ";
//	for (std::list<uint64_t>::iterator it = lt.begin(); it != lt.end(); it++)
//		std::cout << *it << " ";
//	std::cout << std::endl;	

	int i = 2;
	int	di;
	int nodes;
	int size = argc - 1;

	this->splitPair(size, vt);
	while (i < size)
	{
		di = i + i;
		nodes = size / di;
		this->mergeRecur(0, nodes * di - 1, i,  vt);
		i += i;
	}
	i /= 2;
	while (i > 1)
	{
		i /= 2;
		nodes = size / i;
		this->insertMerge(nodes, i, vt);
	}
//	std::cout << "\nvector: ";
//	for (std::vector<uint64_t>::iterator it = vt.begin(); it != vt.end(); it++)
//		std::cout << *it << " ";
//	std::cout << std::endl;
//	std::cout << "list: ";
//	for (std::list<uint64_t>::iterator it = lt.begin(); it != lt.end(); it++)
//		std::cout << *it << " ";
//	std::cout << std::endl;	
}


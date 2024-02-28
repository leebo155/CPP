/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:17:48 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/28 20:10:29 by bohlee           ###   ########.fr       */
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

void	PmergeMe::splitMerge(int a, int b, int node_size, T &t)
{
	if (b  - a < node_size)
		return ;
	else if (b - a == node_size )
	{
		if (t.at(a) < t.at(b))
		{
			t.insert(t.begin() + a,
					t.begin() + b, t.begin() + b + node_size);
			t.erase(t.begin() + b + node_size + 1,
					t.begin() b + node_size * 2 + 1);
		}
		return ;
	}
	int size = (b - a) / 2;
	this->splitMerge(a, size, t);
	this->splitMerge(a + size + 1, end, t);	
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
	std::cout << "\nvector: ";
	for (std::vector<uint64_t>::iterator it = vt.begin(); it != vt.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "list: ";
	for (std::list<uint64_t>::iterator it = lt.begin(); it != lt.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;	

	for (int i = 1; i <= (argc - 1) / 2; i * 2)
		this->splitMerge(0, (argc - 1) / i * i, i, vt);

	std::cout << "vector: ";
	for (std::vector<uint64_t>::iterator it = vt.begin(); it != vt.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "list: ";
	for (std::list<uint64_t>::iterator it = lt.begin(); it != lt.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;	
}


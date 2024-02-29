/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:17:48 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/29 20:42:27 by bohlee           ###   ########.fr       */
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

	this->splitPair(argc - 1, vt);
	for (int i = 2; i <= (argc - 1) / 2; i += i)
		this->mergeRecur(0, (argc - 1) / (i * 2) * (i * 2) - 1, i,  vt);

//	std::cout << "\nvector: ";
//	for (std::vector<uint64_t>::iterator it = vt.begin(); it != vt.end(); it++)
//		std::cout << *it << " ";
//	std::cout << std::endl;
//	std::cout << "list: ";
//	for (std::list<uint64_t>::iterator it = lt.begin(); it != lt.end(); it++)
//		std::cout << *it << " ";
//	std::cout << std::endl;	
}


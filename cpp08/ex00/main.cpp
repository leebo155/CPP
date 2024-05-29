/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:09:56 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/21 17:44:51 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v;
	std::deque<int> d;
	std::list<int> l;

	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	d.push_front(1);
	d.push_front(3);
	d.push_front(4);

	l.push_back(1);
	l.push_back(2);
	l.push_back(4);

	std::cout << "std::vector<int> = {2, 3, 4};\nstd::deque<int> = {4, 3, 1};\nstd::list<int> = {1, 2, 4};\n" << std::endl;

	for (int i = 1; i < 5; i++)
	{
		try {
			std::vector<int>::iterator vit = easyfind(v, i);
			std::cout << "vector<int>: " << *vit << " find" << std::endl;
		} catch (std::exception &e) {
			std::cerr << "vector<int>: " << i << " " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	for (int i = 1; i < 5; i++)
	{

		try {
			std::deque<int>::iterator dit = easyfind(d, i);
			std::cout << "deque<int>: " << *dit << " find" << std::endl;
		} catch (std::exception &e) {
			std::cerr << "deque<int>: " << i << " " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	for (int i = 1; i < 5; i++)
	{
		try {
			std::list<int>::iterator lit = easyfind(l, i);
			std::cout << "list<int>: " << *lit << " find" << std::endl;
		} catch (std::exception &e) {
			std::cerr << "list<int>: " << i << " " << e.what() << std::endl;
		}
	}
	
	return 0;
}

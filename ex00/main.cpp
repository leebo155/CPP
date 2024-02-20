/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:09:56 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/20 20:58:11 by bohlee           ###   ########.fr       */
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

	for (int i = 0; i < 2; i++)
	{
		v.push_back(i);
		d.push_back(i);
		l.push_back(i);
	}

	for (int i = 3; i < 5; i++)
	{
		v.push_back(i);
		d.push_back(i);
		l.push_back(i);
	}

	for (int i = 0; i < 5; i++)
	{
		try {
			std::vector<int>::iterator it = easyfind(v, i);
			std::cout << *it << " find" << std::endl;
		} catch (std::exception &e) {
			std::cerr << i << " " << e.what() << std::endl;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		try {
			std::deque<int>::iterator it = easyfind(d, i);
			std::cout << *it << " find" << std::endl;
		} catch (std::exception &e) {
			std::cerr << i << " " << e.what() << std::endl;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		try {
			std::list<int>::iterator it = easyfind(l, i);
			std::cout << *it << " find" << std::endl;
		} catch (std::exception &e) {
			std::cerr << i << " " << e.what() << std::endl;
		}
	}
	return 0;
}

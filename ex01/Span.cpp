/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:34:46 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/22 15:21:22 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n): size(n) {}

Span::Span(void): size(0) {}

Span::Span(const Span &target): size(0)
{
	*this = target;
}

Span	&Span::operator=(const Span &target)
{
	if (this != &target)
	{
		size = target.size;
		storage.resize(target.storage.size());
		std::copy(target.storage.begin(), target.storage.end(), storage.begin());
	}
	return *this;
}

Span::~Span(void) {}

void	Span::printElements(void)
{
	std::cout << "{ ";
	std::list<int>::iterator it = storage.begin();
	while (it != storage.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << "}" << std::endl;
}

void	Span::addNumber(int n) throw(std::exception)
{
	if (storage.size() == size)
		throw std::out_of_range("storage is full");
	storage.push_back(n);
}

void	Span::addNumber(unsigned int n, int min, int max) throw(std::exception)
{
	if (min > max)
		throw std::runtime_error("minimum is greater than the maximum");
	unsigned int range = max - min;
	srand(time(NULL));
	for (unsigned int i = 0; i < n; i++)
		this->addNumber(static_cast<double>(rand()) / RAND_MAX * range + min);
}

unsigned int	Span::shortestSpan(void) throw(std::exception)
{
	if (storage.size() < 2)
		throw std::runtime_error("not enough elements");

	storage.sort();
	std::list<int>::iterator iter1 = storage.begin();
	std::list<int>::iterator iter2 = iter1++;
	long long tmp = abs(*iter1 - static_cast<long long>(*iter2));
	while (iter1 != storage.end())
	{
		if (tmp > abs(*iter1 - static_cast<long long>(*iter2)))
			tmp = abs(*iter1 - static_cast<long long>(*iter2));
		iter1++;
		iter2++;
	}
	return tmp;
}

unsigned int	Span::longestSpan(void) throw(std::exception)
{
	if (storage.size() < 2)
		throw std::runtime_error("not enough elements");
	
	std::list<int>::iterator iter1 = storage.begin();
	std::list<int>::iterator iter2 = storage.end();
	iter2--;
	
	return abs(*iter2 - static_cast<long long>(*iter1));
}

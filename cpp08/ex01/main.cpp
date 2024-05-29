/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:23:53 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/22 17:22:04 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main()
{
	try {
		std::cout << "Test0: default" << std::endl;
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		sp.printElements();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	
		std::cout << "\nTest1: full storage" << std::endl;
		try {
			sp.addNumber(15);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		
		std::cout << "\nTest2: empty storage shortestSpan(), longestSpan()" << std::endl;
		Span span = Span(100);
		try {
			std::cout << span.shortestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << span.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\nTest3: addNumber(size, min, max)" << std::endl;
		try {
			span.addNumber(100, -2147483648, 2147483647);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		span.printElements();
	
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	
		std::cout << "\nTest4: boundary test" << std::endl;
		Span test(10);
		test.addNumber(-2147483648);
		test.addNumber(2147483647);
		test.printElements();
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;

		std::cout << "\nTest5: deep copy" << std::endl;
		Span copy = Span(test);
		copy.addNumber(0);
		test.printElements();
		copy.printElements();
		std::cout << copy.shortestSpan() << std::endl;
		std::cout << copy.longestSpan() << std::endl;

	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

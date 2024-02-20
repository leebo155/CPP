/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:48:41 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/20 15:24:54 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void	intOnePlusPrint(const int i)
{
	std::cout << i + 1 << std::endl;
}

void	strLengthPrint(const std::string str)
{
	std::cout << str.length() << std::endl;
}

int	main()
{

	int	i[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::string str[3] = {"Hello", "World", "42seoul"};

	std::cout << "Test1: templatePrint(int)" << std::endl;
	::iter(i, 10, &templatePrint);
	std::cout << "\nTest2: templatePrint(string)" << std::endl;
	::iter(str, 3, &templatePrint);
	std::cout << "\nTest3: doublePrint(int)" << std::endl;
	::iter(i, 10, &doublePrint);
	std::cout << "\nTest4: doublePrint(string)" << std::endl;
	::iter(str, 3, &doublePrint);
	std::cout << "\nTest5: intOnePlusPrint(int)" << std::endl;
	::iter(i, 10, &intOnePlusPrint);
	std::cout << "\nTest6: strLengthPrint(string)" << std::endl;
	::iter(str, 3, &strLengthPrint);

	return 0;

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:15:06 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/25 17:23:55 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &target)
{
	(void)target;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &target)
{
	(void)target;
	return *this;
}

ScalarConverter::~ScalarConverter(void)
{
}

void	ScalarConverter::convert(std::string str)
{
	char	*ptr = NULL;
//	double	inf = std::strtod("inf", &ptr);
//	double	minf = std::strtod("-inf", &ptr);
	double	num = std::strtod(str.c_str(), &ptr);
			
	if ((num == 0.0 && ((str[0] != '-') && (str[0] != '+') && (!std::isdigit(str[0]))))
			|| (*ptr != 'f' && *ptr != 0)
			|| (*ptr && ptr[1] != 0))
	{
		std::cout << "Error: " << str << " Is not number." << std::endl;
		return ;
	}

	std::cout << "char: ";
	if (num < CHAR_MIN || CHAR_MAX < num)
		std::cout << "impossible" << std::endl;
	else if	(std::isprint(num))
		std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << num << std::endl;
	std::cout << "float: " << num << "f" << std::endl;
	std::cout << "double: " << num << std::endl;
}

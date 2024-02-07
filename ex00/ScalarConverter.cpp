/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:15:06 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/29 16:50:35 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &target)
{
	static_cast<void>(target);
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &target)
{
	static_cast<void>(target);
	return *this;
}

ScalarConverter::~ScalarConverter(void)
{
}

void	ScalarConverter::convert(std::string str)
{
	char	*ptr = NULL;
	double	num = strtod(str.c_str(), &ptr);
			
	if ((num == 0.0 && ((str[0] != '-') && (str[0] != '+') && (!std::isdigit(str[0]))))
			|| (*ptr != 'f' && *ptr != 0)
			|| (*ptr && ptr[1] != 0))
	{
		std::cout << "Error: " << str << " Is not number." << std::endl;
		return ;
	}

	std::cout << "char: ";
	if ((num < -128 || 127 < num)
			|| (str.find("nan") != std::string::npos))
		std::cout << "impossible" << std::endl;
	else if	(std::isprint(num))
		std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	if ((num < -2147483648 || 2147483647 < num)
			|| (str.find("nan") != std::string::npos))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(num) << std::endl;
	std::cout << "float: " << static_cast<float>(num);
	if (static_cast<int>(num) == static_cast<float>(num)
			&& (-1000000 < num && num < 1000000))
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << num;
	if (static_cast<int>(num) == num
			&& (-1000000 < num && num < 1000000))
		std::cout << ".0";
	std::cout << std::endl;
}

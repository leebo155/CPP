/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:15:06 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/08 14:37:59 by bohlee           ###   ########.fr       */
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
	double		num;
	std::string	upper_str;

	if (str.empty())
	{
		std::cerr << "Error: empty argument." << std::endl;
		return ;
	}
	else if (str.length() == 1)
		num = static_cast<double>(*(str.c_str()));
	else
	{
		for (size_t i = 0; i < str.length(); i++)
			upper_str.push_back(std::toupper(str[i]));

		char	*ptr = 0;
		num = strtod(upper_str.c_str(), &ptr);
			
		if ((num == 0.0 && ((upper_str[0] != '-') && (upper_str[0] != '+') && (!std::isdigit(upper_str[0]))))
				|| (*ptr != 'F' && *ptr != 0)
				|| (*ptr && ptr[1] != 0))
		{
			std::cerr << "Error: " << str << " Is not number." << std::endl;
			return ;
		}
	}

	std::cout << "char: ";
	if ((num < CHAR_MIN || CHAR_MAX < num)
			|| (upper_str.find("NAN") != std::string::npos))
		std::cout << "impossible" << std::endl;
	else if	(std::isprint(num))
		std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	if ((num < INT_MIN || INT_MAX < num)
			|| (upper_str.find("NAN") != std::string::npos))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(num) << std::endl;
	std::cout << "float: " << static_cast<float>(num);
	if ((-1000000 < num && num < 1000000)
			&& (static_cast<int>(num) == static_cast<float>(num)))
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << num;
	if ((-1000000 < num && num < 1000000)
			&& (static_cast<int>(num) == static_cast<float>(num)))
		std::cout << ".0";
	std::cout << std::endl;
}

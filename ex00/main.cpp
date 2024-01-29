/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:27:45 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/29 13:57:41 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: no input." << std::endl;
		return -1;
	}

	try {
		ScalarConverter::convert(argv[1]);
	}
	catch (...) {
		std::cout << "Error: somthing wrong..." << std::endl;
	}

	return 0;
}

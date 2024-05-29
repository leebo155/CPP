/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:27:45 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/08 14:39:22 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: can only have one argument." << std::endl;
		return -1;
	}

	try {
		ScalarConverter::convert(argv[1]);
	}
	catch (...) {
		std::cerr << "Error: somthing wrong..." << std::endl;
	}

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:39:07 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/27 18:16:17 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	try {
		if (argc - 1 == 0)
			throw std::runtime_error("Error");

		RPN rpn;
		rpn.calculate(argc, argv);

	} catch(std::exception &e) {

		std::cerr << e.what() << std::endl;
		return 1;

	}

	return 0;
}

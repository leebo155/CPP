/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:01:44 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/28 16:49:27 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	try {
		if (argc - 1 < 2)
			throw std::runtime_error("Error");

		PmergeMe	pm;
		pm.sort(argc, argv);
	} catch (std::exception &e) {

		std::cerr << e.what() << std::endl;
		return 1;

	}

	return 0;
}

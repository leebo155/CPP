/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:32:12 by bohlee            #+#    #+#             */
/*   Updated: 2023/10/18 21:32:27 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char *argv[])
{
	int	StrIndex;
	int	CharIndex;

	if (argc - 1 == 0)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	StrIndex = 0;
	while (++StrIndex < argc)
	{
		CharIndex = 0;
		while (argv[StrIndex][CharIndex])
			std::cout << (char)(std::toupper(argv[StrIndex][CharIndex++]));
	}
	std::cout << std::endl;
	return 0;
}

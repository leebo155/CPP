/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:46:12 by bohlee            #+#    #+#             */
/*   Updated: 2023/11/09 17:14:10 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char *argv[])
{
	if (argc - 1 != 2)
	{
		std::cout << "usage: ./zombie [amount of zombies] [name]" << std::endl;
		return (1);
	}
	
	int	amount = std::atoi(argv[1]);
	int	index = 0;
	Zombie* zombies = zombieHorde(amount, argv[2]);

	while (index < amount)
	{
		std::cout << index + 1 << " ";
		zombies[index++].announce();
	}
	delete[] zombies;
	return 0;
}

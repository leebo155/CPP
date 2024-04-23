/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:37:43 by bohlee            #+#    #+#             */
/*   Updated: 2023/11/29 15:11:28 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap tom("Tom");
	ClapTrap *alice = new ClapTrap("Alice");

	std::cout << " Tom Energy : " << tom.getEnergy() << std::endl;
	tom.attack(alice->getName());
	alice->takeDamage(tom.getDamage());
	std::cout << " Tom Energy : " << tom.getEnergy() << "\n" << std::endl;
	tom.setEnergy(0);
	std::cout << " Tom Energy : " << tom.getEnergy() << "\n" << std::endl;
	tom.attack(alice->getName());

	std::cout << "\n Alice Health : " << alice->getHealth() << std::endl;
	alice->takeDamage(9);
	std::cout << " Alice Health : " << alice->getHealth() << "\n" << std::endl;
	alice->beRepaired(12);
	std::cout << " Alice Health : " << alice->getHealth() << std::endl;
	std::cout << " Alice Energy : " << alice->getEnergy() << "\n" << std::endl;
	alice->takeDamage(10);
	std::cout << " Alice Health : " << alice->getHealth() << "\n" << std::endl;
	alice->beRepaired(10);
	std::cout << " Alice Health : " << alice->getHealth() << std::endl;
	std::cout << " Alice Energy : " << alice->getEnergy() << "\n" << std::endl;
	std::cout << std::endl;
	delete(alice);
	std::cout << std::endl;

	return 0;
}

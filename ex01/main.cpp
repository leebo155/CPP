/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:37:43 by bohlee            #+#    #+#             */
/*   Updated: 2023/11/29 15:08:02 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

	delete(alice);

	std::cout << "\n====== ScavTrap Test ======" << std::endl;
	ScavTrap bob("Bob");
	ScavTrap *andy = new ScavTrap("Andy");
	
	std::cout << " Andy Health : " << andy->getHealth() << std::endl;
	std::cout << " Andy Energy : " << andy->getEnergy() << std::endl;
	std::cout << " Bob Energy : " << bob.getEnergy() << "\n" << std::endl;
	bob.attack(andy->getName());
	andy->takeDamage(bob.getDamage());
	std::cout << " Andy Health : " << andy->getHealth() << std::endl;
	std::cout << " Bob Energy : " << bob.getEnergy() << "\n" << std::endl;
	andy->beRepaired(30);
	std::cout << " Andy Health : " << andy->getHealth() << std::endl;
	std::cout << " Andy Energy : " << andy->getEnergy() << "\n" << std::endl;
	andy->takeDamage(120);
	std::cout << " Andy Health : " << andy->getHealth() << std::endl;
	andy->beRepaired(100);
	std::cout << " Andy Health : " << andy->getHealth() << "\n" << std::endl;

	std::cout << " Bob Energy : " << bob.getEnergy() << std::endl;
	bob.guardGate();
	std::cout << " Bob Energy : " << bob.getEnergy() << "\n" << std::endl;
	bob.setGate(true);
	bob.guardGate();
	std::cout << " Bob Energy : " << bob.getEnergy() << "\n" << std::endl;
	bob.setGate(false);
	std::cout << " Bob Energy : " << bob.getEnergy() << "\n" << std::endl;
	bob.setEnergy(0);
	std::cout << " Bob Energy : " << bob.getEnergy() << std::endl;
	bob.guardGate();
	bob.setGate(true);
	std::cout << std::endl;
	delete(andy);
	std::cout << std::endl;

	return 0;
}

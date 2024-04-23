/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:37:43 by bohlee            #+#    #+#             */
/*   Updated: 2023/11/30 19:48:36 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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
	bob.guardGate();
	bob.setGate(true);
	std::cout << " Bob Energy : " << bob.getEnergy() << "\n" << std::endl;

	delete(andy);

	std::cout << "\n====== FragTrap Test ======" << std::endl;
	FragTrap john("John");
	FragTrap *jane = new FragTrap("Jane");

	std::cout << " Jane Health : " << jane->getHealth() << std::endl;
	std::cout << " Jane Energy : " << jane->getEnergy() << std::endl;
	std::cout << " John Energy : " << john.getEnergy() << "\n" << std::endl;
	john.attack(jane->getName());
	jane->takeDamage(john.getDamage());
	std::cout << " Jane Health : " << jane->getHealth() << std::endl;
	std::cout << " John Energy : " << john.getEnergy() << "\n" << std::endl;
	jane->beRepaired(50);
	std::cout << " Jane Health : " << jane->getHealth() << std::endl;
	std::cout << " Jane Energy : " << jane->getEnergy() << "\n" << std::endl;
	jane->takeDamage(120);
	std::cout << " Jane Health : " << jane->getHealth() << std::endl;
	jane->beRepaired(100);
	std::cout << " Jane Health : " << jane->getHealth() << "\n" << std::endl;

	std::cout << "John Energy : " << john.getEnergy() << std::endl;
	john.highFivesGuys();
	std::cout << "John Energy : " << john.getEnergy() << "\n" << std::endl;
	john.highFivesGuys();
	std::cout << "John Energy : " << john.getEnergy() << "\n" << std::endl;
	john.highFivesGuys();
	std::cout << "John Energy : " << john.getEnergy() << "\n" << std::endl;
	john.setEnergy(0);
	std::cout << "John Energy : " << john.getEnergy() << std::endl;
	john.highFivesGuys();
	std::cout << std::endl;
	delete(jane);
	std::cout << std::endl;

	std::cout << "\n====== DiamondTrap Test ======" << std::endl;
	DiamondTrap michael("Michael");
	DiamondTrap *sam = new DiamondTrap("Sam");

	std::cout << "\nMichael name : " << michael.getName() << std::endl;
	std::cout << "Michael Health : " << michael.getHealth() << std::endl;
	std::cout << "Michael Energy : " << michael.getEnergy() << std::endl;
	std::cout << "Michael Attack damage : " << michael.getDamage() << "\n" << std::endl;
	michael.attack(sam->getName());
	sam->takeDamage(michael.getDamage());
	std::cout << "Michael Energy : " << michael.getEnergy() << std::endl;
	std::cout << "Sam Health : " << sam->getHealth() << "\n" << std::endl;
	sam->beRepaired(35);
	std::cout << "Sam Health : " << sam->getHealth() << std::endl;
	std::cout << "Sam Energy : " << sam->getEnergy() << "\n" << std::endl;
	michael.whoAmI();
	std::cout << "Michael Energy : " << michael.getEnergy() << "\n" << std::endl;
	sam->whoAmI();
	std::cout << "Sam Energy : " << sam->getEnergy() << "\n" << std::endl;
	sam->setEnergy(0);	
	std::cout << "Sam Energy : " << sam->getEnergy() << "\n" << std::endl;
	sam->whoAmI();
	michael.takeDamage(150);
	std::cout << "Michael Health : " << michael.getHealth() << "\n" << std::endl;
	michael.beRepaired(200);
	std::cout << std::endl;
	delete(sam);
	std::cout << std::endl;

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:11:27 by bohlee            #+#    #+#             */
/*   Updated: 2023/11/11 15:40:01 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name, Weapon &weapon)
{
	this->name = name;
	this->weapon = &weapon;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = 0;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void) const
{
	std::cout << name;
	if (!weapon)
	{
		std::cout << " can't attack" << std::endl;
		return ;
	}
	std::cout << " attacks with their " << weapon->getType() << std::endl;
}

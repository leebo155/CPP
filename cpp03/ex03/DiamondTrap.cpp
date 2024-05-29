/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:49:23 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/06 13:47:58 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "+DiamondTrap Default constructor called." << std::endl;
	this->name = "Monster";
	this->ClapTrap::name = this->name + "_clap_name";
	this->hit_point = this->hit_point_max = FragTrap::frag_health_max;
	this->energy_point = this->energy_point_max = ScavTrap::scav_energy_max;
	this->attack_damage = FragTrap::frag_default_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &target): ClapTrap(target), ScavTrap(target), FragTrap(target)
{
	std::cout << "+DiamondTrap copy constructor called." << std::endl;
	*this = target;
}

DiamondTrap &DiamondTrap::operator= (const DiamondTrap &target)
{
	std::cout << "+DiamondTrap copy assignment constructor called." << std::endl;
	if (this != &target)
	{
		this->name = target.getName();
		ClapTrap::name = this->getName() + "_clap_name";
		this->hit_point_max = FragTrap::frag_health_max;
		this->energy_point_max = ScavTrap::scav_energy_max;
		this->attack_damage = target.getDamage();
		this->hit_point = target.getHealth();
		this->energy_point = target.getEnergy();
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "-DiamondTrap Destructor called." << std::endl;
	std::cout << "-- DiamondTrap " << this->name << " stops working..." << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name)
{
	std::cout << "+DiamondTrap Name parameter constructor called." << std::endl;
	this->name = _name;
	this->ClapTrap::name = this->name + "_clap_name";
	this->hit_point = this->hit_point_max = FragTrap::frag_health_max;
	this->energy_point = this->energy_point_max = ScavTrap::scav_energy_max;
	this->attack_damage = FragTrap::frag_default_damage;
}

std::string	DiamondTrap::getName(void) const
{
	return this->name;
}

void	DiamondTrap::whoAmI(void)
{
	if (this->checkEnergy() || !this->hit_point)
		return ;
	this->energy_point--;
	std::cout << "Hi! I'm " << this->name << " and " << ClapTrap::name << ".\nNice to meet you." << std::endl;
}

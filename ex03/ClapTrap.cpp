/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:42:23 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/06 13:43:27 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "+ClapTrap Default constructor called." << std::endl;
	name = "Nobody";
	hit_point = hit_point_max = clap_health_max;
	energy_point = energy_point_max = clap_energy_max;
	attack_damage = clap_default_damage;

}

ClapTrap::ClapTrap(const ClapTrap &target)
{
	std::cout << "+ClapTrap Copy constructor called." << std::endl;
	*this = target;
}

ClapTrap	&ClapTrap::operator= (const ClapTrap &target)
{
	std::cout << "+ClapTrap Copy assignment constructor called." << std::endl;
	if (this != &target)
	{
		this->name = target.getName();
		this->hit_point = target.getHealth();
		this->energy_point = target.getEnergy();
		this->attack_damage = target.getDamage();	
		this->hit_point_max = this->clap_health_max;
		this->energy_point_max = this->clap_energy_max;
	}
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "-ClapTrap Destructor called." << std::endl;
	std::cout << "-- ClapTrap " << name << " stops working..." << std::endl;
}

ClapTrap::ClapTrap(std::string _name)
{
	std::cout << "+ClapTrap Name parameter constructor called." << std::endl;
	this->name = _name;
	hit_point = hit_point_max = clap_health_max;
	energy_point = energy_point_max = clap_energy_max;
	attack_damage = clap_default_damage;
}

void	ClapTrap::setName(std::string _name)
{
	this->name = _name;
}

void	ClapTrap::setHealth(unsigned int point)
{
	if (this->hit_point_max < this->hit_point + point)
		this->hit_point = this->hit_point_max;
	else
		this->hit_point = point;
}

void	ClapTrap::setEnergy(unsigned int point)
{
	if (this->energy_point_max < this->energy_point + point)
		this->energy_point = this->energy_point_max;
	else
		this->energy_point = point;
}

void	ClapTrap::setDamage(unsigned int point)
{
	this->attack_damage = point;
}

std::string	ClapTrap::getName(void) const
{
	return name;
}

int	ClapTrap::getHealth(void) const
{
	return hit_point;
}

int	ClapTrap::getEnergy(void) const
{
	return energy_point;
}

int	ClapTrap::getDamage(void) const
{
	return attack_damage;
}

bool	ClapTrap::checkEnergy(void)
{
	if (this->energy_point)
		return false;
	std::cout << "ClapTrap " << this->name << " doesn't have enough energy." << std::endl;
	return true;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->checkEnergy() || !this->hit_point)
		return ;
	this->energy_point--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing ";
	std::cout << this->attack_damage << " point of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " takes " << amount << " point of damage!" << std::endl;
	if (hit_point && hit_point <= amount)
	{
		hit_point = 0;
		return ;
	}
	hit_point -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->checkEnergy() || !this->hit_point)
		return ;
	this->energy_point--;
	std::cout << "ClapTrap " << this->name << " be repaired " << amount << " point!" << std::endl;
	if (this->hit_point + amount > this->hit_point_max)
		this->hit_point = this->hit_point_max;
	else
		this->hit_point += amount;
}

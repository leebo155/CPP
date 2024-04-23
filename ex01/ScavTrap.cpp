/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:58:53 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/06 13:37:38 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "+ScavTrap Default constructor called." << std::endl;
	this->name = "Keeper";
	this->hit_point = 100;
	this->energy_point = 50;
	this->attack_damage = 20;
	this->gateStatus = 0;
	this->hit_point_max = 100;
	this->energy_point_max = 50;
}

ScavTrap::ScavTrap(const ScavTrap &target): ClapTrap(target)
{
	std::cout << "+ScavTrap Copy constructor called." << std::endl;
	*this = target;
}

ScavTrap &ScavTrap::operator= (const ScavTrap &target)
{
	std::cout << "+ScavTrap Copy assignment constructor called." << std::endl;
	if (this != &target)
	{
		this->name = target.getName();
		this->hit_point = target.getHealth();
		this->energy_point = target.getEnergy();
		this->attack_damage = target.getDamage();
		this->gateStatus = target.getGate();
		this->hit_point_max = 100;
		this->energy_point_max = 50;
	}
	return *this;
}

ScavTrap::ScavTrap(std::string _name)
{
	std::cout << "+ScavTrap Name parameter constructor called." << std::endl;
	this->name = _name;
	this->hit_point = 100;
	this->energy_point = 50;
	this->attack_damage = 20;
	this->gateStatus = 0;
	this->hit_point_max = 100;
	this->energy_point_max = 50;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "-ScavTrap Destructor called." << std::endl;
	std::cout << "-- ScavTrap " << name << " stops working..." << std::endl;
}

bool	ScavTrap::getGate(void) const
{
	return this->gateStatus;
}

void	ScavTrap::setGate(bool status)
{
	if (this->checkEnergy() || !this->hit_point)
		return ;
	if (this->gateStatus == status)
		return ;
	this->energy_point--;
	if (status)
		std::cout << "The gate closes." << std::endl;
	else
		std::cout << "The gate opens." << std::endl;
	this->gateStatus = status;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->checkEnergy() || !this->hit_point)
		return ;
	this->energy_point--;
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing ";
	std::cout << this->attack_damage << " point of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->checkEnergy() || !this->hit_point)
		return ;
	this->energy_point--;
	if (this->gateStatus)
		std::cout << "=ScavTrap "<< name << "is guarding the door." << std::endl;
	else
		std::cout << "=ScavTrap" << name << " is not keeping the door." << std::endl;
}


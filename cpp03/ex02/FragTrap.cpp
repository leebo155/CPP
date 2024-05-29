/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:32:54 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/06 13:42:21 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "+FragTrap Default constructor called." << std::endl;
	this->name = "Somebody";
	this->hit_point_max = 100;
	this->energy_point_max = 100;
	this->hit_point = this->hit_point_max;
	this->energy_point = this->energy_point_max;
	this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &target): ClapTrap(target)
{
	std::cout << "+FragTrap Copy constructor called." << std::endl;
	*this = target;	
}

FragTrap &FragTrap::operator= (const FragTrap &target)
{
	std::cout << "+FragTrap Copy assignment constructor called." << std::endl;
	if (this != &target)
	{
		this->name = target.getName();
		this->hit_point_max = 100;
		this->energy_point_max = 100;
		this->hit_point = target.getHealth();
		this->energy_point = target.getEnergy();
		this->attack_damage = 30;
	}
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "-FragTrap Destructor called." << std::endl;
	std::cout << "-- FragTrap " << name << " stops working..." << std::endl;
}

FragTrap::FragTrap(std::string _name)
{
	std::cout << "+FragTrap Name parameter constructor called." << std::endl;
	this->name = _name;
	this->hit_point_max = 100;
	this->energy_point_max = 100;
	this->hit_point = this->hit_point_max;
	this->energy_point = this->energy_point_max;
	this->attack_damage = 30;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->checkEnergy() || !this->hit_point)
		return ;
	this->energy_point--;

	std::string response;

	std::cout << "Hello! Do you want to give me a high five? (Y or N)" << std::endl;
	std::cout << ">>";
	std::cin >> response;
	if (std::toupper(response[0] == 0))
	{
		std::cout << "FragTrap slowly lowers its hand..." << std::endl;
		return ;
	}
	if (std::toupper(response[0]) == 'Y' && response[1] == 0)
		std::cout << "Clap! Nice highfives!" << std::endl;
	else if (std::toupper(response[0]) == 'N' && response[1] == 0)
		std::cout << "Well... Let's do it next time!" << std::endl;
	else
		std::cout << "FragTrap doesn't seem to understand." << std::endl;
}

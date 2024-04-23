/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:09:45 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/23 17:24:07 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string _name)
{
	std::cout << "+ Character name constructor called." << std::endl;
	this->name = _name;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	this->wastes = NULL;
}

Character::Character(void)
{
	std::cout << "+ Character default constructor called." << std::endl;
	this->name = "John Doe";
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	this->wastes = NULL;
}

Character::Character(const Character &target)
{
	std::cout << "+ Character copy constructor called." << std::endl;
	this->name = "John Doe";
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	this->wastes = NULL;
	*this = target;
}

Character &Character::operator= (const Character &target)
{
	std::cout << "+ Character copy assignment constructor called." << std::endl;
	if(this != &target)
	{
		this->name = target.name;
		// Delete inventory Materias
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
			{
				delete(this->inventory[i]);
				this->inventory[i] = NULL;
			}
		}
		// Delete wastes Materias
		if (this->wastes)
		{
			delete(this->wastes);
			this->wastes = NULL;
		}
		// Add inventory Materias
		for (int i = 0; i < 4; i++)
		{
			if (target.inventory[i])
				this->inventory[i] = target.inventory[i]->clone();
		}
		// Add wastes Materias
		if (target.wastes)
		{
			this->wastes = target.wastes->clone();
			*(this->wastes) = *(target.wastes);
		}
	}
	return *this;
}

Character::~Character(void)
{
	std::cout << "- Character destructor called." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete(this->inventory[i]);
			this->inventory[i] = NULL;
		}
	}
	if (this->wastes)
		delete(this->wastes);
}

std::string const &Character::getName(void) const
{
	return this->name;
}

void	Character::equip(AMateria* m)
{
	if (m)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i] == NULL)
			{
				this->inventory[i] = m;
				return ;
			}
		}
		std::cout << "** Cannot equip, Inventory is full. **" << std::endl;
	}
}

void	Character::unequip(int idx)
{
	if ((0 <= idx && idx < 4) && this->inventory[idx])
	{
		if (this->wastes)
			this->wastes->addNext(this->inventory[idx]);
		else
			this->wastes = this->inventory[idx];
		this->inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if ((0 <= idx && idx < 4) && this->inventory[idx])
		this->inventory[idx]->use(target);
}

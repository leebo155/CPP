/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:50:58 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/23 14:58:22 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "+ MateriaSource default constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &target)
{
	std::cout << "+ MateriaSource copy constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	*this = target;
}

MateriaSource &MateriaSource::operator= (const MateriaSource &target)
{
	std::cout << "+ MateriaSource copy assignmnet constructor called." << std::endl;
	if (this != &target)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
			{
				delete(this->inventory[i]);
				this->inventory[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (target.inventory[i])
				this->inventory[i] = target.inventory[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "- MateriaSource destructor called." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete(this->inventory[i]);
			this->inventory[i] = NULL;
		}
	}
}

void	MateriaSource::learnMateria(AMateria *type)
{
	if (type)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i] == NULL)
			{
				this->inventory[i] = type;
				return ;
			}
		}
		std::cout << "** Cannot learn new Materia, slot is full. **" << std::endl;
		delete(type);
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0;i < 4; i++)
	{
		if (this->inventory[i] && this->inventory[i]->getType() == type)
			return this->inventory[i]->clone();
	}
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:16:59 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/24 12:10:22 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void)
{
	std::cout << "+ Cure default constructor called." << std::endl;
	this->type = "cure";
	this->next = NULL;
}

Cure::Cure(const Cure &target): AMateria(target)
{
	std::cout << "+ Cure copy constructor called." << std::endl;
	this->type = "cure";
	this->next = NULL;
	*this = target;
}

Cure	&Cure::operator= (const Cure &target)
{
	std::cout << "+ Cure copy assignment constructor called." << std::endl;
	if (this != &target && this->type == target.type)
	{
		if (this->next)
			delete(this->next);
		if (target.next)
		{
			this->next = target.next->clone();
			*(this->next) = *(target.next);
		}
	}
	return *this;
}

Cure::~Cure(void)
{
	std::cout << "- Cure destructor called." << std::endl;
}

AMateria	*Cure::clone(void) const
{
	return new Cure();
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

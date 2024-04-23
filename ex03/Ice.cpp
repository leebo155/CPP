/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:58:09 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/24 12:12:07 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void)
{
	std::cout << "+ Ice default constructor called." << std::endl;
	this->type = "ice";
	this->next = NULL;
}

Ice::Ice(const Ice &target): AMateria(target)
{
	std::cout << "+ Ice copy constructor called." << std::endl;
	this->type = "ice";
	this->next = NULL;
	*this = target;
}

Ice	&Ice::operator= (const Ice &target)
{
	std::cout << "+ Ice copy assignment constructor called." << std::endl;
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

Ice::~Ice(void)
{
	std::cout << "- Ice destructor called." << std::endl;
}

AMateria	*Ice::clone(void) const
{
	return new Ice();
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

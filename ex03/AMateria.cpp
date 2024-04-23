/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:37:14 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/24 12:07:12 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	std::cout << "+ AMateria type constructor called." << std::endl;
	this->type = type;
	this->next = NULL;
}

AMateria::AMateria(void)
{
	std::cout << "+ AMateria defualt constructor called." << std::endl;
	this->type = "none";
	this->next = NULL;
}

AMateria::AMateria(const AMateria &target)
{
	std::cout << "+ AMateria copy constructor called." << std::endl;
	this->type = "none";
	this->next = NULL;
	*this = target;
}

AMateria	&AMateria::operator= (const AMateria &target)
{
	std::cout << "+ AMateria copy assignment constructor called." << std::endl;
	if (this != &target && this->type == target.type)
	{
		AMateria	*tail = this->next;
		AMateria	*tmp;
		this->next = NULL;
		
		// Delete Next Materias
		while (tail)
		{
			tmp = tail;
			tail = tail->next;
			delete(tmp);
		}
		// Add Next Materias
		tmp = target.next;
		while (tmp)
		{
			this->addNext(tmp->clone());
			tmp = tmp->next;
		}
	}
	return *this;
}

AMateria::~AMateria(void)
{
	std::cout << "- AMateria destructor called." << std::endl;
	if (this->next)
		delete(this->next);
}

std::string const	&AMateria::getType(void) const
{
	return this->type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* noting happen " << target.getName() << " feels awkward *" << std::endl;
}

void	AMateria::addNext(AMateria *m)
{
	AMateria	*tail = this;
	
	while (tail->next)
		tail = tail->next;
	tail->next = m;
}

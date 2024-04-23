/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:59:20 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/24 11:45:57 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "+ WrongAnimal default constructor called." << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &target)
{
	std::cout << "+ WrongAnimal copy constructor called." << std::endl;
	this->type = "WrongAnimal";
	*this = target;
}

WrongAnimal &WrongAnimal::operator= (const WrongAnimal &target)
{
	std::cout << "+ WrongAnimal copy assignment constructor called." << std::endl;
	if (this != &target)
		this->type = target.getType();	
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "- WrongAnimal destructor called." << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return this->type;
}

void	WrongAnimal::setType(std::string _type)
{
	this->type = _type;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Gunga Ginga Gong Go Gunga Ginga" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:59:20 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/24 11:40:59 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "+ Animal default constructor called." << std::endl;
	this->type = "Animal";
}

Animal::Animal(const Animal &target)
{
	std::cout << "+ Animal copy constructor called." << std::endl;
	this->type = "Animal";
	*this = target;
}

Animal &Animal::operator= (const Animal &target)
{
	std::cout << "+ Animal copy assignment constructor called." << std::endl;
	if (this != &target)
		this->type = target.getType();	
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "- Animal destructor called." << std::endl;
}

std::string Animal::getType(void) const
{
	return this->type;
}

void	Animal::makeSound(void) const
{
	std::cout << ".. ..... .... ... .. .... .." << std::endl;
}

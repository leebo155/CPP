/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:17:49 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/24 11:41:19 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "+ Dog default constructor called." << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &target): Animal(target)
{
	std::cout << "+ Dog copy constructor called." << std::endl;
	this->type = "Dog";
	*this = target;
}

Dog	&Dog::operator= (const Dog &target)
{
	std::cout << "+ Dog copy assignment constructor called." << std::endl;
	if (this != &target)
		this->type = target.getType();
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "- Dog destructor called." << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof-woof! Ruff-ruf! Bark-bark!" << std::endl;
}

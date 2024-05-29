/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:17:49 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/24 11:22:31 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "+ Dog default constructor called." << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &target): Animal(target)
{
	std::cout << "+ Dog copy constructor called." << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
	*this = target;
}

Dog	&Dog::operator= (const Dog &target)
{
	std::cout << "+ Dog copy assignment constructor called." << std::endl;
	if (this != &target)
	{
		this->type = target.getType();
		*(this->brain) = target.getBrain();
	}
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "- Dog destructor called." << std::endl;
	delete(this->brain);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof-woof! Ruff-ruf! Bark-bark!" << std::endl;
}

Brain	&Dog::getBrain(void) const
{
	return *(this->brain);
}

void	Dog::setBrain(const Brain &target) const
{
	*(this->brain) = target;
}

void	Dog::saveIdea(int index, std::string idea) const
{
	this->brain->setIdeas(index, idea);
}

std::string	Dog::loadIdea(int index) const
{
	return this->brain->getIdeas(index);
}

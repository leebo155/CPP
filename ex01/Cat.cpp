/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:27:33 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/24 11:22:13 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "+ Cat default constructor called." << std::endl;	
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &target): Animal(target)
{
	std::cout << "+ Cat copy constructor called." << std::endl;	
	this->type = "Cat";
	this->brain = new Brain();
	*this = target;
}

Cat &Cat::operator= (const Cat &target)
{
	std::cout << "+ Cat copy assignment constructor called." << std::endl;	
	if(this != &target)
	{
		this->type = target.getType();
		*(this->brain) = target.getBrain();
	}
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "- Cat destructor called." << std::endl;	
	delete(this->brain);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow~ meooow~ meeoow!" << std::endl;
}

Brain	&Cat::getBrain(void) const
{
	return *(this->brain);
}

void	Cat::setBrain(const Brain &target) const
{
	*(this->brain) = target;
}

void	Cat::saveIdea(int index, std::string idea) const
{
	this->brain->setIdeas(index, idea);
}

std::string Cat::loadIdea(int index) const
{
	return this->brain->getIdeas(index);
}	

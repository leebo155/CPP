/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:46:47 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/24 11:49:32 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "+ WrongCat default constructor called." << std::endl;	
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &target): WrongAnimal(target)
{
	std::cout << "+ WrongCat copy constructor called." << std::endl;	
	this->type = "WrongCat";
	*this = target;
}

WrongCat &WrongCat::operator= (const WrongCat &target)
{
	std::cout << "+ WrongCat copy assignment constructor called." << std::endl;	
	if(this != &target)
		this->type = target.getType();
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "- WrongCat destructor called." << std::endl;	
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Roar~ roar! Roar~ roar!! Roar!" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:19:50 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/24 11:21:18 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "+ Brain default constructor called." << std::endl;
	for (int i = 0;i < 100;i++)
		this->ideas[i] = "empty";
}

Brain::Brain(const Brain &target)
{
	std::cout << "+ Brain copy constructor called." << std::endl;
	for (int i = 0;i < 100;i++)
		this->ideas[i] = "empty";
	*this = target;
}

Brain &Brain::operator= (const Brain &target)
{
	std::cout << "+ Brain copy assignment constructor called." << std::endl;
	if (this != &target)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = target.getIdeas(i);
	}
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "- Brain destructor called." << std::endl;
}

std::string	Brain::getIdeas(int index) const
{
	if (0 <= index && index < 100)
		return ideas[index];
	return "";
}

void	Brain::setIdeas(int index, std::string idea)
{
	if (0 <= index && index < 100)
		ideas[index] = idea;
}

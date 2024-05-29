/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:56:40 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/24 19:02:00 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char *Intern::DosentExistException::what(void) const throw()
{
	return "Can't find Form";
}

Intern::Intern(void)
{
}

Intern::Intern(const Intern &target)
{
	(void)target;
}

Intern	&Intern::operator=(const Intern &target)
{
	(void)target;
	return *this;
}

Intern::~Intern(void)
{
}

AForm	*Intern::makeForm(const std::string form, const std::string target) const
	throw(std::exception)
{
	std::string	forms[3] = {"shrubbery creation",
							"robotomy request",
							"presidential pardon"};
	int	index = 0;

	while (index < 3 && forms[index] != form)
		index++;
	switch (index)
	{
		case 0:
			return new ShrubberyCreationForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);
		default:
			throw Intern::DosentExistException();
	}
	return (NULL);
}

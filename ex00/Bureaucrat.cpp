/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:09:13 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/23 18:08:31 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade too high exception";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade too low exception";
}

Bureaucrat::Bureaucrat(void): name("John Doe")
{
	grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat &target): name("John Doe")
{
	grade = 150;
	*this = target;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &target)
{
	std::string *tmpName = const_cast<std::string *>(&this->name);

	if (this != &target)
	{
		*tmpName = target.name;
		this->grade = target.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(const std::string _name, const int _grade) throw(std::exception)
: name(_name)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	grade = _grade;
}

Bureaucrat::Bureaucrat(const std::string _name): name(_name)
{
	grade = 150;
}

const std::string	Bureaucrat::getName(void) const
{
	return name;
}

int	Bureaucrat::getGrade(void) const
{
	return grade;
}

void	Bureaucrat::increaseGrade(void) throw(std::exception)

{
	if (grade == 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void	Bureaucrat::decreaseGrade(void) throw(std::exception)
{
	if (grade == 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &target)
{
	std::cout << target.getName() << ", bureaucrat grade " << target.getGrade() << ".";
	return os;
}

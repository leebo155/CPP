/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:09:13 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/24 16:34:36 by bohlee           ###   ########.fr       */
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
	grade = GRADE_LOWEST;
}

Bureaucrat::Bureaucrat(const Bureaucrat &target): name("John Doe")
{
	grade = GRADE_LOWEST;
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

Bureaucrat::Bureaucrat(const std::string _name, int _grade) throw(std::exception)
: name(_name)
{
	if (_grade < GRADE_HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > GRADE_LOWEST)
		throw Bureaucrat::GradeTooLowException();
	grade = _grade;
}

Bureaucrat::Bureaucrat(const std::string _name): name(_name)
{
	grade = GRADE_LOWEST;
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
	if (grade == GRADE_HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void	Bureaucrat::decreaseGrade(void) throw(std::exception)
{
	if (grade == GRADE_LOWEST)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

void	Bureaucrat::signForm(AForm &target)
{
	try
	{
		target.beSigned(*this);
		std::cout << name << " signed " << target.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << name << " couldn't sign " << target.getName()
			<< " because " << e.what() << "." << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << name << " couldn't execute " << form.getName()
			<< " because " << e.what() << "." << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &target)
{
	std::cout << target.getName() << ", bureaucrat grade " << target.getGrade() << ".";
	return os;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:06:59 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/23 18:07:13 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char *Form::GradeTooHighException::what(void) const throw()
{
	return "Grade too high";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return "Grade too low";
}

Form::Form(void): name("default"), signGrade(150), execGrade(150)
{
	sign = false;
}

Form::Form(const Form &target): name("default"), signGrade(150), execGrade(150)
{
	sign = false;
	*this = target;
}

Form	&Form::operator=(const Form &target)
{
	std::string *tmpName = const_cast<std::string *>(&this->name);
	int			*tmpSignGrade = const_cast<int *>(&this->signGrade);
	int			*tmpExecGrade = const_cast<int *>(&this->execGrade);

	if (this != &target)
	{
		*tmpName = target.name;
		this->sign = target.sign;
		*tmpSignGrade = target.signGrade;
		*tmpExecGrade = target.execGrade;
	}
	return *this;
}

Form::~Form(void)
{
}

Form::Form(const std::string _name, const int _signGrade, const int _execGrade)
	throw(std::exception)
: name(_name), signGrade(_signGrade), execGrade(_execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	sign = false;
}

const std::string	Form::getName(void) const
{
	return name;
}

bool				Form::getSign(void) const
{
	return sign;
}

int					Form::getReqSignGrade(void) const
{
	return signGrade;
}

int					Form::getReqExecGrade(void) const
{
	return execGrade;
}

void				Form::beSigned(Bureaucrat &target)
	throw(std::exception)
{
	if (target.getGrade() > signGrade)
		throw Form::GradeTooLowException();
	sign = true;
}

std::ostream	&operator<<(std::ostream &os, const Form &target)
{
	os << target.getName() << ", Form required grade for sign is "
		<< target.getReqSignGrade() << ", execution is "
		<< target.getReqExecGrade() << " and this Form is ";
	if (target.getSign())
		os << "signed.";
	else
		os << "not signed.";
	return os;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:07:40 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/24 16:26:18 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return "Grade too low";
}

const char *AForm::IsNotSignedException::what(void) const throw()
{
	return "Form is not signed";
}

AForm::AForm(void): name("default"), signGrade(150), execGrade(150)
{
	sign = false;
}

AForm::AForm(const AForm &target): name("default"), signGrade(150), execGrade(150)
{
	sign = false;
	*this = target;
}

AForm	&AForm::operator=(const AForm &target)
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

AForm::~AForm(void)
{
}

AForm::AForm(const std::string _name, const int _signGrade, const int _execGrade)
	throw(std::exception)
: name(_name), signGrade(_signGrade), execGrade(_execGrade)
{
	if (signGrade < GRADE_HIGHEST || execGrade < GRADE_HIGHEST)
		throw AForm::GradeTooHighException();
	else if (signGrade > GRADE_LOWEST || execGrade > GRADE_LOWEST)
		throw AForm::GradeTooLowException();
	sign = false;
}

const std::string	AForm::getName(void) const
{
	return name;
}

bool	AForm::getSign(void) const
{
	return sign;
}

int	AForm::getReqSignGrade(void) const
{
	return signGrade;
}

int	AForm::getReqExecGrade(void) const
{
	return execGrade;
}

void	AForm::beSigned(Bureaucrat &target)
	throw(std::exception)
{
	if (target.getGrade() > signGrade)
		throw AForm::GradeTooLowException();
	sign = true;
}

void	AForm::setName(const std::string _name)
{
	std::string *tmpName = const_cast<std::string *>(&this->name);

	*tmpName = _name;
}

void	AForm::setSign(const bool _sign)
{
	sign = _sign;
}

void	AForm::setReqSignGrade(const int _signGrade) throw(std::exception)
{
	if (_signGrade < GRADE_HIGHEST)
		throw AForm::GradeTooHighException();
	else if (GRADE_LOWEST < _signGrade)
		throw AForm::GradeTooLowException();

	int			*tmpSignGrade = const_cast<int *>(&this->signGrade);

	*tmpSignGrade = _signGrade;
}

void	AForm::setReqExecGrade(const int _execGrade) throw(std::exception)
{
	if (_execGrade < GRADE_HIGHEST)
		throw AForm::GradeTooHighException();
	else if (GRADE_LOWEST < _execGrade)
		throw AForm::GradeTooLowException();

	int			*tmpExecGrade = const_cast<int *>(&this->execGrade);

	*tmpExecGrade = _execGrade;
}

std::ostream	&operator<<(std::ostream &os, const AForm &target)
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

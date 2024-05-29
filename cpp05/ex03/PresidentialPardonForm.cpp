/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:13:37 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/24 16:43:55 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
{
	target = "default";
	this->setName("PresidentialPardonForm");
	this->setSign(false);
	try
	{
		this->setReqSignGrade(25);
		this->setReqExecGrade(5);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		std::cerr << "Grade Range: " << GRADE_HIGHEST << " ~ " << GRADE_LOWEST;
		std::cerr << std::endl;
		this->setReqSignGrade(GRADE_LOWEST);
		this->setReqExecGrade(GRADE_LOWEST);
	}
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form)
: AForm(form)
{
	target = "default";
	this->setName("PresidentialPardonForm");
	this->setSign(false);
	try
	{
		this->setReqSignGrade(25);
		this->setReqExecGrade(5);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		std::cerr << "Grade Range: " << GRADE_HIGHEST << " ~ " << GRADE_LOWEST;
		std::cerr << std::endl;
		this->setReqSignGrade(GRADE_LOWEST);
		this->setReqExecGrade(GRADE_LOWEST);
	}
	*this = form;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
	if (this != &form)
	{
		this->target = form.target;
		this->setSign(form.getSign());
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string _target)
{
	target = _target;
	this->setName("PresidentialPardonForm");
	this->setSign(false);
	try
	{
		this->setReqSignGrade(25);
		this->setReqExecGrade(5);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		std::cerr << "Grade Range: " << GRADE_HIGHEST << " ~ " << GRADE_LOWEST;
		std::cerr << std::endl;
		this->setReqSignGrade(GRADE_LOWEST);
		this->setReqExecGrade(GRADE_LOWEST);
	}
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
	throw(std::exception)
{
	if (!this->getSign())
		throw AForm::IsNotSignedException();
	else if (executor.getGrade() > this->getReqExecGrade())
		throw AForm::GradeTooLowException();

	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

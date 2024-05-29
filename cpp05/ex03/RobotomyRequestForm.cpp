/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:42:30 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/24 17:33:10 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
{
	target = "default";
	this->setName("RobotomyRequestForm");
	this->setSign(false);
	try
	{
		this->setReqSignGrade(72);
		this->setReqExecGrade(45);
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

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form)
: AForm(form)
{
	target = "default";
	this->setName("RobotomyRequestForm");
	this->setSign(false);
	try
	{
		this->setReqSignGrade(72);
		this->setReqExecGrade(45);
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

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
	if (this != &form)
	{
		this->target = form.target;
		this->setSign(form.getSign());
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string _target)
{
	target = _target;
	this->setName("RobotomyRequestForm");
	this->setSign(false);
	try
	{
		this->setReqSignGrade(72);
		this->setReqExecGrade(45);
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

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
	throw(std::exception)
{
	if (!this->getSign())
		throw AForm::IsNotSignedException();
	else if (executor.getGrade() > this->getReqExecGrade())
		throw AForm::GradeTooLowException();
	std::cout << "Drrrrrr.. drr.. drrrr... drrr." << std::endl;
	std::srand(time(0));
	if (std::rand() % 2)
		std::cout << target << " has been successfully robotomized." << std::endl;
	else
		std::cout << target << " failed robotomized." << std::endl;

}

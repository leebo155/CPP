/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:18:01 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/24 16:41:58 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const char *ShrubberyCreationForm::IsNotOpenedException::what(void) const throw()
{
	return "File is not opend";
};

ShrubberyCreationForm::ShrubberyCreationForm(void)
{
	target = "default";
	this->setName("ShrubberyCreationForm");
	this->setSign(false);
	try
	{
		this->setReqSignGrade(145);
		this->setReqExecGrade(137);
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

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form)
: AForm(form)
{
	target = "default";
	this->setName("ShrubberyCreationForm");
	this->setSign(false);
	try
	{
		this->setReqSignGrade(145);
		this->setReqExecGrade(137);
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

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form)
{
	if (this != &form)
	{
		this->target = form.target;
		this->setSign(form.getSign());
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string _target)
{
	target = _target;
	this->setName("ShrubberyCreationForm");
	this->setSign(false);
	try
	{
		this->setReqSignGrade(145);
		this->setReqExecGrade(137);
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

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
	throw(std::exception)
{
	if (!this->getSign())
		throw AForm::IsNotSignedException();
	else if (executor.getGrade() > this->getReqExecGrade())
		throw AForm::GradeTooLowException();
	
	std::ofstream	file;
	std::string		fileName = target;

	file.open(fileName.append("_shrubbery"));
	if (!file.is_open())
		throw ShrubberyCreationForm::IsNotOpenedException();
	file << "                                                         ."
		<< "\n                                              .         ;"
		<< "\n                 .              .              ;%     ;;"
		<< "\n                  ,           ,                :;%  %;"
		<< "\n                   :         ;                   :;%;'     .,"
		<< "\n           ,.        %;     %;            ;        %;'    ,;"
		<< "\n            ;       ;%;  %%;        ,     %;    ;%;    ,%'"
		<< "\n             %;       %;%;      ,  ;       %;  ;%;   ,%;'"
		<< "\n              ;%;      %;        ;%;        % ;%;  ,%;'"
		<< "\n               `%;.     ;%;     %;'         `;%%;.%;'"
		<< "\n                `:;%.    ;%%. %@;        %; ;@%;%'"
		<< "\n                   `:%;.  :;bd%;          %;@%;'"
		<< "\n                     `@%:.  :;%.         ;@@%;'"
		<< "\n                       `@%.  `;@%.      ;@@%;"
		<< "\n                         `@%%. `@%%    ;@@%;"
		<< "\n                           ;@%. :@%%  %@@%;"
		<< "\n                             %@bd%%%bd%%:;"
		<< "\n                               #@%%%%%:;;"
		<< "\n                               %@@%%%::;"
		<< "\n                               %@@@%(o);  . '"
		<< "\n                               %@@@o%;:(.,'"
		<< "\n                           `.. %@@@o%::;"        
		<< "\n                              `)@@@o%::;"        
		<< "\n                               %@@(o)::;"       
		<< "\n                              .%@@@@%::;"       
		<< "\n                              ;%@@@@%::;."        
		<< "\n                             ;%@@@@%%:;;;."
		<< "\n                         ...;%@@@@@%%:;;;;,.."
		<< std::endl;
	file.close();
}

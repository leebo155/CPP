/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:32:59 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/24 17:47:54 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	AForm *test1 = new ShrubberyCreationForm("Test1");
	AForm *test2 = new RobotomyRequestForm("Test2");
	AForm *test3 = new PresidentialPardonForm("Test3");

	Bureaucrat kim("Kim", 1);
	Bureaucrat lee("Lee", 150);

	std::cout << ">>Test 1: Form.execute() not signed Forms" << std::endl;
	try
	{
		test1->execute(lee);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		test2->execute(lee);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		test3->execute(lee);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n>>Test 2: Form.execute() signed Forms but low grade Bureaucrat" << std::endl;

	kim.signForm(*test1);
	kim.signForm(*test2);
	kim.signForm(*test3);
	
	try
	{
		test1->execute(lee);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		test2->execute(lee);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		test3->execute(lee);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n>>Test 3: Form.execute() signed Forms high grade Bureaucrat" << std::endl;
	
	try
	{
		test1->execute(kim);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		test2->execute(kim);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		test3->execute(kim);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete test1;
	delete test2;
	delete test3;

	AForm *test4 = new ShrubberyCreationForm("Test4");
	AForm *test5 = new RobotomyRequestForm("Test5");
	AForm *test6 = new PresidentialPardonForm("Test6");

	std::cout << "\n>>Test 4: Bureaucrat.executeForm() not signed Forms" << std::endl;
	kim.executeForm(*test4);
	kim.executeForm(*test5);
	kim.executeForm(*test6);

	std::cout << "\n>>Test 5: Low grade Bureaucrat.executeForm() signed Forms" << std::endl;
	kim.signForm(*test4);
	kim.signForm(*test5);
	kim.signForm(*test6);

	lee.executeForm(*test4);
	lee.executeForm(*test5);
	lee.executeForm(*test6);

	std::cout << "\n>>Test 6: High grade Bureaucrat.executeForm() signed Forms" << std::endl;
	kim.executeForm(*test4);
	kim.executeForm(*test5);
	kim.executeForm(*test6);

	delete test4;
	delete test5;
	delete test6;

	return 0;
}


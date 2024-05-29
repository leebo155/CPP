/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:32:59 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/23 18:03:01 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	/* ex00
	Bureaucrat kim("Kim", 1);
	Bureaucrat *lee = new Bureaucrat("Lee", 150);
	try // GradeTooHighException
	{
		Bureaucrat park("Park", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try // GradeTooLowException
	{
		Bureaucrat choi("Choi", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << kim << std::endl;
	std::cout << *lee << std::endl;

	try // GradeTooHighException
	{
		kim.increaseGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try // GradeTooLowException
	{
		lee->decreaseGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	kim.decreaseGrade();
	std::cout << kim << std::endl;
	kim.increaseGrade();
	std::cout << kim << std::endl;

	lee->increaseGrade();
	std::cout << *lee << std::endl;
	lee->decreaseGrade();
	std::cout << *lee << std::endl;

	delete lee;
	*/

	Form word("Word", 150, 35);
	Form excel("Excel", 1, 12);
	try
	{
		Form test1("Test 1", 151, 130);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form test2("Test 2", 0, 130);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form test3("Test 3", 120, 151);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form test4("Test 4", 120, 0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n" << std::endl;
	}
	
	Bureaucrat alice("Alice", 150);
	Bureaucrat bob("Bob", 1);

	std::cout << word << std::endl;
	std::cout << excel << std::endl;
	std::cout << alice << std::endl;
	std::cout << bob << "\n" << std::endl;

	try
	{
		excel.beSigned(alice);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n" << std::endl;
	}

	alice.signForm(word);
	alice.signForm(excel);
	
	bob.signForm(word);
	bob.signForm(excel);

	std::cout << "\n" << word << std::endl;
	std::cout << excel << std::endl;

	return 0;
}


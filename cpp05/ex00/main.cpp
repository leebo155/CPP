/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:32:59 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/23 14:46:27 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
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
	return 0;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:32:59 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/24 19:01:36 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat	kim("Kim", 1);
	Intern		intern;
	AForm		*rrf;

	std::cout << "Test 1: Shrubbery Creation Form" << std::endl;
	
	rrf = intern.makeForm("shrubbery creation", "Bender");
	std::cout << *rrf << std::endl;
	kim.signForm(*rrf);
	kim.executeForm(*rrf);

	delete rrf;
	
	std::cout << "\nTest 2: Robotomy Request Form" << std::endl;

	rrf = intern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;
	kim.signForm(*rrf);
	kim.executeForm(*rrf);

	delete rrf;
	
	std::cout << "\nTest 3: Presidential Pardon Form" << std::endl;

	rrf = intern.makeForm("presidential pardon", "Bender");
	std::cout << *rrf << std::endl;
	kim.signForm(*rrf);
	kim.executeForm(*rrf);

	delete rrf;

	std::cout << "\nTest 4: Unknown Form" << std::endl;
	
	try
	{
		rrf = intern.makeForm("unknown", "Bender");
		std::cout << *rrf << std::endl;
		kim.signForm(*rrf);
		kim.executeForm(*rrf);
	
		delete rrf;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}


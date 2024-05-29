/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:51:34 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/24 18:54:44 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		class DosentExistException: public std::exception
		{
			const char *what(void) const throw();
		};
		Intern(void);
		Intern(const Intern &target);
		Intern &operator=(const Intern &target);
		~Intern(void);

		AForm	*makeForm(const std::string form, const std::string target) const
			throw(std::exception);
};

#endif

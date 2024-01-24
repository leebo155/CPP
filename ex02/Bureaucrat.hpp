/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:48:48 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/24 16:23:21 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define GRADE_HIGHEST 1
# define GRADE_LOWEST 150

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;

	public:
		class GradeTooHighException: public std::exception
		{
			public:
				const char *what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char *what(void) const throw();
		};
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &target);
		Bureaucrat &operator=(const Bureaucrat &target);
		~Bureaucrat(void);

		Bureaucrat(std::string _name, int _grade) throw(std::exception);
		Bureaucrat(std::string _name);

		const std::string 	getName(void) const;
		int					getGrade(void) const;

		void				increaseGrade(void) throw(std::exception);
		void				decreaseGrade(void) throw(std::exception);

		void				signForm(AForm &target);
		void				executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &target);

#endif

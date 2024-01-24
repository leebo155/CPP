/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:48:48 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/23 18:08:04 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

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

		Bureaucrat(const std::string _name, const int _grade)
			throw(std::exception);
		Bureaucrat(const std::string _name);

		const std::string 	getName(void) const;
		int					getGrade(void) const;

		void				increaseGrade(void) throw(std::exception);
		void				decreaseGrade(void) throw(std::exception);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &target);

#endif

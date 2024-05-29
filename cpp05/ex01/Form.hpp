/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:33:34 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/23 18:06:49 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				sign;
		const int			signGrade;
		const int			execGrade;

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

		Form(void);
		Form(const Form &target);
		Form &operator=(const Form &target);
		~Form(void);

		Form(const std::string _name, const int _signGrade, const int _execGrade)
			throw(std::exception);

		const std::string	getName(void) const;
		bool				getSign(void) const;
		int					getReqSignGrade(void) const;
		int					getReqExecGrade(void) const;

		void				beSigned(Bureaucrat &target)
			throw(std::exception);
};

std::ostream	&operator<<(std::ostream &os, const Form &target);

#endif

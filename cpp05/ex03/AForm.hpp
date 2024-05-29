/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:03:32 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/24 16:34:52 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				sign;
		const int			signGrade;
		const int			execGrade;

	protected:
		void				setName(const std::string _name);
		void				setSign(const bool _sign);
		void				setReqSignGrade(const int _signGrade)
			throw(std::exception);
		void				setReqExecGrade(const int _execGrade)
			throw(std::exception);

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
		class IsNotSignedException: public std::exception
		{
			public:
				const char *what(void) const throw();
		};

		AForm(void);
		AForm(const AForm &target);
		AForm &operator=(const AForm &target);
		virtual ~AForm(void);

		AForm(const std::string _name, const int _signGrade, const int _execGrade)
			throw(std::exception);

		const std::string	getName(void) const;
		bool				getSign(void) const;
		int					getReqSignGrade(void) const;
		int					getReqExecGrade(void) const;

		void				beSigned(Bureaucrat &target)
			throw(std::exception);

		virtual void		execute(Bureaucrat const & executor) const
			throw(std::exception) = 0;
};

std::ostream	&operator<<(std::ostream &os, const AForm &target);

#endif

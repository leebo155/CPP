/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:36:51 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/24 16:35:07 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm: public AForm
{
	private:
		std::string	target;

	public:
		class IsNotOpenedException: public std::exception
		{
			public:
				const char *what(void) const throw();
		};
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &form);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &form);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string _target);

		void	execute(Bureaucrat const & executor) const throw(std::exception);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:27:45 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/24 16:42:38 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm: public AForm
{
	private:
		std::string	target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &form);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &form);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string _target);

		void	execute(Bureaucrat const & executor) const throw(std::exception);
};

#endif

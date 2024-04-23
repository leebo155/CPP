/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:28:24 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/06 13:42:33 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const FragTrap &target);
		FragTrap &operator= (const FragTrap &target);
		~FragTrap(void);

		FragTrap(std::string _name);
		
		void	highFivesGuys(void);
};

#endif

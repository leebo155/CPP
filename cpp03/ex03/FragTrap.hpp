/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:28:24 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/06 13:45:33 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	protected:
		static const unsigned int	frag_health_max = 100;
		static const unsigned int frag_energy_max = 100;
		static const unsigned int frag_default_damage = 30;

	public:
		FragTrap(void);
		FragTrap(const FragTrap &target);
		FragTrap &operator= (const FragTrap &target);
		~FragTrap(void);

		FragTrap(std::string _name);
		
		void	highFivesGuys(void);
};

#endif

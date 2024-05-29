/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:23:17 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/06 13:36:04 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
	private:
		std::string 	name;
		unsigned int	hit_point;
		unsigned int	energy_point;
		unsigned int	attack_damage;

		unsigned int	hit_point_max;
		unsigned int	energy_point_max;
		bool	checkEnergy(void);

	public:
		ClapTrap(void);
		ClapTrap(const ClapTrap &target);
		ClapTrap &operator= (const ClapTrap &target);
		~ClapTrap(void);

		ClapTrap(std::string _name);

		void	setName(std::string _name);
		void	setHealth(unsigned int point);
		void	setEnergy(unsigned int point);
		void	setDamage(unsigned int point);
		std::string	getName(void) const;
		int			getHealth(void) const;
		int			getEnergy(void) const;
		int			getDamage(void) const;
		
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif

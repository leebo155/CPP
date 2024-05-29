/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:23:17 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/06 13:43:16 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
	protected:
		std::string 	name;
		unsigned int	hit_point;
		unsigned int	energy_point;
		unsigned int	attack_damage;

		unsigned int	hit_point_max;
		unsigned int	energy_point_max;

		static const unsigned int	clap_health_max = 10;
		static const unsigned int	clap_energy_max = 10;
		static const unsigned int	clap_default_damage = 0;
		bool	checkEnergy(void);

	public:
		ClapTrap(void);
		ClapTrap(const ClapTrap &target);
		ClapTrap &operator= (const ClapTrap &target);
		virtual ~ClapTrap(void);

		ClapTrap(std::string _name);

		void	setName(std::string _name);
		void	setHealth(unsigned int point);
		void	setEnergy(unsigned int point);
		void	setDamage(unsigned int point);
		virtual std::string	getName(void) const;
		int			getHealth(void) const;
		int			getEnergy(void) const;
		int			getDamage(void) const;
		
		virtual void	attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
};

#endif

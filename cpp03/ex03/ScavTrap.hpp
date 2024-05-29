/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:47:34 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/06 13:44:39 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap: virtual public ClapTrap
{
	private:
		bool	gateStatus;

	protected:
		static const unsigned int	scav_health_max = 100;
		static const unsigned int	scav_energy_max = 50;
		static const unsigned int	scav_default_damage = 20;

	public:
		ScavTrap(void);
		ScavTrap(const ScavTrap &target);
		ScavTrap &operator= (const ScavTrap &target);
		~ScavTrap(void);

		ScavTrap(std::string _name);

		void	attack(const std::string& target);
		void	guardGate(void);
		bool	getGate(void) const;
		void	setGate(bool status);

};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:47:34 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/06 13:41:56 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap: public ClapTrap
{
	private:
		bool	gateStatus;

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

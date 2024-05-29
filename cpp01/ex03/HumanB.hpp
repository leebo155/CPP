/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:02:48 by bohlee            #+#    #+#             */
/*   Updated: 2023/11/11 15:29:09 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon*		weapon;
		
	public:
		HumanB(std::string name, Weapon &weapon);
		HumanB(std::string name);
		void	setWeapon(Weapon &weapon);
		void	attack(void) const;
};

#endif

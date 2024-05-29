/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:53:04 by bohlee            #+#    #+#             */
/*   Updated: 2023/11/09 17:07:42 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{
	private:
		std::string name;
		
	public:
		Zombie(void);
		Zombie(std::string str);
		~Zombie(void);
		void	setName(std::string str);
		void	announce(void);
};

Zombie*	zombieHorde(int N, std::string name);

#endif

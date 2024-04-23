/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:41:27 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/24 11:50:07 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &target);
		WrongAnimal &operator= (const WrongAnimal &target);
		~WrongAnimal(void);

		std::string 	getType(void) const;
		void			setType(std::string _type);
		void			makeSound(void) const;
};

#endif

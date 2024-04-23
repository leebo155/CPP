/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:15:32 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/07 20:18:19 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain *brain;

	public:
		Dog(void);
		Dog(const Dog &target);
		Dog &operator= (const Dog &target);
		~Dog(void);

		void	makeSound(void) const;

		Brain		&getBrain(void) const;
		void		setBrain(const Brain &target) const;
		void		saveIdea(int index, std::string idea) const;
		std::string	loadIdea(int index) const;
};

#endif

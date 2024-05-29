/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:24:31 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/07 20:18:03 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain *brain;

	public:
		Cat(void);
		Cat(const Cat &target);
		Cat &operator= (const Cat &target);
		~Cat(void);

		void	makeSound(void) const;

		Brain		&getBrain(void) const;
		void		setBrain(const Brain &target) const;
		void		saveIdea(int index, std::string idea) const;
		std::string	loadIdea(int index) const;
};

#endif

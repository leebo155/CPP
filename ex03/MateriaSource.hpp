/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:40:00 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/23 11:54:26 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria	*inventory[4];

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &target);
		MateriaSource &operator= (const MateriaSource &target);
		~MateriaSource(void);

		void	learnMateria(AMateria *type);
		AMateria *createMateria(std::string const &type);
};

#endif

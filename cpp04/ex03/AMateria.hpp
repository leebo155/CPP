/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:04:37 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/24 12:07:15 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string type;
		AMateria	*next;

	public:
		AMateria(std::string const & type);

		AMateria(void);
		AMateria(const AMateria &target);
		AMateria &operator= (const AMateria &target);
		virtual ~AMateria(void);

		std::string const & getType(void) const;

		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);

		void		addNext(AMateria *m);
};

#endif

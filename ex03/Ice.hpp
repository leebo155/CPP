/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:23:38 by bohlee            #+#    #+#             */
/*   Updated: 2023/12/08 16:16:36 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &target);
		Ice &operator= (const Ice &target);
		~Ice(void);

		AMateria	*clone(void) const;
		void		use(ICharacter &target);
};

#endif

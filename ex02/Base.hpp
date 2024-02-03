/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:07:37 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/03 13:49:45 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>

class Base
{
	public:
		virtual ~Base(void);

		Base	*generate(void);
		void	identify(Base* p);
		void	identify(Base& p); 
};

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

#endif

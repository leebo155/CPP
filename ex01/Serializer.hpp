/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:24:26 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/29 17:02:45 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

typedef struct	s_Data
{
	char	c;
	int		i;
	float	f;
	double	d;
} Data;

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer &target);
		Serializer &operator=(const Serializer &target);
		~Serializer(void);
		
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif

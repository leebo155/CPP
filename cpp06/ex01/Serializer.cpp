/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:45:25 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/29 17:03:04 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
}

Serializer::Serializer(const Serializer &target)
{
	static_cast<void>(target);
}

Serializer &Serializer::operator=(const Serializer &target)
{
	static_cast<void>(target);
	return *this;
}

Serializer::~Serializer(void)
{
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

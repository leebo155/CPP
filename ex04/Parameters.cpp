/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parameters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:42:48 by bohlee            #+#    #+#             */
/*   Updated: 2023/11/12 14:45:33 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parameters.hpp"

Parameters::Parameters(std::string filename, std::string s1, std::string s2)
{
	this->filename = filename;
	this->s1 = s1;
	this->s2 = s2;
}

std::string	Parameters::getFilename(void)
{
	return filename;
}

std::string	Parameters::getS1(void)
{
	return s1;
}

std::string	Parameters::getS2(void)
{
	return s2;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parameters.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:38:02 by bohlee            #+#    #+#             */
/*   Updated: 2023/11/12 14:47:18 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERS_HPP
# define PARAMETERS_HPP

#include <iostream>

class Parameters
{
	private:
		std::string filename;
		std::string	s1;
		std::string s2;

	public:
		Parameters(std::string filename, std::string s1, std::string s2);
		std::string	getFilename(void);
		std::string	getS1(void);
		std::string	getS2(void);
};

#endif

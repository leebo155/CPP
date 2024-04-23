/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:34:54 by bohlee            #+#    #+#             */
/*   Updated: 2023/11/12 14:53:25 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parameters.hpp"
#include <fstream>

int	main(int argc, char *argv[])
{
	if (argc - 1 != 3 
		|| static_cast<std::string>(argv[1]).empty()
		|| static_cast<std::string>(argv[2]).empty())
		return 1;

	Parameters	param(argv[1], argv[2], argv[3]);
	std::ifstream	input;
	std::ofstream	output;
	std::string	outputName = param.getFilename().append(".replace");
	std::string	content;
	
	input.open(argv[1]);
	output.open(outputName);
	if (!input.is_open() || !output.is_open())
		return 1;

	while (input.good())
		content.push_back(input.get());
	content.pop_back();
	input.close();

	size_t	index = content.find(param.getS1());
	while (index != std::string::npos)
	{
		content.erase(index, param.getS1().length());
		content.insert(index, param.getS2());
		index = content.find(param.getS1());
	}
	output << content;
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:44:33 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/27 14:57:33 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN &target) {(void)target; }

RPN	&RPN::operator=(const RPN &target) {(void)target; return *this; }

RPN::~RPN(void)
{
	while (!tokens.empty())
		tokens.pop();
}

void	RPN::fourOperator(const char oper) throw(std::exception)
{
	switch (tokens.size())
	{
		case 0:
			throw std::runtime_error("Error");
		case 1:
			throw std::runtime_error("Error");
	}
	double bnum  = tokens.top();
	tokens.pop();
	double fnum = tokens.top();
	tokens.pop();

	switch (oper)
	{
		case '*':
			tokens.push(fnum * bnum);
			break;
		case '+':
			tokens.push(fnum + bnum);
			break;
		case '-':
			tokens.push(fnum - bnum);
			break;
		case '/':
			switch (static_cast<int64_t>(bnum))
			{
				case 0:
					throw std::runtime_error("Error");
			}
			tokens.push(fnum / bnum);
			break;
	}
}

void	RPN::calculate(int argc, char **argv) throw(std::exception)
{
	for (int i = 1; i < argc; i++)
	{
		for (size_t j = 0; argv[i][j]; j++)
		{
			switch (argv[i][j])
			{
				case ' ':
					continue;
				case '\n':
					continue;
				case '\r':
					continue;
				case '\t':
					continue;
				case '\f':
					continue;
				case '\v':
					continue;
				case '*':
					this->fourOperator(argv[i][j]);
					break;
				case '+':
					this->fourOperator(argv[i][j]);
					break;
				case '-':
					this->fourOperator(argv[i][j]);
					break;
				case '/':
					this->fourOperator(argv[i][j]);
					break;
				case '0':
					tokens.push(argv[i][j] - '0');
					break;
				case '1':
					tokens.push(argv[i][j] - '0');
					break;
				case '2':
					tokens.push(argv[i][j] - '0');
					break;
				case '3':
					tokens.push(argv[i][j] - '0');
					break;
				case '4':
					tokens.push(argv[i][j] - '0');
					break;
				case '5':
					tokens.push(argv[i][j] - '0');
					break;
				case '6':
					tokens.push(argv[i][j] - '0');
					break;
				case '7':
					tokens.push(argv[i][j] - '0');
					break;
				case '8':
					tokens.push(argv[i][j] - '0');
					break;
				case '9':
					tokens.push(argv[i][j] - '0');
					break;
				default:
					throw std::runtime_error("Error");
			}
			switch (argv[i][j + 1])
			{
				case '\0':
					break;
				case ' ':
					break;
				case '\n':
					break;
				case '\r':
					break;
				case '\t':
					break;
				case '\f':
					break;
				case '\v':
					break;
				default:
					throw std::runtime_error("Error");
			}
		}
	}

	switch (tokens.size())
	{
		case 1:
			std::cout << tokens.top() << std::endl;
			tokens.pop();
			break;
		default:
			throw std::runtime_error("Error");
	}
}

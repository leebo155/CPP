/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:30:19 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/27 18:02:47 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stdint.h>
# include <stack>
# include <exception>

class RPN
{
	private:
		std::stack<double> tokens;
		
		void	fourOperator(char oper) throw(std::exception);

	public:
		RPN(void);
		RPN(const RPN &target);
		RPN &operator=(const RPN &target);
		~RPN(void);

		void	calculate(int argc, char **argv) throw(std::exception);
};

#endif

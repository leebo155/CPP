/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:41:12 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/22 16:51:48 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		MutantStack(void): std::stack<T>() {};
		MutantStack(const MutantStack &target): std::stack<T>(target) {};
		MutantStack &operator=(const MutantStack &target)
		{
			if (this != target)
			{
				std::stack<T> &st1 = *this;
				std::stack<T> &st2 = target;
				st1 = st2;
			}
			return *this;
		};
		virtual ~MutantStack(void) {};

		iterator				begin(void) { return this->c.begin(); };
		const_iterator			begin(void) const { return this->c.begin(); };
		iterator				end(void) { return this->c.end(); };
		const_iterator			end(void) const { return this->c.end(); };
		reverse_iterator		rbegin(void) { return this->c.rbegin(); };
		const_reverse_iterator	rbegin(void) const { return this->c.rbegin(); };
		reverse_iterator		rend(void) { return this->c.rend(); };
		const_reverse_iterator	rend(void) const { return this->c.rend(); };
		const_iterator			cbegin(void) const { return this->c.cbegin(); };
		const_iterator			cend(void) const { return this->c.cend(); };
		const_reverse_iterator	crbegin(void) const { return this->c.crbegin(); };
		const_reverse_iterator	crend(void) const { return this->c.crend(); };
};

#endif

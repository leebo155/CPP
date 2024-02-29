/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:55:39 by bohlee            #+#    #+#             */
/*   Updated: 2024/02/29 20:43:10 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <vector>
# include <list>
# include <exception>

class PmergeMe
{
	private:
		std::vector<uint64_t> vt;
		std::list<uint64_t> lt;

		template <typename T>
		void	splitPair(int size, T &t)
		{
			for (int i = 0; i + 1 < size; i += 2)
			{
				int a = i;
				int b = i + 1;
				if (t.at(a) < t.at(b))
				{
					T	tmp;
					tmp.insert(tmp.begin(), t.begin() + b, t.begin() + b + 1);
					t.erase(t.begin() + b);
					t.insert(t.begin() + a, tmp.begin(), tmp.end());
					tmp.clear();
					std::cout << "vector: ";
					for (typename T::iterator it = t.begin(); it != t.end(); it++)
						std::cout << *it << " ";
					std::cout << std::endl;
				}
			}
		};
		template <typename T>
		void	mergeRecur(int a, int b, int node_size, T &t)
		{
			int size = (b - a) / 2;
			if (b  - a + 1 < node_size )
				return ;
			else if (b - a + 1 == node_size * 2)
			{
				b = a + size + 1;
				if (t.at(a) < t.at(b))
				{
					T	tmp;
					tmp.insert(tmp.begin(), t.begin() + b, t.begin() + b + node_size);
					t.erase(t.begin() + b, t.begin() + b + node_size);
					std::cout << std::endl;
					t.insert(t.begin() + a, tmp.begin(), tmp.end());
					tmp.clear();
					std::cout << "vector: ";
					for (typename T::iterator it = t.begin(); it != t.end(); it++)
						std::cout << *it << " ";
					std::cout << std::endl;
				}
				return ;
			}

			this->mergeRecur(a, size, node_size, t);
			this->mergeRecur(a + size + 1, b, node_size, t);	
		};

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &target);
		PmergeMe &operator=(const PmergeMe &target);
		~PmergeMe(void);

		void	sort(int argc, char **argv) throw(std::exception);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:55:39 by bohlee            #+#    #+#             */
/*   Updated: 2024/03/04 17:07:19 by bohlee           ###   ########.fr       */
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

		int		jacobsthalNumber(int n);
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
		
		template <typename T>
		void	binarySearch(int end, int node_size, T &a, T &b)
		{
			int	middle;
			int	low = 0;
			int high = end;
			
			while (low < high)
			{
				middle = end / node_size / 2 * node_size;

				if (b.at(0) <  a.at(middle))
					high = middle - node_size;
				else
					low = middle + node_size;
			}
			return high;
		};

		template <typename T>
		void	insertMerge(int nodes, int node_size, T &t)
		{
			T	tmp;
			int	start, end, amount, selected, find;

			for (int i = 0; i < nodes / 2; i++)
			{
				start = i * node_size + node_size;
				end = start + node_size;
				tmp.insert(tmp.end(), t.begin() + start, t.begin() + end);
				t.erase(t.begin() + start, t.begin() + end);
			}
			amount = nodes / 2;
			if (nodes % 2)
			{
				tmp.insert(tmp.end(), t.begin() + start, t.begin() + end);
				t.erase(t.begin() + start, t.begin() + end);
				amount++;
			}
			t.insert(t.begin(), tmp.begin(), tmp.begin() + node_size);
			tmp.erase(tmp.begin(), tmp.begin() + node_size);

			selected = 1;
			start = node_size;
			end = 0;
			for (int i = 1; !tmp.empty(); i++)
			{
				for (int j = this->jacobsthalNumber(i); j > selected; j--)
				{
					if (j > amount)
						j = amount;
					end = start + node_size * j;
					find = this->binarySearch(end, node_size, t, tmp);
				}
			}
		};

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &target);
		PmergeMe &operator=(const PmergeMe &target);
		~PmergeMe(void);

		void	sort(int argc, char **argv) throw(std::exception);
};

#endif

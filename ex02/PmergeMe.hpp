/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:55:39 by bohlee            #+#    #+#             */
/*   Updated: 2024/03/06 14:23:35 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <vector>
# include <deque>
# include <list>
# include <exception>

class PmergeMe
{
	private:
		std::vector<uint64_t> vt;
		std::deque<uint64_t> dq;

		int		jacobsthalNumber(int n);
		template <typename T>
		int		splitPair(int node_size, int size, T &t)
		{
			int block = node_size * 2;
			int a, b;

			if (block > size)
				return node_size / 2;
			for (int i = 0; i + block <= size; i += block)
			{
				a = i;
				b = a + node_size;
				if (t.at(a) < t.at(b))
				{
					T	tmp;
					tmp.insert(tmp.begin(), t.begin() + b, t.begin() + b + node_size);
					t.erase(t.begin() + b, t.begin() + b + node_size);
					t.insert(t.begin() + a, tmp.begin(), tmp.end());
					tmp.clear();
				}
			}
			return this->splitPair(node_size * 2, size, t);
		};
		template <typename T>
		int	binarySearch(int pivot, int end, int node_size, T &a, T &b)
		{
			int	middle;
			int	low = 0;
			int high = end - 1;
			
			while (low <= high)
			{
				middle = (high + low) / 2;

				if (b.at(pivot * node_size) <  a.at(middle * node_size))
					high = middle - 1;
				else
					low = middle + 1;
			}
			return low;
		};

		template <typename T>
		void	insertMerge(int size, int node_size, T &t)
		{
			if (node_size == 0)
				return ;

			T	tmp;
			int	start, end;
			int block = size / node_size;
			int b_blocks = block / 2;

			for (int i = 0; i < b_blocks; i++)
			{
				start = (i + 1) * node_size;
				end = start + node_size;
				tmp.insert(tmp.end(), t.begin() + start, t.begin() + end);
				t.erase(t.begin() + start, t.begin() + end);
			}
			if (block % 2)
			{
				tmp.insert(tmp.end(), t.begin() + start, t.begin() + end);
				t.erase(t.begin() + start, t.begin() + end);
				b_blocks++;
			}
			t.insert(t.begin(), tmp.begin(), tmp.begin() + node_size);
			tmp.erase(tmp.begin(), tmp.begin() + node_size);

			int selected = 1;
			int	move = 1;
			int first_move, jacob, select, find;

			for (int i = 3; !tmp.empty(); i++)
			{
				jacob = this->jacobsthalNumber(i);
				if (jacob >= b_blocks)
					jacob = b_blocks;
				end = jacob + move;
				if (block % 2)
					end--;
				select = jacob - move - 1;
				first_move = this->binarySearch(select, end, node_size, t, tmp);
				t.insert(t.begin() + first_move * node_size,
						tmp.begin() + select * node_size, tmp.begin() + (select + 1) * node_size);
				tmp.erase(tmp.begin() + select * node_size, tmp.begin() + (select + 1) * node_size);

				for (int j = jacob - 1; j > selected; j--)
				{
					end = j + move - 1;
					if (first_move <= end)
						end++;
					move++;
					select--;
					find = this->binarySearch(select, end, node_size, t, tmp);
					t.insert(t.begin() + find * node_size,
							tmp.begin() + select * node_size, tmp.begin() + (select + 1) * node_size);
					tmp.erase(tmp.begin() + select * node_size, tmp.begin() + (select + 1) * node_size);
				}
				selected = jacob;
				move++;
			}
			this->insertMerge(size, node_size / 2, t);
		};

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &target);
		PmergeMe &operator=(const PmergeMe &target);
		~PmergeMe(void);

		void	sort(int argc, char **argv) throw(std::exception);
};

#endif

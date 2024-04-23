/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:50:17 by bohlee            #+#    #+#             */
/*   Updated: 2023/11/19 15:05:03 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	private:
		Fixed const	x;
		Fixed const y;

	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &point);
		Point &operator= (const Point &point);
		~Point(void);
		const Fixed getX(void) const;
		const Fixed getY(void) const;

};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif

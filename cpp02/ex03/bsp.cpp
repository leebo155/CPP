/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:20:10 by bohlee            #+#    #+#             */
/*   Updated: 2023/11/19 16:50:14 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static	Fixed getTriangleArea(Point const a, Point const b, Point const c)
{
	Fixed area(((a.getX() * b.getY()) + (b.getX() * c.getY()) + (c.getX() * a.getY()))
		- ((a.getY() * b.getX()) + (b.getY() * c.getX()) + (c.getY() * a.getX())));
	area = area * Fixed(0.5f);
	if (area < 0)
		return area * Fixed(-1);
	return area;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	ABC = getTriangleArea(a, b, c);
	Fixed	PAB = getTriangleArea(point, a, b);
	Fixed	PBC = getTriangleArea(point, b, c);
	Fixed	PCA = getTriangleArea(point, c, a);

	if (ABC == 0 || PAB == 0 || PBC == 0 || PCA == 0)
		return false;
	else if (ABC.getRawBits() == PAB.getRawBits() + PBC.getRawBits() + PCA.getRawBits())
		return true;
	return false;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:08:47 by bohlee            #+#    #+#             */
/*   Updated: 2023/11/19 15:09:14 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): x(), y()
{
}

Point::Point(const float x, const float y): x(x), y(y)
{
}

Point::Point(const Point &point): x(point.getX()), y(point.getY())
{
}

Point	&Point::operator= (const Point &point)
{
	(void)point;
	return *this;
}

Point::~Point(void)
{
}

const Fixed	Point::getX(void) const
{
	return x;
}

const Fixed	Point::getY(void) const
{
	return y;
}

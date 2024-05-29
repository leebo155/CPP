/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:19:50 by bohlee            #+#    #+#             */
/*   Updated: 2023/11/19 16:33:37 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
	raw = 0;
}

Fixed::Fixed(const int num)
{
	raw = num << bit;
}

Fixed::Fixed(const float num)
{
	raw = roundf(num * (1 << bit));
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed &Fixed::operator= (const Fixed &fixed)
{
	if (this != &fixed)
		this->raw = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
}

int	Fixed::getRawBits(void) const
{
	return raw;
}

void	Fixed::setRawBits(int const raw)
{
	this->raw = raw;
}

float	Fixed::toFloat(void) const
{
	return static_cast<float>(raw) / static_cast<float>(1 << bit);
}

int		Fixed::toInt(void) const
{
	return raw >> bit;
}

std::ostream &operator<< (std::ostream &os, const Fixed &fixed)
{

	os << fixed.toFloat();
	return os;
}

bool	Fixed::operator> (Fixed &fix)
{
	return (this->getRawBits() > fix.getRawBits());
}

bool	Fixed::operator> (const Fixed &fix) const
{
	return (this->getRawBits() > fix.getRawBits());
}

bool	Fixed::operator< (Fixed &fix)
{
	return this->getRawBits() < fix.getRawBits();
}

bool	Fixed::operator< (const Fixed &fix) const
{
	return this->getRawBits() < fix.getRawBits();
}

bool	Fixed::operator>= (Fixed &fix)
{
	return this->getRawBits() >= fix.getRawBits();
}

bool	Fixed::operator>= (const Fixed &fix) const
{
	return this->getRawBits() >= fix.getRawBits();
}

bool	Fixed::operator<= (Fixed &fix)
{
	return this->getRawBits() <= fix.getRawBits();
}

bool	Fixed::operator<= (const Fixed &fix) const
{
	return this->getRawBits() <= fix.getRawBits();
}

bool	Fixed::operator== (Fixed &fix)
{
	return this->getRawBits() == fix.getRawBits();
}

bool	Fixed::operator== (const Fixed &fix) const
{
	return this->getRawBits() == fix.getRawBits();
}

bool	Fixed::operator!= (Fixed &fix)
{
	return this->getRawBits() != fix.getRawBits();
}

bool	Fixed::operator!= (const Fixed &fix) const
{
	return this->getRawBits() != fix.getRawBits();
}

float	Fixed::operator+ (Fixed fix) const
{
	return this->toFloat() + fix.toFloat();
}

float	Fixed::operator- (Fixed fix) const
{
	return this->toFloat() - fix.toFloat();
}

float	Fixed::operator* (Fixed fix) const
{
	return this->toFloat() * fix.toFloat();
}

float	Fixed::operator/ (Fixed fix) const
{
	return this->toFloat() / fix.toFloat();
}

Fixed	Fixed::operator++ (void)
{
	this->raw++;
	return Fixed(*this);
}

Fixed	Fixed::operator++ (int)
{
	Fixed tmp = *this;
	this->raw++;
	return (tmp);
}

Fixed	Fixed::operator-- (void)
{
	this->raw--;
	return Fixed(*this);
}

Fixed	Fixed::operator-- (int)
{
	Fixed tmp = *this;
	this->raw--;
	return tmp;
}

Fixed	Fixed::min(Fixed &fix1, Fixed &fix2)
{
	if (fix1 > fix2)
		return fix2;
	return fix1;
}

const Fixed	Fixed::min(const Fixed &fix1, const Fixed &fix2)
{
	if (fix1 > fix2)
		return fix2;
	return fix1;
}

Fixed	Fixed::max(Fixed &fix1, Fixed &fix2)
{
	if (fix1 < fix2)
		return fix2;
	return fix1;
}

const Fixed	Fixed::max(const Fixed &fix1, const Fixed &fix2)
{
	if (fix1 < fix2)
		return fix2;
	return fix1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:11:55 by bohlee            #+#    #+#             */
/*   Updated: 2023/11/19 16:33:59 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					raw;
		static const int	bit = 8;
	public:
		Fixed(void);
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &fixed);
		Fixed &operator= (const Fixed &fixed);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		bool operator> (Fixed &fix);
		bool operator> (const Fixed &fix) const;
		bool operator< (Fixed &fix);
		bool operator< (const Fixed &fix) const;
		bool operator>= (Fixed &fix);
		bool operator>= (const Fixed &fix) const;
		bool operator<= (Fixed &fix);
		bool operator<= (const Fixed &fix) const;
		bool operator== (Fixed &fix);
		bool operator== (const Fixed &fix) const;
		bool operator!= (Fixed &fix);
		bool operator!= (const Fixed &fix) const;
		float operator+ (Fixed fix) const;
		float operator- (Fixed fix) const;
		float operator* (Fixed fix) const;
		float operator/ (Fixed fix) const;
		Fixed operator++ (void);
		Fixed operator++ (int);
		Fixed operator-- (void);
		Fixed operator-- (int);
		static Fixed min(Fixed &fix1, Fixed &fix2); 
		static const Fixed min(const Fixed &fix1, const Fixed &fix2); 
		static Fixed max(Fixed &fix1, Fixed &fix2); 
		static const Fixed max(const Fixed &fix1, const Fixed &fix2); 
};

std::ostream &operator<< (std::ostream &os, const Fixed &fixed);

#endif

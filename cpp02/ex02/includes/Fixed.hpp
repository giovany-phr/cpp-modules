/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:05:46 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/29 03:00:15 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <string>
# include <cmath>
# include <iostream>

class Fixed
{
	private :
		int					_value;
		static const int	_nbrBits;
	
	public :
		Fixed();
		Fixed(int const nbr);
		Fixed(float const nbr);
		~Fixed();
		Fixed(const Fixed &other);

		Fixed	&operator = (const Fixed &other);

		bool	operator > (const Fixed &other) const;
		bool	operator < (const Fixed &other) const;
		bool	operator >= (const Fixed &other) const;
		bool	operator <= (const Fixed &other) const;
		bool	operator == (const Fixed &other) const;
		bool	operator != (const Fixed &other) const;

		Fixed	operator + (const Fixed &other) const;
		Fixed	operator * (const Fixed &other) const;
		Fixed	operator - (const Fixed &other) const;
		Fixed	operator / (const Fixed &other) const;

		Fixed	&operator ++ ();
		Fixed	operator ++(int);
		Fixed	&operator --();
		Fixed	operator --(int);

		static Fixed		&min(Fixed &Val1, Fixed &Val2);
		static const Fixed	&min(const Fixed &Val1, const Fixed &Val2);
		static Fixed		&max(Fixed &Val1, Fixed &Val2);
		static const Fixed	&max(const Fixed &Val1, const Fixed &Val2);

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fxd);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:22:03 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/21 16:08:38 by gpaupher         ###   ########.fr       */
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
		Fixed &operator = (const Fixed &other); //operator is a keyword
		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fxd);

#endif


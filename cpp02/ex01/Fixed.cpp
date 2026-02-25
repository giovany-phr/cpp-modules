/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:22:07 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/21 16:09:56 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Fixed.hpp"

const int Fixed::_nbrBits = 8;

Fixed::Fixed(): _value(0) //Default constructor
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const nbr)
{
	std::cout << "Int constructor called" << std::endl;
	_value = nbr << _nbrBits;
}

Fixed::Fixed(float const nbr)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf((nbr) * (1 << _nbrBits));
}

Fixed::~Fixed() //Destructor
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)//Copy constructor
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed	&Fixed::operator = (const Fixed &other)//Assignement constructor
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other._value;
	return (*this);
}

int		Fixed::getRawBits() const //Member function
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw) //Member function
{
	_value = raw;
}

float	Fixed::toFloat() const
{
	return (static_cast<float>(_value) / (1 << _nbrBits));
}

int		Fixed::toInt() const
{
	return (_value >> _nbrBits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fxd)
{
	os << fxd.toFloat();
	return (os);
}

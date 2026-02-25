/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:07:47 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/29 03:30:46 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Fixed.hpp"

const int Fixed::_nbrBits = 8;

Fixed::Fixed(): _value(0) //Default constructor
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const nbr)
{
	// std::cout << "Int constructor called" << std::endl;
	_value = nbr << _nbrBits;
}

Fixed::Fixed(float const nbr)
{
	// std::cout << "Float constructor called" << std::endl;
	_value = roundf((nbr) * (1 << _nbrBits));
}

Fixed::~Fixed() //Destructor
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)//Copy constructor
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed	&Fixed::operator = (const Fixed &other)//Assignement constructor
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other._value;
	return (*this);
}

/************** GETTER SETTER **************/

int		Fixed::getRawBits() const //Member function
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw) //Member function
{
	_value = raw;
}

/********************************************/

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

/************ Max and Min functions *************/

Fixed		&Fixed::min(Fixed &Val1, Fixed &Val2)
{
	if (Val1 <= Val2)
		return (Val1);
	else
		return (Val2);
}

const Fixed	&Fixed::min(const Fixed &Val1, const Fixed &Val2)
{
	if (Val1 <= Val2)
		return (Val1);
	else
		return (Val2);
}

Fixed		&Fixed::max(Fixed &Val1, Fixed &Val2)
{
	if (Val1 <= Val2)
		return (Val2);
	else
		return (Val1);
}

const Fixed	&Fixed::max(const Fixed &Val1, const Fixed &Val2)
{
	if (Val1 <= Val2)
		return (Val2);
	else
		return (Val1);
}

/************ Comparaison operators *************/

bool	Fixed::operator > (const Fixed &other) const
{
	return (_value > other._value);
}

bool	Fixed::operator < (const Fixed &other) const
{
	return (_value < other._value);
}

bool	Fixed::operator >= (const Fixed &other) const
{
	return (_value >= other._value);
}

bool	Fixed::operator <= (const Fixed &other) const
{
	return (_value <= other._value);
}

bool	Fixed::operator == (const Fixed &other) const
{
	return (_value == other._value);
}

bool	Fixed::operator != (const Fixed &other) const
{
	return (_value != other._value);
}

/************ arithmetic operators *************/

Fixed	Fixed::operator + (const Fixed &other) const
{
	return (Fixed(toFloat() + other.toFloat())) ;
}

Fixed	Fixed::operator - (const Fixed &other) const
{
	return (Fixed(toFloat() - other.toFloat())) ;
}

Fixed	Fixed::operator * (const Fixed &other) const
{
	return (Fixed(toFloat() * other.toFloat())) ;
}

Fixed	Fixed::operator / (const Fixed &other) const
{
	return (Fixed(toFloat() / other.toFloat())) ;
}

/************ Incrementation Decrementation operators *************/

Fixed	&Fixed::operator ++ ()
{
	_value++;
	return (*this);
}

Fixed	Fixed::operator ++(int)
{
	Fixed	temp = *this;
	_value++;
	return (temp);
}

Fixed	&Fixed::operator --()
{
	_value--;
	return (*this);
}

Fixed	Fixed::operator --(int)
{
	Fixed	temp = *this;
	_value--;
	return (temp);
}

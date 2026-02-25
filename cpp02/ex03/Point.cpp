/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:07:53 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/24 19:56:12 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Point.hpp"

Point::Point() : _x(0), _y(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
    // std::cout << "Float constructor called" << std::endl;
}

Point::Point(const Point &other) : _x(other.getX()), _y(other.getY())
{
    // std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator = (const Point &other)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (*this == other)
        return (*this);
    return (*this);
}

Point::~Point()
{
    // std::cout << "Destructor called" << std::endl;
}

/***********************************/

bool   Point::operator == (const Point &other) const
{
    if (_x == other._x && _y == other._y)
        return (1);
    else
        return (0);
}

bool   Point::operator != (const Point &other) const
{
    if (_x == other._x && _y == other._y)
        return (1);
    else
        return (0);
}

std::ostream &operator<<(std::ostream &os, const Point &pt)
{
    os << "x == " << pt.getX() << " y == "<< pt.getY();
    return (os);
}

/***********************************/

const Fixed &Point::getX() const 
{
    return (this->_x);
}

const Fixed  &Point::getY() const
{
    return (this->_y);
}
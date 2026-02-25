/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:08:04 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/24 19:41:36 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
# include "./Fixed.hpp"

class Point
{
    private :
        const Fixed _x;
        const Fixed _y;

    public :
        Point();
        Point(const float x, const float y);
        Point(const Point &other);
        Point &operator = (const Point &other);
        ~Point();

        const Fixed &getX() const;
        const Fixed &getY() const;

        bool   operator == (const Point &other) const;
        bool   operator != (const Point &other) const;

        
};

std::ostream &operator<<(std::ostream &os, const Point &pt);
bool    bsp(Point const a, Point const b, Point const c, Point const point);

# endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:07:45 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/24 20:42:35 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Point.hpp"

float   getArea(Point const som1, Point const som2, Point const som3) // air signe du triangle
{
    float area =    (som1.getX().toFloat() * (som2.getY().toFloat() - som3.getY().toFloat()) +
                    som2.getX().toFloat() * (som3.getY().toFloat() - som1.getY().toFloat()) +
                    som3.getX().toFloat() * (som1.getY().toFloat() - som2.getY().toFloat())) / 2;
    if (area >= 0)         
        return (area);
    else
        return (area * -1); // valeur absolue de l air
}

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
    float   areaABC = getArea(a, b, c);
    float   areaPBC = getArea(point, b, c);
    float   areaAPC = getArea(a, point, c);
    float   areaABP = getArea(a, b, point);
    if (areaPBC + areaAPC + areaABP == areaABC)
        return (1);
    return (0);
}
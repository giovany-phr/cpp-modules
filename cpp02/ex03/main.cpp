/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:07:50 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/24 20:46:59 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Fixed.hpp"
#include "./includes/Point.hpp"

int main( void )
{
    Point a(0, 0);
    Point const b(8.0f, 8.0f);
    Point c(14, 0);
    Point p(4, 4.0f);
	if (bsp(a, b, c, p))
		std::cout << "the point is indeed inside" << std::endl;
	else
		std::cout << "the point is not inside" << std::endl;
		
	Point newP(10, 10);
	if (bsp(a, b, c, newP))
		std::cout << "the point is indeed inside" << std::endl;
	else
		std::cout << "the point is not inside" << std::endl;
}
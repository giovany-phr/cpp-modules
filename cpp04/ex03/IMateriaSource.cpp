/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:34:46 by gpaupher          #+#    #+#             */
/*   Updated: 2025/05/06 23:07:48 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "./includes/IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
    std::cout << "IMateriaSource default constructor called" << std::endl;
}

IMateriaSource::IMateriaSource(IMateriaSource const &other)
{
    std::cout << "IMateriaSource copy constructor called" << std::endl;
    *this = other;
}

IMateriaSource &IMateriaSource::operator = (IMateriaSource const &other)
{
    (void) other;
    std::cout << "IMateriaSource assignement constructor called" << std::endl;
    return (*this);
}
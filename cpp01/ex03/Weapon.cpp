/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:35:31 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/28 23:46:50 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon()
{
	std::cout << "destuctor Weapon succesfully called" << std::endl;
}

void	Weapon::setType(std::string type)
{
	_type = type;
}

std::string	const &Weapon::getType() const
{
	return (_type);
}

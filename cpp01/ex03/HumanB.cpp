/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:35:34 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/28 23:50:40 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/HumanB.hpp"

HumanB::HumanB(std::string name) : _Weapon(NULL)
{
	_name = name;
	std::cout << _name << " has enterded" << std::endl;
}

HumanB::HumanB(std::string name, Weapon &weapon) : _name(name), _Weapon(&weapon)
{
	std::cout << _name << " has enterded with its "
	<< _Weapon->getType() << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "destuctor Human B succesfully called" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_Weapon = &weapon;
}

void	HumanB::attack()
{
	if (_Weapon != NULL)
		std::cout << this->_name << " attacks with their "
		<< this->_Weapon->getType() << std::endl;
	else
		std::cout << this->_name << " has no weapons" << std::endl;
}
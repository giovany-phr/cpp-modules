/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:35:38 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/10 21:08:31 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &Weapon) : _name(name), _Weapon(Weapon)
{
	std::cout << _name << " has enterded with its "
	<< _Weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "destuctor Human A succesfully called" << std::endl;
}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their "
	<< this->_Weapon.getType() << std::endl;
}
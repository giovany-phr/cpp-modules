/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:58:24 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/29 12:05:44 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Handsome Jack"), _hitPt(10), _energyPt(10), _attackDmg(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPt(10), _energyPt(10), _attackDmg(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hitPt, int energyPt, int attackDmg)
{
	std::cout << "Constructor called" << std::endl;
	_name = name;
	_hitPt = hitPt;
	_energyPt = energyPt;
	_attackDmg = attackDmg;
}

ClapTrap::ClapTrap(const ClapTrap &other) 
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &other)
{
	std::cout << "ClapTrap Assignement constructor called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPt = other._hitPt;
		_energyPt = other._energyPt;
		_attackDmg = other._attackDmg;
	}
	return (*this);
}

/****************************************************/

void	ClapTrap::attack(const std::string &target)
{
	if (_hitPt == 0)
	{
		std::cout << _name << " is down, has no hit point left to attack" << std::endl;
		return ;
	}
	else if (_energyPt == 0)
	{
		std::cout << _name << " has no energy point left to attack" << std::endl;
		return ;
	}
	_energyPt -= 1;
	std::cout << _name << " attacks " << target << ", causing "
	<< _attackDmg << " point of damage !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPt == 0)
	{
		std::cout << _name << " is already down" << std::endl;
		return ;
	}
	_hitPt -= amount;
	if (_hitPt < 0)
		_hitPt = 0;
	std::cout << _name << " gets hit and takes " << amount
	<< " of damages, " << _hitPt << " hit point and " 
	<< _energyPt << " energy points left" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPt == 0)
	{
		std::cout << _name << " cannot repair, its down" << std::endl;
		return ;
	}
	else if (_energyPt == 0)
	{
		std::cout << _name << " cannot repair, no energy points left" << std::endl;
		return ;
	}
	_hitPt += amount;
	_energyPt -= 1;
	std::cout << _name << " gets repaired " << amount
	<< " hit points back, " << _hitPt << " hit point and " 
	<< _energyPt << " energy points left" << std::endl;
}

/****************************************************/

void	ClapTrap::getStatus()
{
	std::cout << "Status CHECK :\n" << _name
	<< "'s attack is at " << _attackDmg << " and it has "
	<< _hitPt << " hit points and " << _energyPt
	<< " energy points left." << std::endl;
}
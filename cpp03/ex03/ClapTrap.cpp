/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:58:24 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/26 19:37:26 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/ClapTrap.hpp"


/***********************************************************/
/******************CONSTRUCTOR/DESTRUCTOR******************/
/*********************************************************/

ClapTrap::ClapTrap() : _name("handsome Jack"), _hitPt(10), _energyPt(10), _attackDmg(0)
{
	std::cout << "ClapTrap Default constructor called for "
	<< _name << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hitPt, int energyPt, int attackDmg)
{
	std::cout << "ClapTrap Constructor called for "
	<< _name << std::endl;
	_name = name;
	_hitPt = hitPt;
	_energyPt = energyPt;
	_attackDmg = attackDmg;
}

ClapTrap::ClapTrap(std::string name) : _hitPt(10), _energyPt(10), _attackDmg(0)
{
	_name = name;
	std::cout << "ClapTrap Constructor called for "
	<< _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) 
{
	*this = other;
	std::cout << "Claptrap Copy constructor called for "
	<< _name << std::endl;
	
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap Destructor called for "
	<< _name << std::endl;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &other)
{
	_name = other._name;
	_hitPt = other._hitPt;
	_energyPt = other._energyPt;
	_attackDmg = other._attackDmg;
	std::cout << "Claptrap Assignement constructor called for "
	<< _name << std::endl;
	return (*this);
}

/***********************************************************/
/********************MEMBER FUNCTIONS**********************/
/*********************************************************/

void	ClapTrap::attack(const std::string &target)
{
	if (_hitPt == 0)
	{
		std::cout << "ClapTrap " << _name << " is down, has no hit point left" << std::endl;
		return ;
	}
	else if (_energyPt == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy point left" << std::endl;
		return ;
	}
	_energyPt -= 1;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
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
	<< " of damages, " << _hitPt << " hit points and " 
	<< _energyPt << " energy points left" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPt == 0)
	{
		std::cout << _name << " cannot do that, its down" << std::endl;
		return ;
	}
	else if (_energyPt == 0)
	{
		std::cout << _name << " has no energy points left" << std::endl;
		return ;
	}
	_hitPt += amount;
	_energyPt -= 1;
	std::cout << _name << " gets repaired " << amount
	<< " hit points back, " << _hitPt << " hit points and " 
	<< _energyPt << " energy points left" << std::endl;
}

/*************************************************/
/********************GETTER**********************/
/***********************************************/

void	ClapTrap::getCStatus()
{
	std::cout << "Status CHECK :\n" << _name
	<< "'s attack is at " << _attackDmg << " and it has "
	<< _hitPt << " hit points and " << _energyPt
	<< " energy points left." << std::endl;
}
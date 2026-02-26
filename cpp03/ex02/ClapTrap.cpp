/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:58:24 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/29 12:10:36 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("handsome Jack"), _hitPt(10), _energyPt(10), _attackDmg(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hitPt, int energyPt, int attackDmg)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
	this->_name = name;
	this->_hitPt = hitPt;
	this->_energyPt = energyPt;
	this->_attackDmg = attackDmg;
}

ClapTrap::ClapTrap(std::string name) : _hitPt(10), _energyPt(10), _attackDmg(0)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
	this->_name = name;
}

ClapTrap::ClapTrap(const ClapTrap &other) 
{
	std::cout << "Claptrap Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &other)
{
	std::cout << "Claptrap Assignement constructor called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPt = other._hitPt;
		this->_energyPt = other._energyPt;
		this->_attackDmg = other._attackDmg;	
	}
	return (*this);
}

/****************************************************/

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hitPt == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is down, has no hit point left" << std::endl;
		return ;
	}
	else if (this->_energyPt == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy point left" << std::endl;
		return ;
	}
	this->_energyPt -= 1;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
	<< this->_attackDmg << " point of damage !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPt == 0)
	{
		std::cout << this->_name << " is already down" << std::endl;
		return ;
	}
	this->_hitPt -= amount;
	if (this->_hitPt < 0)
		this->_hitPt = 0;
	std::cout << this->_name << " gets hit and takes " << amount
	<< " of damages, " << this->_hitPt << " hit points and " 
	<< this->_energyPt << " energy points left" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPt == 0)
	{
		std::cout << this->_name << " cannot do that, its down" << std::endl;
		return ;
	}
	else if (this->_energyPt == 0)
	{
		std::cout << this->_name << " has no energy points left" << std::endl;
		return ;
	}
	this->_hitPt += amount;
	this->_energyPt -= 1;
	std::cout << this->_name << " gets repaired " << amount
	<< " hit points back, " << this->_hitPt << " hit points and " 
	<< this->_energyPt << " energy points left" << std::endl;
}

/****************************************************/

void	ClapTrap::getStatus()
{
	std::cout << "Status CHECK :\n" << this->_name
	<< "'s attack is at " << _attackDmg << " and it has "
	<< this->_hitPt << " hit points and " << this->_energyPt
	<< " energy points left." << std::endl;
}
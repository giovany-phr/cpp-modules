/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:37:43 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/29 12:30:22 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/ScavTrap.hpp"

/***********************************************************/
/******************CONSTRUCTOR/DESTRUCTOR******************/
/*********************************************************/

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_guarding_gate = false;
	this->_hitPt = getHit();
	this->_energyPt = getEnergy();
	this->_attackDmg = getAttack();
	std::cout << "ScavTrap default constructor called for "
	<< this->_name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_guarding_gate = false;
	this->_hitPt = getHit();
	this->_energyPt = getEnergy();
	this->_attackDmg = getAttack();
	std::cout << "ScavTrap constructor called for "
	<< this->_name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called for "
	<< this->_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called for "
	<< this->_name << std::endl;
	this->_guarding_gate = other._guarding_gate;
	*this = other;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &other)
{
	std::cout << "ScavTrap Assignement constructor called for "
	<< this->_name << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPt = other._hitPt;
		this->_energyPt = other._energyPt;
		this->_attackDmg = other._attackDmg;
	}
	return (*this);
}

/***********************************************************/
/********************MEMBER FUNCTIONS**********************/
/*********************************************************/

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hitPt == 0)
	{
		std::cout << "ScavTrap "<<this->_name << " is down, has no hit point left" << std::endl;
		return ;
	}
	else if (this->_energyPt == 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no energy point left" << std::endl;
		return ;
	}
	this->_energyPt -= 1;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing "
	<< this->_attackDmg << " point of damage !" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->_hitPt == 0)
	{
		std::cout << "ScavTrap " << this->_name << " is down, has no hit points left" << std::endl;
		return ;
	}
	else if (this->_energyPt == 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no energy points left" << std::endl;
		return ;
	}
	this->_guarding_gate = true;
	this->_energyPt -= 1;
	std::cout << this->_name << " is now in Gate Keeper mode" << std::endl;
}

void	ScavTrap::getScavStatus()
{
	std::cout << "Status CHECK :\n" << this->_name
	<< "'s attack is at " << this->_attackDmg << " and it has "
	<< this->_hitPt << " hit points and " << this->_energyPt
	<< " energy points left.";
	if (this->_guarding_gate)
		std::cout << " Gate keeper is ON" << std::endl;
	else
	std::cout << " Gate keeper is OFF" << std::endl;
}

/*************************************************/
/********************GETTER**********************/
/***********************************************/

int		ScavTrap::getHit()
{
	return (this->_hit);
}
int		ScavTrap::getEnergy()
{
	return (this->_nrg);
}
int		ScavTrap::getAttack()
{
	return (this->_atk);
}
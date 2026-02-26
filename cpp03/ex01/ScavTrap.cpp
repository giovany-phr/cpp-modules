/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:37:43 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/29 12:07:29 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_guarding_gate = false;
	this->_hitPt = 100;
	this->_energyPt = 50;
	this->_attackDmg = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_guarding_gate = false;
	this->_hitPt = 100;
	this->_energyPt = 50;
	this->_attackDmg = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	this->_guarding_gate = other._guarding_gate;
	*this = other;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &other)
{
	std::cout << "ScavTrap Assignement constructor called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPt = other._hitPt;
		this->_energyPt = other._energyPt;
		this->_attackDmg = other._attackDmg;	
	}
	return (*this);
}

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

void	ScavTrap::getStatus()
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
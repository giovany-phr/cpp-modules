/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:10:59 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/29 12:34:51 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/DiamondTrap.hpp"

/***********************************************************/
/******************CONSTRUCTOR/DESTRUCTOR******************/
/*********************************************************/

DiamondTrap::DiamondTrap() :
ClapTrap("handsome Jack_clap_name"), FragTrap(), ScavTrap()
{	
	this->_name = "handsome Jack";
	this->_hitPt = FragTrap::getHit(); //100
	this->_energyPt = ScavTrap::getEnergy(); //50
	this->_attackDmg = FragTrap::getAttack(); //30
	std::cout << "DiamondTrap default constructor called for "
	<< this->_name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : 
ClapTrap(name + "_clap_name")
{
	this->_name = name;
	this->_hitPt = FragTrap::getHit(); //100
	this->_energyPt = ScavTrap::getEnergy(); //50
	this->_attackDmg = FragTrap::getAttack(); //30
	std::cout << "DiamondTrap constructor called for "
	<< this->_name << std::endl;
}
 
DiamondTrap::DiamondTrap(const DiamondTrap &other)
: ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	std::cout << "DiamondTrap copy constructor called for " 
	<< this->_name << std::endl;
	*this = other;	
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called for "
	<< this->_name << std::endl;
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &other)
{
	std::cout << "DiamondTrap assignement constructor called for "
	<< this->_name << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPt = other._hitPt;
		this->_attackDmg = other._attackDmg;
		this->_energyPt = other._energyPt;
	}
	return (*this);
}

/***********************************************************/
/********************MEMBER FUNCTIONS**********************/
/*********************************************************/

void	DiamondTrap::attack(std::string name)
{
	ScavTrap::attack(name);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap's name is " << this->_name
	<< " and ClapTrap's name is " << ClapTrap::_name << std::endl;
}

/*************************************************/
/********************GETTER**********************/
/***********************************************/

void	DiamondTrap::getDStatus()
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
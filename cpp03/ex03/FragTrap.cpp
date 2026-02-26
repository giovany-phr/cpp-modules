/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:40:08 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/29 12:31:04 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/FragTrap.hpp"

/***********************************************************/
/******************CONSTRUCTOR/DESTRUCTOR******************/
/*********************************************************/

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called for "
	<< this->_name << std::endl;
	this->_hitPt = this->getHit();
	this->_energyPt = this->getEnergy();
	this->_attackDmg = this->getAttack();
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called for "
	<< this->_name << std::endl;
	this->_hitPt = this->getHit();
	this->_energyPt = this->getEnergy();
	this->_attackDmg = this->getAttack();
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called for "
	<< this->_name << std::endl;
	*this = other;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for "
	<< this->_name << std::endl;
}

FragTrap &FragTrap::operator = (const FragTrap &other)
{
	std::cout << "FragTrap assignement constructor called for "
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

void	FragTrap::getFragStatus()
{
	std::cout << "Status CHECK :\n" << this->_name
	<< "'s attack is at " << this->_attackDmg << " and it has "
	<< this->_hitPt << " hit points and " << this->_energyPt
	<< " energy points left." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << this->_name << " asks for a HIGH FIVE. "
	<< "(>_<) High fives guys !" << std::endl;
}

/*************************************************/
/********************GETTER**********************/
/***********************************************/

int		FragTrap::getHit()
{
	return (this->_hit);
}
int		FragTrap::getEnergy()
{
	return (this->_nrg);
}
int		FragTrap::getAttack()
{
	return (this->_atk);
}

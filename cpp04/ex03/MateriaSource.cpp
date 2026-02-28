/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:14:27 by gpaupher          #+#    #+#             */
/*   Updated: 2025/05/06 23:08:17 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/MateriaSource.hpp"

MateriaSource::MateriaSource() : _inventory()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &other) : IMateriaSource(other), _inventory()
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = other;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i])
            delete(this->_inventory[i]);
    }
}

MateriaSource &MateriaSource::operator = (MateriaSource const &other)
{
	std::cout << "MateriaSource assignement constructor called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i];
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			if (this->CheckInventory(m))
				this->_inventory[i] = m->clone();
			else
				this->_inventory[i] = m;
			std::cout << this->_inventory[i]->getType()
			<< "  Materia succesfully learned" << std::endl;
			return ;
		}
	}
	// if (m)
    //     std::cout << m->getType() <<" cannot be equiped. Inventory is full" << std::endl;
    // else
    //     std::cout << m->getType() <<" cannot be equiped. Invalid Materia" << std::endl;
    std::cout << "Invalid Materia. Cannot be learned." << std::endl;
    if (!this->CheckInventory(m))
        delete (m);
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
			return (this->_inventory[i]->clone());
	}
	std::cout << type << " Materia cannot be created" << std::endl;
	return (NULL);
}

bool MateriaSource::CheckInventory(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] == m)
            return (1);
    }
    return (0);
}

void MateriaSource::printInventory() const
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
        {
			std::cout << "Materia " << i << " "
			<< this->_inventory[i]->getType() << std::endl;
		}
	}
}
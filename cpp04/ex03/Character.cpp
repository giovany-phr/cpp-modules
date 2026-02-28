/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:38:38 by gpaupher          #+#    #+#             */
/*   Updated: 2025/05/06 22:24:44 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Character.hpp"

Character::Character() : _name("Default"), _inventory()
{
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string const &name) : _name(name), _inventory()
{
    std::cout << "Character constructor called" << std::endl;
}

Character::Character(Character const &other) : ICharacter(other), _inventory()
{
    std::cout << "Character copy constructor called" << std::endl;
    *this = other;
}

Character::~Character()
{
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i])
            delete(this->_inventory[i]);
    }
}

Character &Character::operator = (Character const &other)
{
    std::cout << "Character assignement constructor called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        for (int i = 0; i < 4; i++)
        {
            if (other._inventory[i])
                this->_inventory[i] = other._inventory[i];
        }
    }
    return (*this);
}

std::string const &Character::getName() const
{
    return (this->_name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] == NULL)
        {
            if (this->CheckInventory(m))
                this->_inventory[i] = m->clone();
            else
                this->_inventory[i] = m;
            std::cout << this->getName() << " equiped the Materia "
            << this->_inventory[i]->getType() << " to its inventory" << std::endl;
            return ;
        }
    }
    // if (m)
    //     std::cout << m->getType() <<" cannot be equiped. Inventory is full" << std::endl;
    // else
    //     std::cout << m->getType() <<" cannot be equiped. Invalid Materia" << std::endl;
    std::cout << "Invalid Materia. Cannot be equiped." << std::endl;
    if (!this->CheckInventory(m))
        delete (m);
}

void Character::unequip(int idx)
{
    if (0 <= idx && idx < 4)
    {
        std::cout << this->getName() << " unequiped the Materia "
        << this->_inventory[idx]->getType() << " from its inventory" << std::endl;
        this->_inventory[idx] = NULL;
    }
    else if (idx < 0 || 4 <= idx)
        std::cout << "Invalid index. Materia cannot be unequiped." << std::endl;
    else
        std::cout << "Invalid Materia. Materia cannot be unequiped." << std::endl;
}

bool Character::CheckInventory(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] == m)
            return (1);
    }
    return (0);
}

void Character::use(int idx, ICharacter& target)
{
    if ((0 <= idx && idx < 4) && this->_inventory[idx])
        this->_inventory[idx]->use(target);
    else
        std::cout << "Error: Cannot use Materia" << std::endl;
}

void Character::printInventory() const
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
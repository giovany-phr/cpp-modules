/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:50:01 by gpaupher          #+#    #+#             */
/*   Updated: 2025/05/01 16:34:48 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal::~Animal()
{
    std::cout << "Animal Desstructor called" << std::endl;
}

Animal &Animal::operator = (const Animal &other)
{
    std::cout << "Animal assignement constructor called" << std::endl;
    if (this != &other)
    {
        delete (this);
        this->_type = other._type;
    }
    return (*this);
}

void    Animal::makeSound()  const
{
    std::cout << this->_type
    << " makes wathever sound that is" << std::endl;
}

std::string Animal::getType() const
{
    return (this->_type);
}
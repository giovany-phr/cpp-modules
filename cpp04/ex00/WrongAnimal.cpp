/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:50:01 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/26 19:50:02 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Desstructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &other)
{
    std::cout << "WrongAnimal assignement constructor called" << std::endl;
    this->_type = other._type;
    return (*this);
}

void    WrongAnimal::makeSound()  const
{
    std::cout << this->_type
    << " goes \"AWOOO I am a furry\"" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->_type);
}
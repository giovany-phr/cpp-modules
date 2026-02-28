/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:50:09 by gpaupher          #+#    #+#             */
/*   Updated: 2025/05/01 16:39:11 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Cat.hpp"

Cat::Cat() : Animal()
{
    this->_type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
    this->_type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat::~Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat &Cat::operator = (const Cat &other) 
{
    std::cout << "Cat Assignement constructor called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;  
    }
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "The " << this->_type
    << " goes nyan nyan" << std::endl;
}

std::string Cat::getType() const
{
    return (this->_type);
}
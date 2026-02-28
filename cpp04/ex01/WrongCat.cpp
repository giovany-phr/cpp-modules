/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:50:09 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/26 19:55:54 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->_type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
    this->_type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = other;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat &WrongCat::operator = (const WrongCat &other) 
{
    std::cout << "WrongCat Assignement constructor called" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

void    WrongCat::makeSound() const
{
    std::cout << "The " << this->_type
    << " goes \"RELEASE ME I'M NOT A CAT\"" << std::endl;
}

std::string WrongCat::getType() const
{
    return (this->_type);
}
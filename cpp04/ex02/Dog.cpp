/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:50:12 by gpaupher          #+#    #+#             */
/*   Updated: 2025/05/05 18:34:37 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
    if (!this->_brain)
    {
        perror("Cat allocation failed");
		std::cerr << "Exiting process now";
		exit(1);
    }
}

Dog::Dog(std::string type) : Animal(type)
{
    this->_type = "Dog";
    this->_brain = new Brain();
    if (!this->_brain)
    {
        perror("Cat allocation failed");
		std::cerr << "Exiting process now";
		exit(1);
    }
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    *this = other;
}

Dog::~Dog()
{
    delete (this->_brain);
    std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator = (const Dog &other)
{
    std::cout << "Dog default constructor called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
        this->_brain = new Brain();
        if (!this->_brain)
        {
            perror("Cat allocation failed");
            std::cerr << "Exiting process now";
            exit(1);
        }
        *this->_brain = *other._brain;
    }
    return (*this);
}

void    Dog::makeSound() const
{
    std::cout << "The " << this->_type
    << " goes wuan wuan" << std::endl;
}

std::string Dog::getType() const
{
    return (this->_type);
}

void    Dog::getIdeas()
{
    for (int i = 0; i < 100; i++)
    std::cout << i << " idea: " << this->_brain->getIdea(i)
    << " at adress " << this->_brain->getIdAdress(i) << std::endl;
}

void    Dog::setIdea(size_t index, std::string idea)
{
    this->_brain->setIdea(index, idea);
}
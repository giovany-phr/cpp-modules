/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:50:09 by gpaupher          #+#    #+#             */
/*   Updated: 2025/05/05 18:34:22 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat default constructor called" << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
    if (!this->_brain)
    {
        perror("Cat allocation failed");
		std::cerr << "Exiting process now";
		exit(1);
    }
}

Cat::Cat(std::string type) : Animal(type)
{
    this->_type = "Cat";
    this->_brain = new Brain();
    if (!this->_brain)
    {
        perror("Cat allocation failed");
		std::cerr << "Exiting process now";
		exit(1);
    }
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat::~Cat()
{
    delete (this->_brain);
    std::cout << "Cat default constructor called" << std::endl;
}

Cat &Cat::operator = (const Cat &other) 
{
    std::cout << "Cat Assignement constructor called" << std::endl;
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

void    Cat::makeSound() const
{
    std::cout << "The " << this->_type
    << " goes nyan nyan" << std::endl;
}

std::string Cat::getType() const
{
    return (this->_type);
}

void    Cat::getIdeas()
{
    for (int i = 0; i < 100; i++)
        std::cout << i << " idea: " << this->_brain->getIdea(i)
        << " at adress " << this->_brain->getIdAdress(i) << std::endl;
}

void    Cat::setIdea(size_t index, std::string idea)
{
    this->_brain->setIdea(index, idea);
}
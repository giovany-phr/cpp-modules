/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 04:25:17 by gpaupher          #+#    #+#             */
/*   Updated: 2025/05/05 18:05:36 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}
Brain::Brain(std::string *ideas)
{
    std::cout << "Brain constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = ideas[i];
}
Brain::Brain(const Brain &other)
{
    *this = other;
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}
Brain &Brain::operator = (const Brain &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = other._ideas[i]; 
    }
    return (*this);std::string *getIdAdress(size_t i);
}

void    Brain::setIdea(size_t index, std::string idea)
{
    if (0 <= index && index < 100)
    {
        this->_ideas[index] = idea;
        std::cout << "Success Idea  : set into Brain" << std::endl;
    }
    else
        std::cout << "Error Idea    : Invalid index given" << std::endl;
}

std::string   Brain::getIdea(size_t index)
{
    if (0 <= index && index < 100)
        return (this->_ideas[index]);
    else
        std::cout << "Invalid index given" << std::endl;
    return (NULL);
}

std::string *Brain::getIdAdress(size_t i)
{
    if (i < 0 && 100 <= i)
        return (NULL);
    else
    {
        std::string &stringRef = this->_ideas[i];
        return (&stringRef);
    }
}


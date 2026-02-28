/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:37:10 by gpaupher          #+#    #+#             */
/*   Updated: 2025/05/06 23:07:16 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/ICharacter.hpp"

ICharacter::ICharacter()
{
    std::cout << "ICharacter default constructor called" << std::endl;
}

ICharacter::ICharacter(ICharacter const &other)
{
    std::cout << "Character copy constructor called" << std::endl;
    *this = other;
}

ICharacter &ICharacter::operator = (ICharacter const &other)
{
    (void) other;
    std::cout << "Character assignement constructor called" << std::endl;
    return (*this);
}
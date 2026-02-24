/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:06:48 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/10 17:46:21 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    Zombie *Undead = new Zombie(name);
    if (!Undead)
    {
        std::cout << "Error with the memory allocation" << std::endl;
        return (NULL);
    }
    return (Undead);
}
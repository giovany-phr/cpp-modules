/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:06:42 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/09 17:45:52 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    private :
        std::string _name;

    public :
        Zombie(std::string name);
        ~Zombie();
        void announce();
     
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif

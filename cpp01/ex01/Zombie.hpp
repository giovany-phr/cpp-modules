/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:06:42 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/10 17:03:05 by gpaupher         ###   ########.fr       */
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
        Zombie();
        ~Zombie();
        void announce();
        void set_name(std::string name);
};

Zombie *zombieHorde(int N, std::string name);

#endif

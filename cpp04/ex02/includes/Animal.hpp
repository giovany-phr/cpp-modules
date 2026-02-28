/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:49:43 by gpaupher          #+#    #+#             */
/*   Updated: 2025/05/05 18:41:44 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
#include <cstdio>
#include <cstdlib>

class Animal
{
    protected :
        std::string _type;
        Animal(),
        Animal(std::string type);
        Animal(const Animal &other);

    public :
        virtual ~Animal();

        Animal &operator = (const Animal &other);

        virtual void        makeSound() const;
        virtual std::string getType() const; 
};

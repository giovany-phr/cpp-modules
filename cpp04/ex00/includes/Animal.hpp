/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:49:43 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/26 19:56:42 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>

class Animal
{
    protected :
        std::string _type;

    public :
        Animal(),
        Animal(std::string type);
        Animal(const Animal &other);
        virtual ~Animal();

        Animal &operator = (const Animal &other);

        virtual void        makeSound() const;
        virtual std::string getType() const; 
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:49:52 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/26 19:55:27 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    private :
        // std::string type;

    public :
        WrongCat();
        WrongCat(std::string type);
        WrongCat(const WrongCat &other);
        ~WrongCat();

        WrongCat &operator = (const WrongCat &other);

        void    makeSound() const;
        std::string getType() const;
};
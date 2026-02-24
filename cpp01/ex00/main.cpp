/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:02:13 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/10 17:46:47 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *Zombie;
	Zombie = newZombie("Jeff");
	if (!Zombie)
		return (1);
	Zombie->announce();
    randomChump("Chumpy");
    delete(Zombie);
	return (0);
}
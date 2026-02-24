/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:22:11 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/28 23:52:43 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/HumanA.hpp"
#include "./includes/HumanB.hpp"

int main()
{
	std::cout << "=========Test 1=========" << std::endl;
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();

	std::cout << "\n=========Test 2=========" << std::endl;
	Weapon club1 = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club1);
	jim.attack();
	club1.setType("some other type of club");
	jim.attack();
	
	std::cout << "\n=========Test 3=========" << std::endl;
	Weapon club2 = Weapon("crude spiked club");
	HumanB tom("Tom", club2);
	tom.attack();
	club2.setType("some other type of club");
	tom.attack();
	return 0;
}
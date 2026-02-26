/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:58:28 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/26 19:33:59 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/ClapTrap.hpp"
# include "./includes/ScavTrap.hpp"
# include "./includes/FragTrap.hpp"
# include "./includes/DiamondTrap.hpp"


int main()
{
	std::cout << "==========TEST 1==========" << std::endl;
	DiamondTrap	cl4p_tp("CL4P_TP");
	cl4p_tp.getDStatus();
	cl4p_tp.attack("jack");
	cl4p_tp.takeDamage(5);
	cl4p_tp.beRepaired(2);
	cl4p_tp.getDStatus();
	cl4p_tp.whoAmI();

	std::cout << "\n==========TEST 2==========" << std::endl;
	DiamondTrap	jack;
	jack.getDStatus();
	jack.takeDamage(200);
	jack.beRepaired(5);
	jack.getDStatus();

	std::cout << "\n==========TEST 3==========" << std::endl;
	DiamondTrap	moxxie("moxxie");
	DiamondTrap	ellie(moxxie);
	DiamondTrap	scooter;
	scooter = moxxie;
	moxxie.getDStatus();
	ellie.getDStatus();
	scooter.getDStatus();
	moxxie.whoAmI();
	ellie.whoAmI();

	std::cout << "\n==========TEST 4==========" << std::endl;
	DiamondTrap	lilith("Lilith");

	lilith.guardGate();
	lilith.highFivesGuys();
	lilith.getDStatus();
	return (0);
}
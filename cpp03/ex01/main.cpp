/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:58:28 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/25 16:36:50 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/ClapTrap.hpp"
# include "./includes/ScavTrap.hpp"

int main()
{
	std::cout << "==========TEST 1==========" << std::endl;
	ScavTrap	cl4p_tp("CL4P_TP");
	cl4p_tp.getStatus();
	cl4p_tp.attack("jack");
	cl4p_tp.takeDamage(5);
	cl4p_tp.beRepaired(2);
	cl4p_tp.guardGate();
	cl4p_tp.getStatus();

	std::cout << "\n==========TEST 2==========" << std::endl;
	ScavTrap	jack;
	jack.getStatus();
	jack.takeDamage(200);
	jack.beRepaired(5);
	jack.getStatus();

	std::cout << "\n==========TEST 3==========" << std::endl;
	ScavTrap	moxxie("moxxie");
	ScavTrap	ellie(moxxie);
	ScavTrap	scooter;
	scooter = moxxie;
	scooter.guardGate();
	moxxie.getStatus();
	ellie.getStatus();
	scooter.getStatus();
	return (0);
}
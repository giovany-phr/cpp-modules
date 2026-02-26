/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:58:28 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/29 12:04:28 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/ClapTrap.hpp"

int main()
{
	std::cout << "==========TEST 1==========" << std::endl;
	ClapTrap	cl4p_tp("CL4P_TP");
	cl4p_tp.getStatus();
	cl4p_tp.attack("jack");
	cl4p_tp.takeDamage(5);
	cl4p_tp.beRepaired(2);
	cl4p_tp.getStatus();

	std::cout << "\n==========TEST 2==========" << std::endl;
	ClapTrap	jack;
	jack.getStatus();
	jack.takeDamage(200);
	jack.beRepaired(5);
	jack.getStatus();

	std::cout << "\n==========TEST 3==========" << std::endl;
	ClapTrap	moxxie("moxxie");
	ClapTrap	ellie(moxxie);
	ClapTrap	scooter;
	scooter = moxxie;
	moxxie.getStatus();
	ellie.getStatus();
	scooter.getStatus();
	return (0);
}
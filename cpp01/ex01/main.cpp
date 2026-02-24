/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:02:13 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/28 21:20:41 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie	*walkers;
	int		N;

	N = 6;
	walkers = zombieHorde(N, "walker");
	if (!walkers)
		return (1);
	for (int i = 0; i < N; i++)
	{
		std::cout << i << ": ";
		walkers->announce();
	}
	delete[](walkers);
	return (0);
}
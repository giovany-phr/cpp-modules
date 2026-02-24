/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:47:43 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/10 17:44:52 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	int	i;
	
	Zombie	*Undeads = new Zombie[N];
	if (!Undeads)
	{
		std::cout << "Error with the memory allocation" << std::endl;
		return (NULL);
	}
	for(i = 0; i < N; i++)
	{
		Undeads[i].set_name(name);
	}
	return (Undeads);
}
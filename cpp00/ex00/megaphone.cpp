/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:18:57 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/28 20:25:48 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "iostream"	

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc > 1)
	{
		for (i = 1; argv[i]; i++)
		{
			j = -1;
			while (argv[i][++j])
				argv[i][j] = std::toupper(argv[i][j]);
		}
		for (i = 1; argv[i]; i++)
		{
			std::cout<<argv[i];
		}
		std::cout<<std::endl;
	}
	else
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
	return (0);
}
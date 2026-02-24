/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:59:39 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/15 18:12:45 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/File.hpp"

int	checkSrc(char *file, char *s1, char *s2)
{
	std::string		src1(s1);
	std::string		src2(s2);
	std::string		buffer;
	std::string		nameFile(file) ;

	if (src1 == src2)
	{
		nameFile = nameFile + ".replace";
		std::ofstream outFile((nameFile.c_str()));
		std::ifstream inFile(file);
		if (!inFile.is_open() && !outFile.is_open())
		{
			std::cerr << "Error : files opening "<< std::endl;
			return (1);
		}
		while (getline(inFile, buffer))
			outFile << buffer << std::endl;;
		inFile.close();
		outFile.close();
		return (1);
	}
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Error : Number of arguments" << std::endl;
		return (1);
	}
	if (createReplace(av[1]))
		return (1);
	if (checkSrc(av[1], av[2], av[3]))
		return (1);
	if (readAndReplace(av[1], av[2], av[3]))
		return (1);
	return (0);
}

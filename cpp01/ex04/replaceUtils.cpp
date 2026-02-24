/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceUtils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:11:30 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/29 00:11:28 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/File.hpp"

int	createReplace(char *file)
{
	std::ifstream	inFile(file);
	std::string	nameFile(file);

	if (!inFile.is_open())
	{
		std::cerr << "Error : file opening " << file << std::endl;
		return (1);
	}
	nameFile = nameFile + ".replace";
	std::ofstream newFile(nameFile.c_str());
	if (!newFile.is_open())
	{
		std::cerr << "Error : file opening " << file << std::endl;
		return (1);
	}
	newFile.close();
	return (0);
}

void	printReplace(std::string buffer, char *s1, char *s2, std::ofstream &outFile)
{
	size_t			pos;
	std::string		str1(s1);
	std::string		str2(s2);
	
	pos = buffer.find(str1);
	while (pos != std::string::npos)
	{
		buffer.erase(pos, str1.length());
		buffer.insert(pos, str2);
		pos = buffer.find(str1);
	}
	if (pos == std::string::npos)
		outFile << buffer << std::endl;
}

int	readAndReplace(char *file, char *s1, char *s2)
{
	std::ifstream	inFile(file);
	std::string		buffer;
	std::string		nameFile(file) ;
	
	nameFile = nameFile + ".replace";
	std::ofstream outFile((nameFile.c_str()));
	if (!inFile.is_open() && !outFile.is_open())
	{
		std::cerr << "Error : file opening " << file << std::endl;
		return (1);
	}
	while (getline(inFile, buffer))
		printReplace(buffer, s1, s2, outFile);
	inFile.close();
	outFile.close();
	return (0);
}
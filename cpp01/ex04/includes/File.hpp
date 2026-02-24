/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:17:05 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/15 18:11:04 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
#define FILE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cstring>


int	checkSrc(char *file, char *s1, char *s2);

int		createReplace(char *file);
int		readAndReplace(char *file, char *s1, char *s2);
void	printReplace(std::string buffer, char *s1, char *s2, std::ofstream &outFile);

#endif

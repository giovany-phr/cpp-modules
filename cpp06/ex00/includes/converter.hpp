/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:06:07 by gpaupher          #+#    #+#             */
/*   Updated: 2025/06/05 19:51:17 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include <string>
# include <exception>
# include <limits.h>
# include <cstdlib>
# include <cfloat>
# include <iomanip> // std::setprecision

# define ERR	0
# define CHAR	1
# define INT	2
# define FLOAT	3
# define DOUBLE	4

#define	NAN_INF	5

int     typeFinder(std::string str);
int     ft_isChar(std::string str);
int     ft_isDigit(std::string str);
int     ft_isSpe(std::string str);

bool    checkInput(std::string str);
bool	checkSigns(std::string str);
bool	isDuplicata(std::string str);

void	isSpe(std::string str);
void	isChar(std::string str);
void	isInt(std::string str);
void	isFloat(std::string str);
void	isDouble(std::string str);

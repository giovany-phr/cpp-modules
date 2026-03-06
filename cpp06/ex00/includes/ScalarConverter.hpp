/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:48:23 by gpaupher          #+#    #+#             */
/*   Updated: 2025/06/05 19:51:38 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include <string>
# include <exception>
# include <limits.h>
# include <cstdlib>

# include "converter.hpp"

class ScalarConverter
{
	private :
		ScalarConverter();

	public :
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();

		ScalarConverter &operator = (const ScalarConverter &other);
		
		static void convert(std::string str);
};
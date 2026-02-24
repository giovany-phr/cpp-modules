/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:29:27 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/18 18:29:47 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARLFILTER_HPP
#define HARLFILTER_HPP

# include <string>
# include <iostream>

class	HarlFilter
{
	public :
		HarlFilter();
		~HarlFilter();
		void complain(std::string level);

	private :
		void debug();
		void info();
		void warning();
		void error();
		std::string	_LevelTab[4];
		void (HarlFilter::*_LevelPtr[4])();
};

#endif

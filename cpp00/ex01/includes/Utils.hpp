/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:45:28 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/04 20:48:10 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>

bool		check_data(std::string buffer, int flag);
bool		check_string(std::string buffer, int flag);
std::string	trunContact(std::string str);
void		print_header();
bool		delete_msg();

#endif
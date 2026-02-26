/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:39:56 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/29 12:29:15 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "./ClapTrap.hpp"

class FragTrap :  public virtual  ClapTrap
{
	public :
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		virtual ~FragTrap();

		FragTrap &operator = (const FragTrap &other);

		void	highFivesGuys(void);
		
		void	getFragStatus();
		int		getHit();
		int		getEnergy();
		int		getAttack();

	private :
		static const int _hit = 100;
		static const int _nrg = 100;
		static const int _atk = 30;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:59:08 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:21:05 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : virtual public FragTrap, virtual public ScavTrap
{
private:
	std::string name;

public:
	/*                               ORTHODOX CLASS                           */
	DiamondTrap(void);
	DiamondTrap(std::string _name);
	DiamondTrap(const DiamondTrap &rhs);
	~DiamondTrap(void);
	DiamondTrap &operator=(const DiamondTrap &rhs);

	/*                               METHODS                                  */
	void whoAmI();
	void displayStat();

};

#endif
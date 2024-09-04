/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:59:08 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/04 15:11:19 by cdomet-d         ###   ########lyon.fr   */
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
	DiamondTrap(const DiamondTrap &copy);
	~DiamondTrap(void);
	DiamondTrap &operator=(const DiamondTrap &copy);

	/*                               METHODS                                  */

	/*                               GETTERS                                  */

	/*                               SETTERS                                  */
};

#endif
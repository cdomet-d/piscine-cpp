/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:34:27 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/05 17:49:37 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

class ScavTrap : public ClapTrap
{
public:
	/*                               ORTHODOX CLASS                           */
	ScavTrap(void);
	ScavTrap(std::string _name);
	ScavTrap(const ScavTrap &copy);
	~ScavTrap(void);
	ScavTrap &operator=(const ScavTrap &copy);

	/*                               METHODS                                  */
	void guardGate(void);
	void attack(const std::string &target);
};

#endif

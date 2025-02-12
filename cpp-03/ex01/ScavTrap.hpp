/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:34:27 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:21:05 by cdomet-d         ###   ########.fr       */
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
	ScavTrap(const ScavTrap &rhs);
	~ScavTrap(void);
	ScavTrap &operator=(const ScavTrap &rhs);

	/*                               METHODS                                  */
	void guardGate(void);
	void attack(const std::string &target);
};

#endif

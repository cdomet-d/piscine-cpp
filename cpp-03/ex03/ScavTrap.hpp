/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:34:27 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/04 14:46:23 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

class ScavTrap : virtual public ClapTrap
{
private:
	
public:
	/*                               ORTHODOX CLASS                           */
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &copy);
	~ScavTrap(void);
	ScavTrap &operator=(const ScavTrap &copy);

	/*                               METHODS                                  */
	void guardGate(void);
};

#endif

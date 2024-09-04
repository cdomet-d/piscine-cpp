/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:34:27 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/04 14:36:19 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

class FragTrap : public ClapTrap
{
private:
	
public:
	/*                               ORTHODOX CLASS                           */
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &copy);
	~FragTrap(void);
	FragTrap &operator=(const FragTrap &copy);

	/*                               METHODS                                  */
	void highFivesGuys(void);
	void attack(const std::string &target);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:34:27 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:21:05 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

class FragTrap : virtual public ClapTrap
{
protected:
	static const unsigned int dftFragDmg = 30;
	static const unsigned int dftFragHitPts = 100;
public:
	/*                               ORTHODOX CLASS                           */
	FragTrap(void);
	FragTrap(std::string _name);
	FragTrap(const FragTrap &rhs);
	~FragTrap(void);
	FragTrap &operator=(const FragTrap &rhs);

	/*                               METHODS                                  */
	void highFivesGuys(void);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:34:27 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/05 17:49:28 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

class FragTrap : public ClapTrap
{
private:
	static const long int fragTrapMaxHitPts = 100;
	static const long int fragTrapHitPts = 100;
	static const unsigned int fragTrapEnergyPts = 100;
	static const unsigned int fragTrapAttackDmg = 30;

public:
	/*                               ORTHODOX CLASS                           */
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &copy);
	~FragTrap(void);
	FragTrap &operator=(const FragTrap &copy);

	/*                               METHODS                                  */
	void highFivesGuys(void);

	/*                               GETTERS                                  */
	long int getFragDmg(void) const;
	long int getFragEnergyPts(void) const;
	long int getFragHitPts(void) const;
	long int getFragMaxHitPts(void) const;
};

#endif
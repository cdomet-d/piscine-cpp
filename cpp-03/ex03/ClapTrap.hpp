/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:11:51 by jauseff           #+#    #+#             */
/*   Updated: 2024/09/05 17:40:23 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

#define R "\033[0m" // reset

#define G "\x1b[32m" // clapTrap
#define B "\x1b[34m" // scavTrap
#define P "\x1b[35m" // fragTrap
#define C "\x1b[33m" // DiamondTrap

class ClapTrap
{
protected:
	std::string name;
	long int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;

public:
	/*                               ORTHODOX CLASS                           */
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	~ClapTrap(void);
	ClapTrap &operator=(const ClapTrap &comp);

	/*                               METHODS                                  */
	void attack(const std::string &target);
	void beRepaired(unsigned int amount);
	void takeDamage(unsigned int amount);

	/*                               GETTERS                                  */
	long int getHealth(void) const;
	std::string getName(void) const;
	unsigned int getDamage(void) const;
	unsigned int getEnergy(void) const;

	/*                               SETTERS                                  */
	void setDamage(unsigned int _damage);
	void setEnergy(unsigned int _energy);
	void setHealth(unsigned int _health);
	void setName(std::string _name);
};

#endif
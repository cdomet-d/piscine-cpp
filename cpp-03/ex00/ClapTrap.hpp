/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:11:51 by jauseff           #+#    #+#             */
/*   Updated: 2024/09/04 13:48:23 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

# define G "\x1B[0;32m"
# define B "\x1B[0;34m"
# define R "\033[0m"

class ClapTrap
{
private:
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
	unsigned int getDamage(void);
	unsigned int getEnergy(void);
	long int getHealth(void);
	void attack(const std::string &target);
	void beRepaired(unsigned int amount);
	void setDamage(unsigned int newDamage);
	void takeDamage(unsigned int amount);
	void displayStats(void);
};

#endif
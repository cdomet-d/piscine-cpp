/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:11:51 by jauseff           #+#    #+#             */
/*   Updated: 2024/09/02 16:55:01 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class clapTrap
{
private:
	std::string name;
	long int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;

public:
	/*                               ORTHODOX CLASS                           */
	clapTrap(void);
	clapTrap(std::string name);
	clapTrap(const clapTrap &copy);
	~clapTrap(void);
	clapTrap &operator=(const clapTrap &comp);

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
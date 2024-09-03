/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:11:51 by jauseff           #+#    #+#             */
/*   Updated: 2024/09/03 11:53:11 by cdomet-d         ###   ########lyon.fr   */
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
	void attack(const std::string &target);
	void beRepaired(unsigned int amount);
	void displayStats(void);
	void takeDamage(unsigned int amount);

	/*                               GETTERS                                  */
	long int 		getHealth(void);
	std::string		getName(void);
	unsigned int	getDamage(void);
	unsigned int	getEnergy(void);

	/*                               SETTERS                                  */
	void			setDamage(unsigned int _damage);
	void			setEnergy(unsigned int _energy);
	void			setHealth(unsigned int _health);
	void			setName(std::string _name);
};

#endif
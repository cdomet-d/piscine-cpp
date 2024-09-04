/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:11:51 by jauseff           #+#    #+#             */
/*   Updated: 2024/09/04 13:54:17 by cdomet-d         ###   ########lyon.fr   */
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
	long int maxHitPoint;
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
	void displayStats(void);
	void takeDamage(unsigned int amount);

	/*                               GETTERS                                  */
	long int 		getHealth(void) const;
	std::string		getName(void) const;
	unsigned int	getDamage(void) const;
	unsigned int	getEnergy(void) const;
	unsigned int	getMaxHitPoint(void) const;


	/*                               SETTERS                                  */
	void			setMaxHitPoint(unsigned int _maxHitPoint);
	void			setDamage(unsigned int _damage);
	void			setEnergy(unsigned int _energy);
	void			setHealth(unsigned int _health);
	void			setName(std::string _name);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:35:00 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/26 17:00:24 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
protected:
	std::string name;
	AMateria *inventory[4];
public:
	/*                               ORTHODOX CLASS                           */
	Character(void);
	Character(std::string _name);
	Character(const Character &copy);
	~Character(void);
	Character &operator=(const Character &copy);

	/*                               METHODS                                  */
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);
	void	displayInventory(void);
	/*                               GETTERS                                  */
	std::string const &getName(void) const;
};

#endif

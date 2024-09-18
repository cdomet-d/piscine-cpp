/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:53:12 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/18 14:30:24 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include "AMateria.hpp"
class AMateria;

class ICharacter
{
protected:
	std::string name;
	AMateria *inventory[4];
public:
	/*                               ORTHODOX CLASS                           */
	ICharacter(void);
	ICharacter(const ICharacter &copy);
	~ICharacter(void);
	ICharacter &operator=(const ICharacter &copy);

	/*                               METHODS                                  */
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;

	/*                               GETTERS                                  */
	virtual std::string const & getName() const = 0;
};

#endif

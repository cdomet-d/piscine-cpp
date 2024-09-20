/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:13:12 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/20 16:19:26 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string type;

public:
	/*                               ORTHODOX CLASS                           */
	AMateria(void);
	AMateria(const AMateria &copy);
	AMateria(std::string const &_type);
	virtual ~AMateria(void);
	AMateria &operator=(const AMateria &copy);

	/*                               METHODS                                  */
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);

	/*                               GETTERS                                  */
	std::string const &getType() const;

	/*                               SETTERS                                  */
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CureMateria.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:32:13 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/18 13:45:38 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUREMATERIA_HPP
# define CUREMATERIA_HPP

#include "AMateria.hpp"

class CureMateria : public AMateria
{
private:
	
public:
	/*                               ORTHODOX CLASS                           */
	CureMateria(void);
	CureMateria(const CureMateria &copy);
	~CureMateria(void);
	CureMateria &operator=(const CureMateria &copy);

	/*                               METHODS                                  */
	virtual CureMateria* clone() const;
	virtual void use(ICharacter& target);

	/*                               GETTERS                                  */
	
	/*                               SETTERS                                  */
};

#endif
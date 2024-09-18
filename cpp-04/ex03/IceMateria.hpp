/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IceMateria.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:39:46 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/18 16:04:34 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICEMATERIA_HPP
#define ICEMATERIA_HPP

#include "AMateria.hpp"

class IceMateria : public AMateria
{
private:
public:
	/*                               ORTHODOX CLASS                           */
	IceMateria(void);
	IceMateria(const IceMateria &copy);
	~IceMateria(void);
	IceMateria &operator=(const IceMateria &copy);

	/*                               METHODS                                  */
	virtual IceMateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif

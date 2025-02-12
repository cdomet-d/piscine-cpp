/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:39:46 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/18 16:04:34 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
private:
public:
	/*                               ORTHODOX CLASS                           */
	Ice(void);
	Ice(const Ice &rhs);
	~Ice(void);
	Ice &operator=(const Ice &rhs);

	/*                               METHODS                                  */
	virtual Ice *clone() const;
	virtual void use(ICharacter &target);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:32:13 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/18 16:04:57 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
private:
public:
	/*                               ORTHODOX CLASS                           */
	Cure(void);
	Cure(const Cure &copy);
	~Cure(void);
	Cure &operator=(const Cure &copy);

	/*                               METHODS                                  */
	virtual Cure *clone() const;
	virtual void use(ICharacter &target);

	/*                               GETTERS                                  */

	/*                               SETTERS                                  */
};

#endif
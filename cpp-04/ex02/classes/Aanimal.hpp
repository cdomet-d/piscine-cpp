/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aanimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:52:58 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/16 10:20:01 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class Aanimal
{
protected:
	std::string type;

public:
	/*                               ORTHODOX CLASS                           */
	Aanimal(void);
	Aanimal(std::string _type);
	Aanimal(const Aanimal &rhs);
	virtual ~Aanimal(void);
	Aanimal &operator=(const Aanimal &rhs);

	/*                               METHODS                                  */
	virtual void makeSound(void) const = 0;
	std::string getType(void) const;
};

#endif

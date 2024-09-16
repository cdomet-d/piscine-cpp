/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:52:58 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/16 10:20:01 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
protected:
	std::string	type;
public:
	/*                               ORTHODOX CLASS                           */
	Animal(void);
	Animal(const Animal &copy);
	virtual ~Animal(void);
	Animal &operator=(const Animal &copy);

	/*                               METHODS                                  */
	virtual void makeSound(void) const = 0;
	std::string getType(void) const;
};

#endif

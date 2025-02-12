/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:52:58 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:21:05 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

#define R "\033[0m" // reset
#define COLOR "\x1b[35m"

class Animal
{
protected:
	std::string	type;
public:
	/*                               ORTHODOX CLASS                           */
	Animal(void);
	Animal(std::string _type);
	Animal(const Animal &rhs);
	virtual ~Animal(void);
	Animal &operator=(const Animal &rhs);

	/*                               METHODS                                  */
	virtual void makeSound(void) const;
	std::string getType(void) const;
};

#endif

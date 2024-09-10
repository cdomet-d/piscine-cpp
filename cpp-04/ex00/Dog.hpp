/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:23:23 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/10 17:29:53 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
private:
	
public:
	/*                               ORTHODOX CLASS                           */
	Dog(void);
	Dog(const Dog &copy);
	~Dog(void);
	Dog &operator=(const Dog &copy);

	/*                               METHODS                                  */
	void makeSound(void) const;
};

#endif

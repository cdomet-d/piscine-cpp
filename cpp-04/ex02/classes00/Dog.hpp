/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:23:23 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/16 17:51:42 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Aanimal.hpp"
#include "Brain.hpp"

class Dog : public Aanimal
{
private:
	Brain *brain;

public:
	/*                               ORTHODOX CLASS                           */
	Dog(void);
	Dog(const Dog &copy);
	~Dog(void);
	Dog &operator=(const Dog &copy);

	/*                               METHODS                                  */
	void makeSound(void) const;
	void fillPetArr(std::string s) const;
	void displayThoughts(void) const;
};

#endif

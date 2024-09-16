/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:23:23 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/16 17:51:33 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Aanimal.hpp"
#include "Brain.hpp"

class Cat : public Aanimal
{
private:
	Brain *brain;

public:
	/*                               ORTHODOX CLASS                           */
	Cat(void);
	Cat(const Cat &copy);
	~Cat(void);
	Cat &operator=(const Cat &copy);

	/*                               METHODS                                  */
	void makeSound(void) const;
	void fillPetArr(std::string s) const;
	void displayThoughts(void) const;
};

#endif

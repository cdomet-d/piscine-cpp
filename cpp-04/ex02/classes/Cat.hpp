/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:23:23 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/26 16:51:42 by cdomet-d         ###   ########.fr       */
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

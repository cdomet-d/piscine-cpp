/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:54:47 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/10 17:06:56 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
private:
	
public:
	/*                               ORTHODOX CLASS                           */
	Cat(void);
	Cat(const Cat &copy);
	~Cat(void);
	Cat &operator=(const Cat &copy);

	/*                               METHODS                                  */
	void makeSound(void) const;
};

#endif
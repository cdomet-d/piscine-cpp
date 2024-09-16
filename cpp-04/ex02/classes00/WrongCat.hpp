/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:54:47 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/10 18:06:21 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
	
public:
	/*                               ORTHODOX CLASS                           */
	WrongCat(void);
	WrongCat(const WrongCat &copy);
	~WrongCat(void);
	WrongCat &operator=(const WrongCat &copy);

	/*                               METHODS                                  */
	void makeSound(void) const;
};

#endif

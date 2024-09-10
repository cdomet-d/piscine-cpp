/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:52:58 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/10 18:01:14 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
protected:
	std::string	type;
public:
	/*                               ORTHODOX CLASS                           */
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &copy);
	virtual ~WrongAnimal(void);
	WrongAnimal &operator=(const WrongAnimal &copy);

	/*                               METHODS                                  */
	void makeSound(void) const;
	std::string getType(void) const;
};

#endif

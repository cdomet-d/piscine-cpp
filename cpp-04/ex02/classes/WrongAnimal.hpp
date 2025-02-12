/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:52:58 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:21:05 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
protected:
	std::string type;

public:
	/*                               ORTHODOX CLASS                           */
	WrongAnimal(void);
	WrongAnimal(std::string _type);
	WrongAnimal(const WrongAnimal &rhs);
	virtual ~WrongAnimal(void);
	WrongAnimal &operator=(const WrongAnimal &rhs);

	/*                               METHODS                                  */
	void makeSound(void) const;
	std::string getType(void) const;
};

#endif

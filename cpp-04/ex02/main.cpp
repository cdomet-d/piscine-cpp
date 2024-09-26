/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:14:47 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/26 17:27:27 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#include <iostream>
#include <iomanip>

int main(void)
{
	{
		std::cout << "\n === MINIMUM TESTING ===" << std::endl;
		size_t size = 5;
		Aanimal *zoo[size];
		for (size_t i = 0; i < size; i++)
		{
			if (i % 2)
				zoo[i] = new Cat();
			else
				zoo[i] = new Dog();
		}

		for (size_t i = 0; i < size; i++)
		{
			std::cout << "[ " << std::setw(1) << i + 1 << " ] ";
			std::cout << zoo[i]->getType() << " | ";
			zoo[i]->makeSound();
		}

		for (size_t i = 0; i < size; i++)
			delete zoo[i];
	}
	{
		// This is to prove that the class cannot be instiantiated, since it's abstract | Uncomment to test
		// Aanimal *aclass = new Aanimal;
		// Aanimal aclass_test;
	}
}

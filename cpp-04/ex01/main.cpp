/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:14:47 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/27 11:29:19 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#include <iostream>
#include <iomanip>

#define R "\033[0m" // reset
#define COLOR "\x1b[35m"

int main(void)
{
	{
		std::cout << "\n === MINIMUM TESTING ===" << std::endl;
		size_t size = 5;
		Animal *zoo[size];
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
		std::cout << "\n\n"
				  << std::endl;
		Dog *sandor = new Dog();
		Dog *gregor = new Dog();

		std::cout << COLOR << "created a Dog named Sandor and gave it thoughts\n"
				  << R << std::endl;
		sandor->fillPetArr("i need to kill my sociopathic brother");

		std::cout << COLOR << "created a Dog named Gregor and gave it other thoughts\n"
				  << R << std::endl;
		gregor->fillPetArr("i am a sociopath");

		std::cout << COLOR << "Demonstrating both Dogs have different thoughts\n"
				  << R << std::endl;

		sandor->displayThoughts();
		gregor->displayThoughts();

		std::cout << COLOR << "Using operator=() to assign gregor to Sandor\n"
				  << R << std::endl;
		*gregor = *sandor;

		std::cout << COLOR << "Demonstrating that both Dogs now share the same thoughts but have different brains\n"
				  << R << std::endl;
		sandor->displayThoughts();
		gregor->displayThoughts();
		delete sandor;
		delete gregor;
	}

	{
		std::cout << "\n\n"
				  << std::endl;
		Cat *gregor = new Cat();

		gregor->fillPetArr("I am a sociopath");
		std::cout << COLOR << "created a " << gregor->getType() << " named Gregor with copy constructor\n"
				  << R << std::endl;
		Cat *sandor = new Cat(*gregor);

		std::cout << COLOR << "created a " << sandor->getType() << " named Sandor with copy constructor\n"
				  << R << std::endl;
		
		std::cout << COLOR << "Demonstrating Gregor && Sandor thoughts are the same\n"
				  << R << std::endl;
		sandor->displayThoughts();
		gregor->displayThoughts();

		std::cout << COLOR << "Populating Sandor's thoughts with his own\n"
				  << R << std::endl;
		sandor->fillPetArr("I will kill my mad brother");
		std::cout << COLOR << "Demonstrating deep copy : Sandor and Gregor now have different thoughts\n"
				  << R << std::endl;
		gregor->displayThoughts();
		sandor->displayThoughts();
		delete gregor;
		delete sandor;
	}
}

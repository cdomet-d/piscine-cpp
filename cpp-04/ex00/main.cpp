/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:14:47 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/12 14:03:08 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#include <iostream>
#include <iomanip>

int	main(void)
{
	{
		const Animal *meta = new Animal();
		const Animal *cat = new Cat();
		const Animal *dog = new Dog();
		const WrongAnimal *wrong = new WrongCat();

		std::cout  << std::endl << "|=== Making sounds ===|" << std::endl;
		std::cout << std::setw(15) <<std::left << "Animal";
		meta->makeSound();
		std::cout << std::setw(15) <<std::left << "WrongCat";
		wrong->makeSound();
		std::cout << std::setw(15) <<std::left << "Cat";
		cat->makeSound();
		std::cout << std::setw(15) <<std::left << "Dog";
		dog->makeSound();
		
		std::cout  << std::endl << "|=== Show types ===|" << std::endl;
		std::cout << std::setw(15) <<std::left << "Animal" << meta->getType() << std::endl;
		std::cout << std::setw(15) <<std::left << "WrongCat" << wrong->getType() << std::endl;
		std::cout << std::setw(15) <<std::left << "Cat" << cat->getType() << std::endl;
		std::cout << std::setw(15) <<std::left << "Dog" << dog->getType() << std::endl << std::endl;
		
		delete wrong;
		delete meta;
		delete cat;
		delete dog;
	}
} 
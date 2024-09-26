/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:14:47 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/26 17:18:13 by cdomet-d         ###   ########.fr       */
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
		WrongCat woof;

		std::cout  << std::endl << "|=== Making sounds ===|" << std::endl;
		std::cout << std::setw(15) <<std::left << "Animal";
		meta->makeSound();
		std::cout << std::setw(15) <<std::left << "WrongCat";
		wrong->makeSound();
		std::cout << std::setw(15) <<std::left << "Cat";
		cat->makeSound();
		std::cout << std::setw(15) <<std::left << "Dog";
		dog->makeSound();
		std::cout << std::setw(15) <<std::left << "True WrongCat";
		woof.makeSound();
		
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
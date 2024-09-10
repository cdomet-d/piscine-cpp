/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:14:47 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/10 18:08:28 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#include <iostream>

int	main(void)
{
	const Animal *meta = new Animal();
	const Animal *cat = new Cat();
	const Animal *dog = new Dog();
	const WrongAnimal *wrong = new WrongCat();

	meta->makeSound();
	wrong->makeSound();
	cat->makeSound();
	dog->makeSound();

	std::cout << "Type (animal): " << meta->getType() << std::endl;
	std::cout << "Type (wrong): " << wrong->getType() << std::endl;
	std::cout << "Type (cat): " << cat->getType() << std::endl;
	std::cout << "Type (dog): " << dog->getType() << std::endl;
	
	delete wrong;
	delete meta;
	delete cat;
	delete dog;
	
	return 0;
} 
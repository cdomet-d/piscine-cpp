/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:10:08 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/02 17:08:18 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <ctime>
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Base::~Base(void) {}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

Base *Base::generate()
{
	time_t seed;

	seed = time(0) % 3;

	std::cout << "Seed is: " << seed << std::endl;
	switch (seed)
	{
	case 0:
		std::cout << "Creating A" << std::endl;
		return new A();
	case 1:
		std::cout << "Creating B" << std::endl;
		return new B();
	case 2:
		std::cout << "Creating C" << std::endl;
		return new C();
	default:
		return NULL;
	}

	return this;
}

void Base::identify(Base *p)
{
	std::cout << std::endl;

	std::cout << "dynamic_cast<A *>(p): " << dynamic_cast<A *>(p) << std::endl
			  << "dynamic_cast<B *>(p): " << dynamic_cast<B *>(p) << std::endl
			  << "dynamic_cast<C *>(p): " << dynamic_cast<C *>(p) << std::endl
	<< std::endl;

	if (dynamic_cast<A *>(p))
		std::cout << "in *identify: p points to child class A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "in *identify: p points to child class B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "in *identify: p points to child class C" << std::endl;
	else
		std::cout << "in *identify: An error has occured" << std::endl;
}

void Base::identify(Base &p)
{
	try {
		A test = dynamic_cast<A &>(p);
		std::cout << "in &identify : p points to child class A" << std::endl;
		return;
	} catch (std::exception &e) { }

	try {
		B test = dynamic_cast<B &>(p);
		std::cout << "in &identify : p points to child class B" << std::endl;
		return;
	} catch (std::exception &e) { }

	try {
		C test = dynamic_cast<C &>(p);
		std::cout << "in &identify : p points to child class C" << std::endl;
		return;
	} catch (std::exception &e) { }
	std::cout << "in &identify : An error has occured" << std::endl;

}

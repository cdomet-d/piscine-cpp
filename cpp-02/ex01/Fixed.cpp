/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:02:45 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/08/26 13:09:11 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->raw = 0;
}

Fixed::Fixed(const Fixed &original)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->raw = n << this->exp;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->raw = roundf(n * (1 << this->exp));
}

float Fixed::toFloat(void) const 
{
	return ((float)this->raw / (1 << this->exp));
}

int Fixed::toInt( void ) const 
{
	int r = this->getRawBits() >> this->exp;
	return (r);
}


int Fixed::getRawBits(void) const
{
	return this->raw;
}

void Fixed::setRawBits(int const raw)
{
	this->raw = raw;
}

Fixed::~Fixed() 
{
	std::cout << "Destructor called" << std::endl;
}

// operator overload

std::ostream&	operator<<(std::ostream& os, const Fixed& print)
{
	os << print.toFloat();
	return (os);
}

Fixed& Fixed::operator=(const Fixed &original)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &original)
		this->raw = original.raw;
	return *this;
}

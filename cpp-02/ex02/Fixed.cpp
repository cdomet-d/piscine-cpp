/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:02:45 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/08/22 16:39:04 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

/* ************************************************************************** */
/*                              CONSTRUCTORS                                  */
/* ************************************************************************** */

Fixed::Fixed() {
	this->raw = 0;
}

Fixed::Fixed(const Fixed &original) {
	*this = original;
}

Fixed::Fixed(const int n) {
	this->raw = n << this->exp;
}

Fixed::Fixed(const float n) {
	this->raw = roundf(n * (1 << this->exp));
}

Fixed::~Fixed() {

}

/* ************************************************************************** */
/*                                MEMBERS                                     */
/* ************************************************************************** */

float Fixed::toFloat(void) const {
	return ((float)this->raw / (1 << this->exp));
}

int Fixed::toInt( void ) const {
	int r = this->getRawBits() >> this->exp;
	return r;
}

int Fixed::getRawBits(void) const {
	return this->raw;
}

void Fixed::setRawBits(int const raw) {
	this->raw = raw;
}


/* ************************************************************************** */
/*                                OPERATOR                                    */
/*                                OVERLOAD                                    */
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& os, const Fixed& print) {
	os << print.toFloat();
	return (os);
}

Fixed& Fixed::operator=(const Fixed &original) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &original)
		this->raw = original.raw;
	return *this;
}

bool	Fixed::operator<(const Fixed& comp) const {
	if (this->raw < comp.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed& comp) const {
	if (this->raw > comp.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& comp) const {
	if (this->raw >= comp.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& comp) const {
	if (this->raw <= comp.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& comp) const {
	if  (this->raw == comp.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& comp) const {
	if (this->raw != comp.getRawBits())
		return (true);
	return (false);
}
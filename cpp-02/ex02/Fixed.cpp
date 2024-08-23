/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauseff <jauseff@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:02:45 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/08/23 18:26:43 by jauseff          ###   ########lyon.fr   */
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

/* ************************************************************************** */
/*                                ASSIGNEMENT                                 */
/* ************************************************************************** */

Fixed& Fixed::operator=(const Fixed &original) {
	if (this != &original)
		this->raw = original.raw;
	return *this;
}

/* ************************************************************************** */
/*                                COMPARISON                                  */
/* ************************************************************************** */

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

/* ************************************************************************** */
/*                                INCREMENTATION                              */
/*                                DECREMENTATION                              */
/* ************************************************************************** */

Fixed& Fixed::operator++(void) {
	this->raw++;
	return (*this);
}

Fixed Fixed::operator++(int n) {
	(void)n;
	Fixed old = *this;
	this->raw++;
	return (old);
}

Fixed& Fixed::operator--(void) {
	this->raw--;
	return (*this);
}

Fixed Fixed::operator--(int n) {
	(void)n;
	Fixed old = *this;
	this->raw--;
	return (old);
}

/* ************************************************************************** */
/*                                ARITHMETIC                                  */
/* ************************************************************************** */

Fixed Fixed::operator-(const Fixed& n) const {
	Fixed result;

	result.setRawBits(this->raw - n.getRawBits());
	return result;
}

Fixed Fixed::operator+(const Fixed& n) const {
	Fixed result;

	result.setRawBits(this->raw + n.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed& n) const {
	Fixed result;

	result.setRawBits(this->raw * n.getRawBits());
	result.raw = result.raw >> this->exp;
	return result;
}

Fixed Fixed::operator/(const Fixed& n) const {
	Fixed result;
	if (n == 0)
	{	
		throw std::invalid_argument("Error: cannot divide by 0");
		return result;
	}
	result.setRawBits((this->raw * (1 << this->exp)) / n.getRawBits());
	return result;
}

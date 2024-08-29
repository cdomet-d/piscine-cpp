/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:02:42 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/08/29 14:53:11 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	long long int raw;
	static const int exp = 8;

public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &original);
	Fixed &operator=(const Fixed &original);
	float toFloat(void) const;
	int getRawBits(void) const;
	int toInt(void) const;
	void setRawBits(int const raw);
	~Fixed();
};

std::ostream &operator<<(std::ostream &os, const Fixed &print);
#endif
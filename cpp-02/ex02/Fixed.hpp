/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:02:42 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/08/23 11:44:16 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		long long int		raw;
		static const int	exp = 8;
	public:
		/* Constructors */
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed& original);
		
		/* Members */
		float	toFloat(void) const;
		int		getRawBits(void) const;
		int		toInt( void ) const;
		void	setRawBits(int const raw);

		/* Operator overload */
		// =
		Fixed&	operator=(const Fixed& original);
		// >, <, >=, <=, == et !=
		bool	operator<(const Fixed& comp) const;
		bool	operator>(const Fixed& comp) const;
		bool	operator>=(const Fixed& comp) const;
		bool	operator<=(const Fixed& comp) const;
		bool	operator==(const Fixed& comp) const;
		bool	operator!=(const Fixed& comp) const;
		// +, -, *, et /
		Fixed operator-(const Fixed& n) const;
		Fixed operator+(const Fixed& n) const;
		Fixed operator*(const Fixed& n) const;
		Fixed operator/(const Fixed& n) const;

		// ++, -- 
		Fixed& operator++(void);
		Fixed operator++(int n);
		Fixed& operator--(void);
		Fixed operator--(int n);
		
		/* Destructor */
		~Fixed();
};

std::ostream&	operator<<(std::ostream& os, const Fixed& print);

#endif
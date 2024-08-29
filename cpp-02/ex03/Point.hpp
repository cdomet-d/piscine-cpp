/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauseff <jauseff@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:24:17 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/08/29 10:02:20 by jauseff          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point {
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point(void);
		Point(const float a, const float b);
		Point(const Point& original);
		Point &operator=(const Point& original);
		bool operator==(const Point& comp) const;
		const Fixed getX(void) const;
		const Fixed getY(void) const;
		~Point(void);

};
std::ostream& operator<<(std::ostream& os, const Point& print);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
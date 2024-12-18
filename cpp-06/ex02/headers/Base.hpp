/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:10:13 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/02 15:38:30 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class A;
class B;
class C;

class Base
{
public:
	virtual ~Base();
	Base* generate();
	void identify(Base* p);
	void identify(Base& p);
	
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:14:00 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/02 16:52:35 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int main (void)
{
	Base base;
	Base *ptr = base.generate();

	if (!ptr)
		return 1;
	Base &ref = *ptr;
	base.identify(ptr);
	base.identify(ref);
	delete ptr;
	return 0;
}

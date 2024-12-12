/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:51:48 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/12 17:29:56 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

#define TEST_MUTANT(Container, Type, SubContainer, Instance, Method)         \
	std::cout << std::endl                                                     \
			  << "" #Container "<" #Type ", " #SubContainer "> > " #Instance   \
				 ""                                                            \
			  << std::endl                                                     \
			  << std::endl;                                                    \
	Container< Type, SubContainer< Type > > Instance;                          \
	Instance.Method(5);                                                        \
	Instance.Method(17);                                                       \
	std::cout << Instance.top() << std::endl;                                  \
	Instance.pop();                                                            \
	std::cout << Instance.size() << std::endl;                                 \
	Instance.Method(3);                                                        \
	Instance.Method(5);                                                        \
	Instance.Method(737);                                                      \
	Instance.Method(0);                                                        \
	Container< Type, SubContainer< Type > >::iterator it = Instance.begin();   \
	Container< Type, SubContainer< Type > >::iterator ite = Instance.end();    \
	++it;                                                                      \
	--it;                                                                      \
	while (it != ite) {                                                        \
		std::cout << *it << std::endl;                                         \
		++it;                                                                  \
	}                                                                          \
	std::stack< Type, SubContainer< Type > > s(mstack);

int main(void)
{
	{TEST_MUTANT(MutantStack, int, std::deque, mstack, push);}
	{TEST_MUTANT(MutantStack, int, std::list, mstack, push);}
	{TEST_MUTANT(MutantStack, int, std::vector, mstack, push);}
}

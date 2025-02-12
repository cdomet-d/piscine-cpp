/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:04:29 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:21:05 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>
#include <iostream>

class Serializer
{
public:
	/*                               METHODS                                  */
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);

private:
	/*                               ORTHODOX CLASS                           */
	Serializer(void);
	Serializer(const Serializer &rhs);
	~Serializer(void);
	Serializer &operator=(const Serializer &rhs);
};

#endif

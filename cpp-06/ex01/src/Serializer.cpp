/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:04:34 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:25:02 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer &rhs)
{
	*this = rhs;
}

Serializer::~Serializer(void) {}

Serializer &Serializer::operator=(const Serializer &rhs)
{
	// rhs instructions
	static_cast<void>(rhs);
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}
Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

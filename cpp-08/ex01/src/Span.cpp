/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:07:40 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/06 16:49:07 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Span::Span(void) : trackElem(0), spanSize(0)
{
	span.reserve(0);
}
Span::Span(unsigned int n) : trackElem(0), spanSize(n)
{
	span.reserve(n);
}
Span::Span(const Span &copy)
	: trackElem(copy.trackElem), spanSize(copy.spanSize)
{
	*this = copy;
}

Span::~Span(void)
{
}

Span &Span::operator=(const Span &comp)
{
	this->span = comp.span;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
void Span::addNumber(unsigned int n)
{
	span.push_back(n);
	trackElem += 1;
}

// void Span::fillSpan(unsigned int *values,
// 					std::vector<unsigned int>::iterator begin,
// 					std::vector<unsigned int>::iterator end)
// {
	// std::cout << values + sizeof(values) / sizeof(unsigned int) << std::endl;
	// unsigned long vend = values + sizeof(values) / sizeof(unsigned int);
	unsigned long vi = 0;
	// while (vi < vend) {
	// 	this->addNumber(values[vi]);
	// }
// }

// unsigned int Span::shortestSpan()
// {
// }
// unsigned int Span::longestSpan()
// {
// }

/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */
unsigned int Span::getTrackElem() const
{
	return trackElem;
}

unsigned int Span::getSpanSize() const
{
	return spanSize;
}

std::vector<unsigned int>::iterator Span::getSpanBegin()
{
	return span.begin();
}
std::vector<unsigned int>::iterator Span::getSpanEnd()
{
	return span.end();
}

std::ostream &operator<<(std::ostream &os, const Span &print)
{
	os << "Span size: [" << print.getSpanSize() << "] || Elem in span: ["
	   << print.getTrackElem() << "]";
	return os;
}
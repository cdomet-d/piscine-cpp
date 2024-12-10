/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:07:48 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/10 13:36:25 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span {
  public:
	/*                               ORTHODOX CLASS                           */
	Span(void);
	Span(unsigned int n);
	Span(const Span &copy);
	~Span(void);
	Span &operator=(const Span &copy);

	/*                               METHODS                                  */
	void addNumber(unsigned int n);
	void fillSpan(const std::vector<unsigned int>::iterator pos,
				  std::vector<unsigned int>::iterator begin,
				  std::vector<unsigned int>::iterator end);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	class MaxElemExceeded : public std::exception {
	  public:
		const char *what() const throw();
	};

	/*                               GETTERS                                  */
	unsigned int getTrackElem() const;
	unsigned int getSpanSize() const;
	std::vector<unsigned int>::iterator getSpanBegin();
	std::vector<unsigned int>::iterator getSpanEnd();
	void print();

  private:
	std::vector<unsigned int> span;
	unsigned int trackElem;
	unsigned int spanSize;
};

std::ostream &operator<<(std::ostream &os, const Span &print);

#endif

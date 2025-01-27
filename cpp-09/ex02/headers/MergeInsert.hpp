/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsert.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:40:58 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/27 11:55:21 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGEINSERT_HPP
#define MERGEINSERT_HPP

#include "Timer.hpp"
#include <cstdlib>
#include <stdint.h>
#include <string>

#define PAIR 2

template < template < class, class = std::allocator< int > > class Container >

class MergeInsert {
  public:
	/*                               ORTHODOX CLASS                           */
	MergeInsert(void);
	MergeInsert(const std::string &seq);
	MergeInsert(const MergeInsert &copy);
	MergeInsert &operator=(const MergeInsert &copy);
	~MergeInsert(void);

	/*                               EXCEPTIONS                               */
	class outOfRange : public std::exception {
	  public:
		const char *what() const throw();
	};
	class forbiddenToken : public std::exception {
	  public:
		const char *what() const throw();
	};
	class singleValue : public std::exception {
	  public:
		const char *what() const throw();
	};
	/*                               METHODS                                  */
	void printContainer(
		const Container< Container< int, std::allocator< int > > > &cont);
	void makePairs(Container< Container< int, std::allocator< int > > > &cont);
	void undoPairs(Container< Container< int, std::allocator< int > > > &cont);
	void sortPairs(Container< Container< int, std::allocator< int > > > &cont);
	void addValidValue(const int64_t n, const char *endptr);
	void sort();

  private:
	Container< Container< int, std::allocator< int > > > container;
	uint32_t iSize;
	uint32_t curElemSize;
	Timer clock;
};

#include "MergeInsert.tpp"

#endif

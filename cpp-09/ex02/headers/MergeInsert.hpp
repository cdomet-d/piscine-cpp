/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsert.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:40:58 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/30 11:29:28 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGEINSERT_HPP
#define MERGEINSERT_HPP

#include "SisterTracker.hpp"
#include "Timer.hpp"
#include <cstdlib>
#include <stdint.h>
#include <string>
#include <vector>

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

	// debug
	void printContainer(
		const Container< Container< int, std::allocator< int > > > &cont,
		std::string contName);

	// parsing
	void addValidValue(const int64_t n, const char *endptr);

	// sorting
	void makePairs(Container< Container< int, std::allocator< int > > > &cont);
	void sortPairs(Container< Container< int, std::allocator< int > > > &cont);
	void splitPairs(Container< Container< int, std::allocator< int > > > &cont);
	void fillMain(Container< Container< int, std::allocator< int > > > &cont);
	bool makeElemFromStraggler(
		Container< Container< int, std::allocator< int > > > &cont);
	void merge(Container< Container< int, std::allocator< int > > > &cont);
	void sort();

	// index handling

  private:
	Container< Container< int, std::allocator< int > > > container;
	uint32_t iSize;
	uint32_t curElemSize;
	bool hasStraggler;
	Timer clock;
	SisterTracker aIndex;
};

#include "MergeInsert.tpp"

#endif

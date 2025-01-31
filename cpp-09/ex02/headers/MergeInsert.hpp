/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsert.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:40:58 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/31 17:14:45 by cdomet-d         ###   ########.fr       */
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

template < template < class, class = std::allocator< int > > class Cont >

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
	void printContainer(const Cont< Cont< int, std::allocator< int > > > &cont,
						std::string contName);

	// parsing
	void addValidValue(const int64_t n, const char *endptr);

	// sorting

	Cont< int > halfElemInStraggler(Cont< int > &straggler);
	void binarySearch(size_t maxRange,
					  Cont< Cont< int, std::allocator< int > > > &main,
					  Cont< int > &toInsert);
	void fillMain(Cont< Cont< int, std::allocator< int > > > &cont);
	void makePairs(Cont< Cont< int, std::allocator< int > > > &cont);
	void merge(Cont< Cont< int, std::allocator< int > > > &cont);
	void sort();
	void sortPairs(Cont< Cont< int, std::allocator< int > > > &cont);
	void splitPairs(Cont< Cont< int, std::allocator< int > > > &cont);

	// index handling

  private:
	Cont< Cont< int, std::allocator< int > > > container;
	Cont< int > straggler;
	uint32_t iSize;
	uint32_t curElemSize;
	bool hasStraggler;
	Timer clock;
	SisterTracker aIndex;
};

#include "MergeInsert.tpp"

#endif

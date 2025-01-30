/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SisterTracker.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:23:27 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/30 11:36:18 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SISTERTRACKER_HPP
#define SISTERTRACKER_HPP

#include <stdint.h>
#include <vector>
#include <cstdlib>

class SisterTracker {
  public:
	/*                               ORTHODOX CLASS                           */
	SisterTracker(void);
	~SisterTracker(void);

	/*                               METHODS                                  */
	void updateSister(size_t insertionIndex);
	void printSister();

	/*                               GETTERS                                  */
	size_t getMaxRange(size_t bIndex);

	/*                               SETTER                                   */
	void addIndex(size_t aIndex);


  private:
	SisterTracker(const SisterTracker &copy);
	SisterTracker &operator=(const SisterTracker &copy);
	std::vector< int > sisterIndex;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SisterTracker.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:23:27 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/31 16:45:00 by cdomet-d         ###   ########.fr       */
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
	void update(size_t insertionIndex);
	void print();

	/*                               GETTERS                                  */
	size_t getMaxRange(size_t bIndex);

	/*                               SETTER                                   */
	void add(size_t aIndex);
	void reset();


  private:
	SisterTracker(const SisterTracker &copy);
	SisterTracker &operator=(const SisterTracker &copy);
	std::vector< size_t > sisterIndex;
};

#endif

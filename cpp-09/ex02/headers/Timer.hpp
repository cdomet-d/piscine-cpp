/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Timer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:56:53 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:31:12 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_HPP
#define TIMER_HPP

#include <ctime>

class Timer {
  public:
	/*                               ORTHODOX CLASS                           */
	Timer(void);
	~Timer(void);

	/*                               METHODS                                  */
	void displayTimeElasped() const;

	/*                               SETTERS                                  */
  private:
	std::clock_t start;

	/*                               PRIVATE CONSTRUCTORS                     */
	Timer(const Timer &rhs);
	Timer &operator=(const Timer &rhs);
};

#endif

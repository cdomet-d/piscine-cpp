/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Timer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:56:53 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/15 10:38:53 by cdomet-d         ###   ########lyon.fr   */
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
	void displayTimeElasped();

	/*                               SETTERS                                  */
  private:
	Timer(const Timer &copy);
	Timer &operator=(const Timer &copy);
	std::clock_t start;
};

#endif

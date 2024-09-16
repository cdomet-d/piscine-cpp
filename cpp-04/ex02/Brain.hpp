/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:28:11 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/12 16:09:25 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
private:
	std::string ideas[100];
public:
	/*                               ORTHODOX CLASS                           */
	Brain(void);
	Brain(const Brain &copy);
	~Brain(void);
	Brain &operator=(const Brain &copy);

	/*                               METHODS                                  */
	void fillArr(std::string idea);
	void displayArr(void) const;

	/*                               GETTERS                                  */
	
	/*                               SETTERS                                  */
};

#endif

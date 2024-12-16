/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:42:47 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/16 10:18:05 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HPP
#define INPUT_HPP

#include <map>
#include <string>

class Input {
  public:
	/*                               ORTHODOX CLASS                           */
	Input(void);
	Input(const Input &copy);
	~Input(void);
	Input &operator=(const Input &copy);

	/*                               METHODS                                  */

	/*                               GETTERS                                  */
	// getInput();
	// isInputValid();

	/*                               SETTERS                                  */
  private:
	std::map< std::string, int > input;
};

#endif
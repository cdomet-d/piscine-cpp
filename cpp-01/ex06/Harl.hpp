/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:17:13 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/08/21 10:29:03 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

# define COLOR "\x1B[1;32m"
# define PINK "\x1B[1;31m"
# define END "\033[0m"

# include <string>

enum Complain {
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		void complain( std::string level );
};

#endif
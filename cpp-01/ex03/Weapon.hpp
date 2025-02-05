/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:46:24 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/05 12:36:51 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Implement a Weapon class that has:
// • A private attribute type, which is a string.
// • A getType() member function that returns a const reference to type.
// • A setType() member function that sets type using the new one passed as param-
// eter.

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon{
	private:
		std::string		type;
	public:
		Weapon(void);
		Weapon(std::string _type);
		~Weapon(void);
		const std::string&	getType(void);
		void				display(void);
		void 				setType(const std::string type);
};

#endif

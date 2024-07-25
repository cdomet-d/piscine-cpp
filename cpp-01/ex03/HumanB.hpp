/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:46:18 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/25 17:30:05 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB{
	private:
		std::string	name;
		Weapon*		weapon;
	public:
		HumanB(void);
		HumanB(std::string _name);
		void	attack(void);
		void	setWeapon(Weapon* _weapon);
		~HumanB(void);
};

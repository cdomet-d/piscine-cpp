/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:46:18 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:44:09 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB {
  private:
	std::string name;
	Weapon *weapon;

  public:
	HumanB(void);
	HumanB(std::string _name);
	void attack(void);
	void setWeapon(Weapon &_weapon);
	~HumanB(void);
};

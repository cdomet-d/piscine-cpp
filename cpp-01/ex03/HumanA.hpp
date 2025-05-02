/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:46:12 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:44:15 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// HumanA and HumanB are almost the same except for these two tiny details:
// • While HumanA takes the Weapon in its constructor, HumanB doesn’t.
// • HumanB may not always have a Weapon, whereas HumanA will always be armed

#include "Weapon.hpp"

class HumanA {
  private:
	std::string name;
	Weapon &weapon;

  public:
	HumanA(std::string _name, Weapon &_weapon);
	void attack(void);
	~HumanA(void);
};

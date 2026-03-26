/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   GitHub : @Nave20                                  #+#    #+#             */
/*   28 is the new 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/FragTrap.hpp"
#include "../inc/ScavTrap.hpp"

int main()
{
	ScavTrap test;

	test.attack("Jean");
	test.takeDamage(9);
	test.setEnergy(1);
	test.beRepaired(8);
	test.beRepaired(8);
	test.setEnergy(50);
	test.guardGate();
	test.guardGate();

	FragTrap frag("frag");
	frag.beRepaired(7);
	frag.highFivesGuys();
}

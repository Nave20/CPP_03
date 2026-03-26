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

#include "../inc/ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() : _guardState(0)
{
	std::cout << "Scav Constructor called" << std::endl;
	this->_name = "ScavTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 10;
}

ScavTrap::ScavTrap(std::string name) : _guardState(0)
{
	std::cout << "Scav Constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 10;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << "Scav Copy constructor called" << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	this->_guardState = other._guardState;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		this->_guardState = other._guardState;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scav Destructor called" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout << this->_name << " is out of energy !" << std::endl;
		return;
	}
	this->_energyPoints--;
	if (this->_hitPoints + amount >= 100)
	{
		std::cout << this->_name << " is back to it's prime !" << std::endl;
		this->_hitPoints = 100;
	}
	else
	{
		this->_hitPoints += amount;
		std::cout << this->_name << " is back to "<< this->_hitPoints << " HP !" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	if (this->_guardState == 0)
	{
		std::cout << this->_name <<" is now guarding the gate." << std::endl;
		this->_guardState = 1;
	}
	else
	{
		std::cout << this->_name <<" is no longer guarding the gate." << std::endl;
		this->_guardState = 0;
	}
}

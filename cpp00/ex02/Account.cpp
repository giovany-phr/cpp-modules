/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 21:38:17 by gpaupher          #+#    #+#             */
/*   Updated: 2025/04/28 20:42:46 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./Account.hpp"
# include <iostream>
# include <iomanip>
# include <ctime>
# include <locale>
# include <string>

int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalAmount = 0;
int Account::_nbAccounts = 0;

//**********************************************************//
//****************CONSTRUCTOR DESTRUCTOR*******************//
//********************************************************//

Account::Account() {}

Account::Account(int initial_deposit)
{
	this->_accountIndex = 0;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts;
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"
	<< this->_amount << ";created" << std::endl;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";closed" << std::endl;
}

//**********************************************************//
//***********************GETTER SETTER*********************//
//********************************************************//

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbDeposits()
{
	return (_totalNbDeposits);	
}

int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

//**********************************************************//
//*********************MEMBER FUNCTIONS********************//
//********************************************************//

void	Account::makeDeposit( int deposit )
{
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	_amount += deposit;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";p_amount:" << _amount - deposit
	<< ";deposit:" << deposit
	<< ";amount:"<< _amount
	<< ";nb_deposits:" << _nbDeposits<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > this->_amount)
	{
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";p_amount:" << this->_amount + withdrawal
	<< ";withdrawal:" << withdrawal
	<< ";amount:" << this->_amount
	<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

//**********************************************************//
//**********************************************************//

void	Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
	<< ";total:" << getTotalAmount()
	<< ";deposits:" << getNbDeposits()
	<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"
	<< this->_amount << ";deposits:" << this->_nbDeposits
	<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	char	buffer[42];
	time_t	ji;

	std::time(&ji);
	if (strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", std::localtime(&ji)))
            std::cout << "[" << buffer << "] ";
	// std::cout << "[19920104_091532] "; // quote above unquote here and use diff command on terminal
}
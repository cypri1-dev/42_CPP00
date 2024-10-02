/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:16:41 by cyferrei          #+#    #+#             */
/*   Updated: 2024/10/02 17:19:06 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cctype>
#include <sstream>
#include <string>

int	PhoneBook::stringToInt(std::string& str)
{
	int number;
	std::stringstream ss(str);
	ss >> number;
	return (number);
}

bool	PhoneBook::isValidNumber(std::string index)
{
	int	indexAtoi;
	for(size_t i = 0; i < index.length(); i++)
	{
		if (!std::isdigit(index[i]))
			return (false);
	}
	indexAtoi = stringToInt(index);
	if (indexAtoi >= 0 && indexAtoi <= 7)
	{
		if(!tabContact[indexAtoi].isEmpty())
		{
			std::cout << "Displaying contact at index " << indexAtoi << "..." << std::endl;
			return (true);
		}
		else
		{
			std::cout << "No contact found at this index." << std::endl;
			return (false);
		}
	}
	else
	{
		std::cout << "Index out of range, please enter a number between 0 and 7." << std::endl;
		return (false);
	}
	return (false); 
}

bool	PhoneBook::getInput(std::string& input)
{
	if (!std::getline(std::cin, input))
	{
		std::cout << "\033[31m\nCtrl+D detected\033[0m" << std::endl;
		return(false);
	}
	return (true);
}

// void	PhoneBook::getContactInfos(std::string *infos)
// {
// 	std::string message[5] = {
// 		"Enter first name: ",
// 		"Enter last name: ",
// 		"Enter nickname: ",
// 		"Enter phone number: ",
// 		"Enter darkest secret: ",
// 	};
// 	for (size_t i = 0; i < 5; i++)
// 	{
// 		std::cout << message[i] << std::endl;
// 		std::string buffer;
// 		// this->getInput(buffer);
// 		if(!this->getInput(buffer))
// 			exit(EXIT_FAILURE);
// 		infos[i] = std::string(buffer);
// 	}
// }

void	PhoneBook::displayList()
{
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	for(int i = 0; i < 8; i++)
		this->tabContact[i].print(i);
}

void	PhoneBook::search(void)
{
	this->displayList();
	if (tabContact[0].isEmpty())
	{
		std::cout << "PhoneBook is empty! Please enter at least one contact to use index search" << std::endl;
		return;
	}
	else 
	{
		std::string index;
		std::cout << "Enter an index :" << std::endl;
		std::getline(std::cin, index);
		//add protection;
		if (isValidNumber(index))
		{
			// std::cout << "More comming soon..." << std::endl;
			tabContact[stringToInt(index)].printFullContact(stringToInt(index));
		}
		else
			return;
	}
}

void	PhoneBook::exitPhonebook(void)
{
	std::cout << "Exiting Phonebook!" << std::endl;
	exitRequest = true;
}

void	PhoneBook::add(void)
{
	static size_t contact_number = 0;
	this->tabContact[contact_number % 8].fillInfos();
	contact_number++;
}

void	PhoneBook::run()
{
	this->exitRequest = false;
	static const struct
	{
		std::string keyword;
		void (PhoneBook::*func)(void);
	} 
	selection[] = 
	{
		{ .keyword = "ADD", .func = &PhoneBook::add},
		{ .keyword = "SEARCH", .func = &PhoneBook::search},
		{ .keyword = "EXIT", .func = &PhoneBook::exitPhonebook},
	};
	
	std::cout << "-- My PhoneBook --\n\n" << std::endl;
	while(!this->exitRequest)
	{
		std::cout << "Please, choose from the following choices: ADD, SEARCH or EXIT : ";
		std::string input;
		if (!getInput(input)) 
			break;
		for (size_t i = 0; i < sizeof(selection) / sizeof(selection[0]); i++) {
			if (input == selection[i].keyword) {
				(this->*selection[i].func)();
				continue;
			}
		}
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:39:44 by cyferrei          #+#    #+#             */
/*   Updated: 2024/09/26 15:35:58 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>
#include <iostream>

int main(void)
{
	PhoneBook directory;
	std::string name;
	std::string lastName;
	std::string darkestSecret;
	std::string phoneNumber;
	std::string input;
	std::string answer;

	std::cout << "-- My PhoneBook --\n\n" << std::endl;
	while(1)
	{
		std::cout << "Please, choose from the following choices: ADD, SEARCH or EXIT : ";
		if (!std::getline(std::cin, answer))
		{
			std::cout << "\033[31m\nCtrl+D detected\033[0m" << std::endl;
			break;
		}
		if (answer == "ADD")
			std::cout << "You wrote: " << answer << std::endl;
		else if (answer == "SEARCH")
			std::cout << "You wrote: " << answer << std::endl;
		else if (answer == "EXIT")
		{
			std::cout << "You wrote: " << answer << std::endl;
			exit(EXIT_SUCCESS);
		}
		else
			std::cout << "Wrong choice!" << std::endl;
	}
	return (0);
}
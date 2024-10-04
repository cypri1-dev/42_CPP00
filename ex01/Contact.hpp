/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:28:10 by cyferrei          #+#    #+#             */
/*   Updated: 2024/10/04 16:23:50 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#define BOLD_ON "\033[1m"
#define BOLD_OFF "\033[0m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define GREEN "\033[32m"

#include <iostream>
#include <string> 
#include <cstdlib>
#include <cstdio>

typedef enum {
	FIRSTNAME,
	LASTNAME,
	NICKNAME,
	PHONENUMBER,
	DARKESTSECRET,
} ContactInfos;

class Contact {	
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		Contact() {}; //default constructor
		void	contactReset();
		void	fillInfos();
		bool	isEmpty();
		void	print(size_t index);
		std::string	cut(std::string);
		void	printFullContact(size_t index);
		bool	checkArg(std::string input);
};

#endif
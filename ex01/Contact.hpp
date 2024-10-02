/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:28:10 by cyferrei          #+#    #+#             */
/*   Updated: 2024/10/02 17:14:31 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

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
		void	fillInfos(); //custom constructor
		bool isEmpty();
		void print(size_t index);
		std::string cut(std::string);
		void printFullContact(size_t index);
};

#endif
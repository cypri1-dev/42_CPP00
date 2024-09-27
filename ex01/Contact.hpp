/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:28:10 by cyferrei          #+#    #+#             */
/*   Updated: 2024/09/27 16:38:24 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string> 
#include <cstdlib>

typedef enum {
	NAME,
	LASTNAME,
	PHONENUMBER,
	DARKESTSECRET,
} ContactInfos;

class Contact {	
	private:
		std::string name;
		std::string lastName;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		Contact(); //default constructor
		Contact(std::string *infos); //custom constructor
		bool isEmpty();
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:34:34 by cyferrei          #+#    #+#             */
/*   Updated: 2024/10/04 16:19:05 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact tabContact[8];
		bool getInput(std::string& input);
		void getContactInfos(std::string *infos);
		void add(void);
		void search(void);
		void displayList(void);
		void exitPhonebook(void);
		bool exitRequest;
		bool isValidNumber(std::string index);
		int stringToInt(std::string& str);

	public:
		void run();
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:16:18 by defimova          #+#    #+#             */
/*   Updated: 2025/01/05 15:16:19 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <list>
# include "Contact.hpp"

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

class PhoneBook {
	private:
		Contact contacts[8];
    	int current_index;
		int	contact_cnt;

	public:
    	PhoneBook();
    	PhoneBook(const PhoneBook &a);
    	~PhoneBook();
    	PhoneBook& operator=(const PhoneBook &a);

    	void				add_contact(const Contact &contact);
		Contact 			get_contact(int index) const;
		int					get_contact_cnt() const;
		void				print_phonebook() const;
};

#endif

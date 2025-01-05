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

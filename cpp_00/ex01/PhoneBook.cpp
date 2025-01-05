#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	current_index = 0;
	contact_cnt = 0;
}

PhoneBook::PhoneBook(const PhoneBook &a)
{
	current_index = a.current_index;
    for (int i = 0; i < 8; i++)
	{
    	contacts[i] = a.contacts[i];
    }
}

PhoneBook::~PhoneBook() {}

PhoneBook& PhoneBook::operator=(const PhoneBook &a)
{
    if (this != &a) {
        current_index = a.current_index;
		contact_cnt = a.contact_cnt;
        for (int i = 0; i < 8; i++)
		{
            contacts[i] = a.contacts[i];
        }
    }
    return *this;
}

Contact PhoneBook::get_contact(int index) const 
{
    return contacts[index];
}

int PhoneBook::get_contact_cnt() const
{
	return (contact_cnt);
}

void	PhoneBook::add_contact(const Contact &contact)
{
    contacts[current_index] = contact;
	if (contact_cnt < 7)
		contact_cnt++;
    current_index = (current_index + 1) % 8;
}

void	PhoneBook::print_phonebook() const
{
    std::cout << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname" 
              << std::endl;

    for (int i = 0; i < contact_cnt; i++)
	{
		std::cout
		<< std::setw(10)
		<< i 
		<< "|" 
		<< std::setw(10) 
		<< (this->contacts[i].get_first_name().length() > 10 ? this->contacts[i].get_first_name().substr(0, 9) + "." : this->contacts[i].get_first_name())
		<< "|" 
		<< std::setw(10)
		<< (this->contacts[i].get_last_name().length() > 10 ? this->contacts[i].get_last_name().substr(0, 9) + "." : this->contacts[i].get_last_name())
		<< "|" 
		<< std::setw(10)
		<< (this->contacts[i].get_nickname().length() > 10 ? this->contacts[i].get_nickname().substr(0, 9) + "." : this->contacts[i].get_nickname())
		<< std::endl;
    }
}

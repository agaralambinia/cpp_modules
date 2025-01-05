#include <iostream>
#include <string>
#include <iomanip>

#ifndef CONTACT_H
# define CONTACT_H

class Contact {
	private:
    	std::string first_name;
    	std::string last_name;
    	std::string nickname;
    	std::string phone_number;
    	std::string darkest_secret;

	public:
    	Contact();
    	Contact(const Contact &a);
    	~Contact();
    	Contact& operator=(const Contact &a);
 
		//setters
		void set_first_name(const std::string &name);
		void set_last_name(const std::string &name);
		void set_nickname(const std::string &name);
		void set_phone_number(const std::string &number);
		void set_darkest_secret(const std::string &secret);

		//getters
		std::string get_first_name() const;
		std::string get_last_name() const;
		std::string get_nickname() const;
		std::string get_phone_number() const;
		std::string get_darkest_secret() const;

    	void print_contact() const;
};

#endif

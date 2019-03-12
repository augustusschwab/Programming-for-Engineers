#pragma once
#include <string>
class Contact {
	
	std::string first;
	std::string last;
	std::string num;
	std::string email;

public:
	Contact();
	Contact(std::string _first, std::string _last, std::string _num, std::string _email);
	std::string GetFirstName() const;
	std::string GetLastName() const;
	std::string GetNumber() const;
	std::string GetEmail() const;
};

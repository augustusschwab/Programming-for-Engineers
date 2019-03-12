#include "contact.h"

Contact::Contact(){}

Contact::Contact(std::string _first, std::string _last, std::string _num, std::string _email){
	first = _first;
	last = _last;
	num = _num;
	email = _email;
}

std::string Contact::GetFirstName() const {
	return first;
}

std::string Contact::GetLastName() const {
	return last;
}

std::string Contact::GetNumber() const {
	return num;
}

std::string Contact::GetEmail() const {
	return email;
}

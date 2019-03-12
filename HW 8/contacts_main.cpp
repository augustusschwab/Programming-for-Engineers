#include <iostream>
#include <string>
#include <map>
#include "contact.h"

using namespace std;

void list_contacts(const map<string, Contact>& contacts) {
	if (contacts.size() == 0) { cout << "no contacts\n"; }
	else {
		for (map<string, Contact>::const_iterator it = contacts.begin();
		it != contacts.end(); ++it) {
			cout << it->second.GetLastName() << ", " << it->second.GetFirstName() << "\n";
		}
	}
}

int main() {
		std::string cmd;
		map<string, Contact> contacts;
		do {
			if (cmd == "exit") {
				break;
			}
			else if (cmd == "list") {
				list_contacts(contacts);
			}
			else if (cmd == "add") {
				string first;
				cout << "first name: ";
				cin >> first;
				string last;
				cout << "last name: ";
				cin >> last;
				string num;
				cout << "phone number: ";
				cin >> num;
				string email;
				cout << "e-mail: ";
				cin >> email;
				Contact NewContact(first, last, num, email);
				contacts[last+first] = NewContact;
			}
			else if (cmd == "remove") {
				string first;
				cout << "first name: ";
				cin >> first;
				string last;
				cout << "last name: ";
				cin >> last;
				map<string, Contact>::iterator it;
				it = contacts.find(last+first);
				if (it != contacts.end()) { 
					cout << "removed " << it->second.GetFirstName() << " " << it->second.GetLastName()
						<< "\n";
					contacts.erase(it); 
				}
				else { cout << "contact not found\n"; }

			}
			else if (cmd == "find") {
				string first;
				cout << "first name: ";
				cin >> first;
				string last;
				cout << "last name: ";
				cin >> last;
				auto it = contacts.find(last+first);
				if (it != contacts.end()) {
					cout << "Name: " << it->second.GetFirstName() << " " << it->second.GetLastName() << "\n"
						<< "Phone Number: " << it->second.GetNumber() << "\n"
						<< "E-mail: " << it->second.GetEmail() << "\n";
				}
				else { cout << "contact not found\n"; }
			}
			// Print a terminal prompt so the user knows
			// we're waiting for their input
			std::cout << "> ";
		} while (std::cin >> cmd);
		return 0;
}
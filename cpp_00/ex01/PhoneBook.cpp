#include "PhoneBook.hpp"

void PhoneBook::addContact(const Contact& newContact) {
    contacts_[oldest_index_] = newContact;
    if (contact_count_ < 8) {
        ++contact_count_;
    }
    oldest_index_ = (oldest_index_ + 1) % 8;
}

void PhoneBook::truncateField(std::string& field) const {
    if (field.length() > 10) {
        field.resize(9);
        field += ".";
    }
}

void PhoneBook::displayHeader() const {
    std::cout << std::setw(10) << "Index" << "|" << std::setw(10)
              << "First Name" << "|" << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
}

void PhoneBook::displayContactRow(int index) const {
    std::string firstName = contacts_[index].getFirstName();
    std::string lastName = contacts_[index].getLastName();
    std::string nickName = contacts_[index].getNickName();

    truncateField(firstName);
    truncateField(lastName);
    truncateField(nickName);

    std::cout << std::setw(10) << index << "|" << std::setw(10) << firstName
              << "|" << std::setw(10) << lastName << "|" << std::setw(10)
              << nickName << std::endl;
}

void PhoneBook::searchContacts() const {
    displayHeader();

    for (int i = 0; i < contact_count_; ++i) {
        displayContactRow(i);
    }
}

void PhoneBook::displayContact(int index) const {
    if (index < 0 || index >= contact_count_) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    printContactDetails(contacts_[index]);
}

bool PhoneBook::Run(const std::string& cmd) {
    if (cmd == "ADD") {
        addNewContact();
    } else if (cmd == "SEARCH") {
        searchForContact();
    } else if (cmd == "EXIT") {
        return false;
    } else {
        std::cout << "Unknown command. Please enter ADD, SEARCH, or EXIT."
                  << std::endl;
    }
    return true;
}

void PhoneBook::addNewContact() {
    Contact newContact;
    std::string input;

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    newContact.setFirstName(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    newContact.setLastName(input);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    newContact.setNickName(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    newContact.setPhoneNumber(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    newContact.setDarkestSecret(input);

    addContact(newContact);
}

void PhoneBook::searchForContact() {
    searchContacts();
    std::cout << "Enter the index of the contact to display: ";
    int index;
    std::cin >> index;
    std::cin.ignore();
    displayContact(index);
}

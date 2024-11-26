#include "PhoneBook.hpp"

#include "Contact.hpp"
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

bool PhoneBook::run(const std::string& cmd) {
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

std::string PhoneBook::getValidPhoneNumber() {
    std::string input;
    while (true) {
        std::cout << "Enter phone number (2-16 digits): ";
        std::getline(std::cin, input);
        if (contacts_[0].setPhoneNumber(input)) {
            return input;
        } else {
            std::cout << "Invalid phone number!" << std::endl;
        }
    }
}

std::string PhoneBook::getValidName(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << "Enter " << prompt << ": ";
        std::getline(std::cin, input);
        if (contacts_[0].setFirstName(input)) {
            return input;
        } else {
            std::cout << "Invalid name!" << std::endl;
        }
    }
}

std::string PhoneBook::getValidDarkestSecret() {
    std::string input;
    while (true) {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, input);
        if (contacts_[0].setDarkestSecret(input)) {
            return input;
        }
    }
}

void PhoneBook::addNewContact() {
    Contact newContact;
    newContact.setFirstName(getValidName("name"));
    newContact.setLastName(getValidName("last name"));
    newContact.setNickName(getValidName("nickname"));
    newContact.setPhoneNumber(getValidPhoneNumber());
    newContact.setDarkestSecret(getValidDarkestSecret());
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

void PhoneBook::printContactDetails(const Contact& contact) const {
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickName() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}
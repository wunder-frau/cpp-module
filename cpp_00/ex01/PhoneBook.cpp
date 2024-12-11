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

void PhoneBook::run() {
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) {
            std::cout
                << "\nThis means EOF (Ctrl+D) or error occurred. Exiting..."
                << std::endl;
            break;
        }

        if (command == "ADD") {
            addNewContact();
        } else if (command == "SEARCH") {
            searchForContact();
        } else if (command == "EXIT") {
            break;  // Exit the loop
        } else {
            std::cout << "Unknown command. Please enter ADD, SEARCH, or EXIT."
                      << std::endl;
        }
    }
}

std::string PhoneBook::getValidPhoneNumber() {
    std::string input;
    if (input == "EXIT") {
        return "";
    }
    while (true) {
        std::cout << "Enter phone number (2-16 digits): ";
        if (!std::getline(std::cin, input)) {
            std::cout
                << "\nThis means EOF (Ctrl+D) or error occurred. Exiting..."
                << std::endl;
            return "";
        }
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
        if (!std::getline(std::cin, input)) {
            std::cout
                << "\nThis means EOF (Ctrl+D) or error occurred. Exiting..."
                << std::endl;
            return "";
        }

        if (input == "EXIT") {
            return "";
        }
        if (prompt == "name" && contacts_[0].setFirstName(input)) {
            return input;
        } else if (prompt == "last name" && contacts_[0].setLastName(input)) {
            return input;
        } else if (prompt == "nickname" && contacts_[0].setNickName(input)) {
            return input;
        } else {
            std::cout << "Invalid input for " << prompt << ". Try again.\n";
        }
    }
}

std::string PhoneBook::getValidDarkestSecret() {
    std::string input;
    while (true) {
        std::cout << "Enter darkest secret: ";
        if (!std::getline(std::cin, input)) {
            std::cout
                << "\nThis means EOF (Ctrl+D) or error occurred. Exiting..."
                << std::endl;
            return "";
        }
        if (input == "EXIT") {
            return "";
        }
        if (contacts_[0].setDarkestSecret(input)) {
            return input;
        }
    }
}

void PhoneBook::addNewContact() {
    std::string firstName = getValidName("name");
    if (firstName.empty()) {
        std::cout << "Exiting contact creation..." << std::endl;
        return;
    }

    std::string lastName = getValidName("last name");
    if (lastName.empty()) {
        std::cout << "Exiting contact creation..." << std::endl;
        return;
    }

    std::string nickname = getValidName("nickname");
    if (nickname.empty()) {
        std::cout << "Exiting contact creation..." << std::endl;
        return;
    }

    std::string phoneNumber = getValidPhoneNumber();
    if (phoneNumber.empty()) {
        std::cout << "Exiting contact creation..." << std::endl;
        return;
    }

    std::string secret = getValidDarkestSecret();
    if (secret.empty()) {
        std::cout << "Exiting contact creation..." << std::endl;
        return;
    }

    Contact newContact;
    newContact.setFirstName(firstName);
    newContact.setLastName(lastName);
    newContact.setNickName(nickname);
    newContact.setPhoneNumber(phoneNumber);
    newContact.setDarkestSecret(secret);

    addContact(newContact);
}

void PhoneBook::searchForContact() {
    searchContacts();
    std::cout << "Enter the index of the contact to display: ";
    int index;
    if (!(std::cin >> index)) {
        std::cin.clear();
        std::cout << "\nEOF or invalid input detected. Exiting search...\n";
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    displayContact(index);
}

void PhoneBook::printContactDetails(const Contact& contact) const {
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickName() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}
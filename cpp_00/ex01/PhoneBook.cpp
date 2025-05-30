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

// ===============================
// Display Methods
// ===============================

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

void PhoneBook::printContactDetails(const Contact& contact) const {
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickName() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

// ===============================
// Input Validation Methods
// ===============================

std::string PhoneBook::getValidPhoneNumber() {
    std::string input;
    while (true) {
        std::cout << "Enter phone number (2-16 digits): ";
        if (!std::getline(std::cin, input)) {
            std::cout << "\nEOF (Ctrl+D) or input error detected. Exiting..."
                      << std::endl;
            return "";
        }

        size_t start = input.find_first_not_of(" \t\n\r");
        size_t end = input.find_last_not_of(" \t\n\r");
        if (start == std::string::npos) {
            std::cout
                << "Invalid input! Please enter a valid phone number or 'EXIT'."
                << std::endl;
            continue;
        }
        input = input.substr(start, end - start + 1);

        if (input == "EXIT") {
            return "";
        }

        bool valid = true;
        if (input.length() < 2 || input.length() > 16) {
            valid = false;
        } else {
            for (char c : input) {
                if (!std::isdigit(c)) {
                    valid = false;
                    break;
                }
            }
        }

        if (valid) {
            return input;
        } else {
            std::cout << "Invalid phone number! It must be 2-16 digits."
                      << std::endl;
        }
    }
}

std::string PhoneBook::getValidName(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << "Enter " << prompt << ": ";
        if (!std::getline(std::cin, input)) {
            std::cout << "\nEOF (Ctrl+D) or input error detected. Exiting..."
                      << std::endl;
            return "";
        }

        size_t start = input.find_first_not_of(" \t\n\r");
        size_t end = input.find_last_not_of(" \t\n\r");
        if (start == std::string::npos) {
            std::cout << "Invalid input! Please enter a valid " << prompt
                      << " or 'EXIT'." << std::endl;
            continue;
        }
        input = input.substr(start, end - start + 1);

        if (input == "EXIT") {
            return "";
        }

        size_t firstSpace = input.find(' ');
        if (firstSpace != std::string::npos) {
            input = input.substr(0, firstSpace);
        }

        bool valid = true;
        if (input.empty() || input.length() > 50) {
            valid = false;
        } else {
            for (char c : input) {
                if (!std::isalpha(c) && c != ' ') {
                    valid = false;
                    break;
                }
            }
        }

        if (valid) {
            return input;
        } else {
            std::cout << "Invalid input for " << prompt
                      << ". Please use only alphabetic characters and spaces, "
                         "up to 50 characters."
                      << std::endl;
        }
    }
}

std::string PhoneBook::getValidDarkestSecret() {
    std::string input;
    while (true) {
        std::cout << "Enter darkest secret: ";
        if (!std::getline(std::cin, input)) {
            std::cout << "\nEOF (Ctrl+D) or input error detected. Exiting..."
                      << std::endl;
            return "";
        }

        size_t start = input.find_first_not_of(" \t\n\r");
        size_t end = input.find_last_not_of(" \t\n\r");
        if (start == std::string::npos) {
            std::cout << "Invalid input! Please enter a valid darkest secret "
                      << "or 'EXIT'." << std::endl;
            continue;
        }
        input = input.substr(start, end - start + 1);

        if (input == "EXIT") {
            return "";
        }

        if (!input.empty() && input.length() <= 100) {
            return input;
        } else {
            std::cout << "Invalid input for darkest secret. It must be "
                      << "non-empty and up to 100 characters." << std::endl;
        }
    }
}

// ===============================
// Contact Management Methods
// ===============================

void PhoneBook::addNewContact() {
    std::string firstName = getValidName("first name");
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
    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchForContact() {
    if (contact_count_ == 0) {
        std::cout << "No contacts available to search." << std::endl;
        return;
    }

    searchContacts();
    while (true) {
        std::cout << "Enter the index of the contact to display (0-"
                  << (contact_count_ - 1) << "): ";

        std::string input;
        if (!std::getline(std::cin, input)) {
            std::cout << "\nEOF detected. Exiting search..." << std::endl;
            should_exit_ = true;
            return;
        }

        size_t start = input.find_first_not_of(" \t\n\r");
        size_t end = input.find_last_not_of(" \t\n\r");
        if (start == std::string::npos) {
            std::cout << "Invalid input! Please enter a valid index or 'EXIT'."
                      << std::endl;
            continue;
        }
        input = input.substr(start, end - start + 1);

        if (input == "EXIT") {
            std::cout << "Exiting search..." << std::endl;
            return;
        }

        bool isNumber = true;
        for (char c : input) {
            if (!std::isdigit(c)) {
                isNumber = false;
                break;
            }
        }

        if (!isNumber) {
            std::cout
                << "Invalid input! Please enter a numerical index or 'EXIT'."
                << std::endl;
            continue;
        }

        int index;
        try {
            index = std::stoi(input);
        } catch (const std::invalid_argument&) {
            std::cout << "Invalid input! Please enter a valid number or 'EXIT'."
                      << std::endl;
            continue;
        } catch (const std::out_of_range&) {
            std::cout
                << "Input out of range! Please enter a number between 0 and "
                << (contact_count_ - 1) << "." << std::endl;
            continue;
        }

        if (index < 0 || index >= contact_count_) {
            std::cout << "Invalid index! Please enter a number between 0 and "
                      << (contact_count_ - 1) << "." << std::endl;
            continue;
        }
        displayContact(index);
        return;
    }
}

// ===============================
// Main Loop Method
// ===============================

void PhoneBook::run() {
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) {
            if (!should_exit_) {
                std::cout
                    << "\nThis means EOF (Ctrl+D) or error occurred. Exiting..."
                    << std::endl;
            }
            break;
        }
        size_t start = command.find_first_not_of(" \t\n\r");
        size_t end = command.find_last_not_of(" \t\n\r");
        if (start != std::string::npos) {
            command = command.substr(start, end - start + 1);
        } else {
            command = "";
        }

        if (command == "ADD") {
            addNewContact();
        } else if (command == "SEARCH") {
            searchForContact();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Unknown command. Please enter ADD, SEARCH, or EXIT."
                      << std::endl;
        }

        if (should_exit_) {
            break;
        }
    }
}

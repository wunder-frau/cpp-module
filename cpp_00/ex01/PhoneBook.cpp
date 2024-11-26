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

bool PhoneBook::isValidPhoneNumber(const std::string& number,
                                   std::string& errorMsg) const {
    if (number.empty()) {
        errorMsg = "Number cannot be empty.";
        return false;
    }
    if (number.length() < 2) {
        errorMsg = "Phone number is too short. It must be at least 2 digits.";
        return false;
    }

    if (number.length() > 16) {
        errorMsg =
            "Phone number is too long. It must be no more than 16 digits.";
        return false;
    }

    for (char c : number) {
        if (!std::isdigit(c)) {
            errorMsg = "Phone number must contain digits only.";
            return false;
        }
    }

    errorMsg.clear();
    return true;
}

bool PhoneBook::isValidName(const std::string& name,
                            std::string& errorMsg) const {
    if (name.empty()) {
        errorMsg = "Name cannot be empty.";
        return false;
    }
    for (char c : name) {
        if (!std::isalpha(c) && c != ' ') {
            errorMsg = "Name must contain only apha characters.";
            return false;
        }
    }
    errorMsg.clear();
    return true;
}

std::string PhoneBook::getValidPhoneNumber() const {
    std::string input;
    std::string errorMsg;

    while (true) {
        std::cout << "Enter phone number (2-16 digits): ";
        std::getline(std::cin, input);

        if (isValidPhoneNumber(input, errorMsg)) {
            return input;
        } else {
            std::cout << "Invalid phone number! " << errorMsg << std::endl;
        }
    }
}

std::string PhoneBook::getValidName(const std::string& prompt) const {
    std::string input;
    std::string errorMsg;

    while (true) {
        std::cout << "Enter " << prompt << ": ";
        std::getline(std::cin, input);

        if (isValidName(input, errorMsg)) {
            return input;
        } else {
            std::cout << "Invalid " << prompt << "! " << errorMsg << std::endl;
        }
    }
}

void PhoneBook::addNewContact() {
    Contact newContact;
    std::string input;

    newContact.setFirstName(getValidName("name"));
    newContact.setLastName(getValidName("last name"));
    newContact.setLastName(getValidName("nickname"));
    // std::cout << "Enter nickname: ";
    // std::getline(std::cin, input);
    // newContact.setNickName(input);
    newContact.setPhoneNumber(getValidPhoneNumber());

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

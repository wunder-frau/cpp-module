#pragma once
#include <iomanip>
#include <iostream>
#include <string>

#include "Contact.hpp"

class PhoneBook {
public:
    PhoneBook() : contact_count_(0), oldest_index_(0) {};

    // Public interface methods
    bool run(const std::string& cmd);
    void searchContacts() const;
    void displayContact(int index) const;

private:
    // Core phone book functionality
    void addNewContact();
    void addContact(const Contact& newContact);
    void searchForContact();

    // Display utilities
    void displayHeader() const;
    void displayContactRow(int index) const;
    void truncateField(std::string& field) const;

    // Validation and input utilities
    std::string getValidName(const std::string& prompt) const;
    std::string getValidPhoneNumber() const;
    std::string getValidDarkestSecret() const;
    bool isValidName(const std::string& name, std::string& errorMsg) const;
    bool isValidPhoneNumber(const std::string& number,
                            std::string& errorMsg) const;

    Contact contacts_[8];
    int contact_count_;
    int oldest_index_;
};

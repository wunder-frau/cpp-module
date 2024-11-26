#pragma once
#include <iomanip>
#include <iostream>
#include <string>

#include "Contact.hpp"

class PhoneBook {
public:
    PhoneBook() : contact_count_(0), oldest_index_(0) {};

    bool run(const std::string& cmd);
    void addContact(const Contact& newContact);
    void searchContacts() const;
    void displayContact(int index) const;
    void displayHeader() const;
    void displayContactRow(int index) const;
    void truncateField(std::string& field) const;

private:
    Contact contacts_[8];
    int contact_count_;
    int oldest_index_;

    bool isValidName(const std::string& name, std::string& errorMsg) const;
    bool isValidPhoneNumber(const std::string& number,
                            std::string& errorMsg) const;
    std::string getValidDarkestSecret() const;
    std::string getValidName(const std::string& prompt) const;
    std::string getValidPhoneNumber() const;
    void addNewContact();
    void searchForContact();
};

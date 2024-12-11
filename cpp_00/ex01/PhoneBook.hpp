#pragma once
#include <iomanip>
#include <iostream>
#include <string>

#include "Contact.hpp"

class PhoneBook {
public:
    PhoneBook() : contact_count_(0), oldest_index_(0) {};

    void run();
    void searchContacts() const;
    void displayContact(int index) const;
    void printContactDetails(const Contact& contact) const;

private:
    void addNewContact();
    void addContact(const Contact& newContact);
    void searchForContact();

    void displayHeader() const;
    void displayContactRow(int index) const;
    void truncateField(std::string& field) const;

    std::string getValidName(const std::string& prompt);
    std::string getValidPhoneNumber();
    std::string getValidDarkestSecret();

    Contact contacts_[8];
    int contact_count_;
    int oldest_index_;
};

#pragma once
#include <iomanip>
#include <iostream>
#include <string>

#include "Contact.hpp"

class PhoneBook {
public:
    PhoneBook() : contact_count_(0), oldest_index_(0) {};

    bool Run(const std::string& cmd);
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

    void addNewContact();
    void searchForContact();
};

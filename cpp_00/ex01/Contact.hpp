#pragma once

#include <iostream>

class Contact;

void printContactDetails(const Contact& contact);

class Contact {
    friend void printContactDetails(const Contact& contact);

public:
    const std::string& getFirstName() const { return first_name_; }
    const std::string& getLastName() const { return last_name_; }
    const std::string& getNickName() const { return nick_name_; }
    const std::string& getPhoneNumber() const { return phone_number_; }
    const std::string& getDarkestSecret() const { return secret_; }

    void setFirstName(const std::string& value) { first_name_ = value; }
    void setLastName(const std::string& value) { last_name_ = value; }
    void setNickName(const std::string& value) { nick_name_ = value; }
    void setPhoneNumber(const std::string& value) { phone_number_ = value; }
    void setDarkestSecret(const std::string& value) { secret_ = value; }

private:
    std::string first_name_, last_name_, nick_name_, phone_number_, secret_;
};

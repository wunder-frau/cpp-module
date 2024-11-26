#pragma once
#include <iostream>
#include <string>
class Contact {
public:
    // Getter methods
    const std::string& getFirstName() const { return first_name_; }
    const std::string& getLastName() const { return last_name_; }
    const std::string& getNickName() const { return nick_name_; }
    const std::string& getPhoneNumber() const { return phone_number_; }
    const std::string& getDarkestSecret() const { return secret_; }

    // Setter methods (remove const)
    bool setFirstName(const std::string& value);
    bool setLastName(const std::string& value);
    bool setNickName(const std::string& value);
    bool setPhoneNumber(const std::string& value);
    bool setDarkestSecret(const std::string& value);

private:
    // Private data members
    std::string first_name_, last_name_, nick_name_, phone_number_, secret_;

    // Private validation methods
    bool isValidName(const std::string& name) const;
    bool isValidPhoneNumber(const std::string& number) const;
};

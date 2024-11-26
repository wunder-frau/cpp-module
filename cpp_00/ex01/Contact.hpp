#pragma once
#include <iostream>
#include <string>
class Contact {
public:
    const std::string& getFirstName() const { return first_name_; }
    const std::string& getLastName() const { return last_name_; }
    const std::string& getNickName() const { return nick_name_; }
    const std::string& getPhoneNumber() const { return phone_number_; }
    const std::string& getDarkestSecret() const { return secret_; }

    bool setFirstName(const std::string& value);
    bool setLastName(const std::string& value);
    bool setNickName(const std::string& value);
    bool setPhoneNumber(const std::string& value);
    bool setDarkestSecret(const std::string& value);

private:
    std::string first_name_, last_name_, nick_name_, phone_number_, secret_;

    bool isValidName(const std::string& name) const;
    bool isValidPhoneNumber(const std::string& number) const;
};

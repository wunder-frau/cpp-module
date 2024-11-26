#include "Contact.hpp"

#include "PhoneBook.hpp"

bool Contact::setFirstName(const std::string& value) {
    if (!isValidName(value))
        return false;
    first_name_ = value;
    return true;
}

bool Contact::setLastName(const std::string& value) {
    if (!isValidName(value))
        return false;
    last_name_ = value;
    return true;
}

bool Contact::setNickName(const std::string& value) {
    if (!isValidName(value))
        return false;
    nick_name_ = value;
    return true;
}

bool Contact::setPhoneNumber(const std::string& value) {
    if (!isValidPhoneNumber(value))
        return false;
    phone_number_ = value;
    return true;
}

bool Contact::setDarkestSecret(const std::string& value) {
    if (value.empty() || value.length() > 100) {
        return false;
    }
    secret_ = value;
    return true;
}

bool Contact::isValidName(const std::string& name) const {
    if (name.empty())
        return false;
    for (char c : name) {
        if (!std::isalpha(c) && c != ' ')
            return false;
    }
    return true;
}

bool Contact::isValidPhoneNumber(const std::string& number) const {
    if (number.empty() || number.length() < 2 || number.length() > 16)
        return false;
    for (char c : number) {
        if (!std::isdigit(c))
            return false;
    }
    return true;
}

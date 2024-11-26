#include "Contact.hpp"

bool Contact::setFirstName(const std::string& value) {
    std::string errorMsg;
    if (value.empty()) {
        errorMsg = "Name cannot be empty!";
        std::cout << errorMsg << std::endl;
        return false;
    } else if (value.length() > 50) {
        errorMsg = "First name is too long! Maximum length is 50 characters.";
        std::cout << errorMsg << std::endl;
        return false;
    }
    first_name_ = value;
    return true;
}

bool Contact::setLastName(const std::string& value) {
    std::string errorMsg;
    if (value.empty()) {
        errorMsg = "Last name cannot be empty!";
        std::cout << errorMsg << std::endl;
        return false;
    } else if (value.length() > 50) {
        errorMsg = "Last name is too long! Maximum length is 50 characters.";
        std::cout << errorMsg << std::endl;
        return false;
    }
    last_name_ = value;
    return true;
}

bool Contact::setNickName(const std::string& value) {
    std::string errorMsg;
    if (value.empty()) {
        errorMsg = "Nickname cannot be empty!";
        std::cout << errorMsg << std::endl;
        return false;
    } else if (value.length() > 50) {
        errorMsg = "Nickname is too long! Maximum length is 50 characters.";
        std::cout << errorMsg << std::endl;
        return false;
    }
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
    std::string errorMsg;
    if (value.empty()) {
        errorMsg = "Darkest secret cannot be empty!";
        std::cout << errorMsg << std::endl;
        return false;
    } else if (value.length() > 50) {
        errorMsg =
            "Darkest secret is too long! Maximum length is 50 characters.";
        std::cout << errorMsg << std::endl;
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

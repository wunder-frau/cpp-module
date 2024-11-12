#include "Contact.hpp"

void printContactDetails(const Contact &contact) {
    std::cout << "First Name: " << contact.first_name_ << '\n'
              << "Last Name: " << contact.last_name_ << '\n'
              << "Nickname: " << contact.nick_name_ << '\n'
              << "Phone Number: " << contact.phone_number_ << '\n'
              << "Darkest Secret: " << contact.secret_ << std::endl;
}

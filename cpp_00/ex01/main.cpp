#include <iostream>

#include "Contact.hpp"

int main() {
    Contact contact;
    contact.setFirstName("John");
    contact.setLastName("Doe");
    contact.setNickname("Johnny");
    contact.setPhoneNumber("123456789");
    contact.setDarkestSecret("Afraid of heights");

    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;

    return 0;
}

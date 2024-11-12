#include "Contact.hpp"

int main() {
    Contact contact;

    contact.setFirstName("John");
    contact.setLastName("Doe");
    contact.setNickName("Johnny");
    contact.setPhoneNumber("123-456-7890");
    contact.setDarkestSecret("I love programming!");

    printContactDetails(contact);

    std::cout << "Nickname: " << contact.getNickName() << std::endl;

    return 0;
}

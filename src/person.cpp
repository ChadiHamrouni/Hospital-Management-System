#include <iostream>
#include "../header/person.h"

Person::Person(std::string PersonId, std::string FullName, std::string PhoneNumber)
{
    personId = PersonId;
    fullName = FullName;
    phoneNumber = PhoneNumber;
}

void Person::getInfo()
{
    std::cout << "PersonID: " << personId << std::endl;
    std::cout << "Full Name: " << fullName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
}

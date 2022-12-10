#ifndef PERSON_H
#define PERSON_H
#include <iostream>
class Person
{
public:
    std::string personId;
    std::string fullName;
    std::string phoneNumber;

    Person(std::string PersonId, std::string FullName, std::string PhoneNumber);
    void getInfo();
};

#endif

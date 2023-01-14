#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person{
protected:
    std::string personId;
    std::string fullName;
    std::string phoneNumber;

public:
    Person(std::string PersonId, std::string FullName, std::string PhoneNumber);
    Person(std::string PersonId, std::string FullName);
    void getPersonInfo();
    void archives(Person person);
};

#endif

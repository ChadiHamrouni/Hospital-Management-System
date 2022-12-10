#include<iostream>
#include "../header/admin.h"
#include "../header/person.h"

Admin::Admin(std::string PersonId, std::string FullName, std::string PhoneNumber, std::string Username, std::string Password) : Person(PersonId, FullName, PhoneNumber)
{
    username = Username;
    password = Password;
}

void Admin::getPersonDetails()
{
    std::cout << "Person ID: " << personId << std::endl;
    std::cout << "Full Name: " << fullName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Username: " << username << std::endl;
    std::cout << "Password: " << password << std::endl;
}
void Admin::viewAdmins() {}
void Admin::chooseRoom() {}
void Admin::viewDepartments() {}
void Admin::viewRooms() {}


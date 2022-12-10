#ifndef ADMIN_H
#define ADMIN_H
#include "person.h"

class Admin : public Person
{
protected:
    std::string username;
    std::string password;

public:
    Admin(std::string PersonId, std::string FullName, std::string PhoneNumber, std::string Username, std::string Password);
    void getPersonDetails();
    void viewAdmins();
    // bool searchPatient(std::string ID) {}
    void chooseRoom();
    void viewDepartments();
    void viewRooms();
};

#endif

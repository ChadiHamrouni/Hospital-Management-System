#ifndef ADMIN_H
#define ADMIN_H

#include "person.h"
#include "doctor.h"

class Admin : public Person{
protected:
    std::string username;
    std::string password;

public:
    Admin(std::string PersonId, std::string FullName, std::string PhoneNumber, std::string Username, std::string Password);
    void getAdminDetails();
    void search();
    void displayProfile();
    void displaySettings(ImGuiIO& io);
    void doctorRequestHeader();
    void doctorRequest();
    void displayArchivesHeader();
    void dashBoardStats(ImFont* font);
    void latestAppointment();
    void futureAppointments();
    void currentOnCallDoctors(Doctor doc);
    void currentRegularDoctors(Doctor doc);
    void addDoctorForm();
    void addPatientForm();
};

#endif

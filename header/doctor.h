#ifndef DOCTOR_H
#define DOCTOR_H

#include "person.h"

class Doctor : protected Person{
protected:
    std::string department;
    std::string status;
    std::string address;
    std::string qualification;

public:
    Doctor(std::string PersonId, std::string FullName, std::string PhoneNumber, std::string Department, std::string Status, std::string Address, std::string Qualification);
    Doctor(std::string PersonId, std::string FullName, std::string Department, std::string Status);
        
    void getDoctorDetails(Doctor doc);
    void doctorList(Doctor doc);
    void doctorListColorless(Doctor doc);
};


#endif
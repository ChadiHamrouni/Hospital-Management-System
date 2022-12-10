#ifndef DOCTOR_H
#define DOCTOR_H
#include "person.h"
#include <iostream>

class Doctor : public Person
{
public:
    std::string department;
    std::string status;
    std::string address;
    std::string qualification;

public:
    Doctor(std::string PersonId, std::string FullName, std::string PhoneNumber, std::string Department, std::string Status, std::string Address, std::string Qualification);
    void dischargePatient(std::string patientId);
    void getDoctorDetails(Doctor d);
};

#endif
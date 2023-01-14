#ifndef PATIENT_H
#define PATIENT_H

#include "person.h"

class Patient : protected Person{
protected:
    int entryNumber;
    int age;
    std::string sex;
    std::string address;
    std::string city;
    std::string entrydate;
    std::string doctorRefferedTO;
    std::string diagnosis;
    std::string department;

public:    
    Patient(std::string PersonId, std::string FullName, std::string PhoneNumber,        
        int EntryNumber,
        int Age,
        std::string Sex,
        std::string Address,
        std::string City,
        std::string EntryDate,
        std::string DoctorRefferedTo,
        std::string Diagnosis,
        std::string Department);

        void getPatientDetails(Patient pat);
        void patientHeader();
        void patientList(Patient pat);        
};

#endif
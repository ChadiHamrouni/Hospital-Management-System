#include <string>
#include <iostream>
#include "../header/patient.h"
//#include <fstream>
#include <string.h>
//std::fstream myFile;

    Patient::Patient(std::string Id, std::string FullName, std::string PhoneNumber) {
        id = Id;
        fullName = FullName;
        phoneNumber = PhoneNumber;
    }

/*    Patient::Patient(std::string PersonId, std::string FullName, std::string PhoneNumber, int Age, char Sex, std::string Address, std::string City, std::string EntryDate, int EntryNumber, std::string DoctorRefferedTo, std::string Diagnosis, std::string Department)
        : Person(PersonId, FullName, PhoneNumber)
    {
        age = Age;
        sex = Sex;
        address = Address;
        city = City;
        entrydate = EntryDate;
        entryNumber = EntryNumber;
        doctorRefferedTO = DoctorRefferedTo;
        diagnosis = Diagnosis;
        department = Department;
    }*/

/*bool searchPatient(std::string ID)
{  
myFile.open("../data/Patient.txt", std::ios::in);
    if (myFile.is_open())
         {
             std::string line;
             while (getline(myFile, line))
             {
                 int res = line.compare(ID);
                 if (res == 0)
                     return true; // equal
                 return false;
             }
             myFile.close();
             std::cout << "test if code reaches here";
         }
}*/
     
/*void registerPatient(Patient p)
{
    myFile.open("../data/Patient.txt", std::ios::app);
         if (myFile.is_open())
         {
             if (searchPatient(p.personId) == false)
             {
                 myFile << personId << "\n"
                        << fullName << "\n"
                        << phoneNumber << "\n"
                        << age << "\n"
                        << sex << "\n"
                        << address << "\n"
                        << city << "\n"
                        << entrydate << "\n"
                        << entryNumber << "\n"
                        << doctorRefferedTO << "\n"
                        << diagnosis << "\n"
                        << department << "\n"
                        << endl;
                 myFile.close();
             }
             else
             {
                 std::cout << "This patient has already been added!" << endl;
             }
         }
}*/

/*void Patient::getPatientDetails()
    {
        std::cout << "Full Name: " << fullName << endl;
        std::cout << "Phone Number: " << phoneNumber << endl;
        std::cout << "Age: " << age << endl;
        std::cout << "Sex: " << sex << endl;
        std::cout << "Address: " << address << endl;
        std::cout << "City: " << city << endl;
        std::cout << "Entry Date: " << entrydate << endl;
        std::cout << "Entry Number: " << entryNumber << endl;
        std::cout << "Doctor reffered to: " << doctorRefferedTO << endl;
        std::cout << "Diagnosis: " << diagnosis << endl;
        std::cout << "Department: " << department << endl;
}*/

class AdmittedPatient : public Patient
{
private:
        std::string initialCondition;
        std::string roomNumber;
};

class RegularPatient : public Patient
{
private:
        std::string medicineRecommended;
        // date dateOfVisit;
        std::string statusOfTreatment;
};

class DischargedPatient : public Patient
{
private:
        // date dateOfDischarge;
        std::string treatmentAdvice;
        std::string treatmentGiven;
        std::string paymentDue;
};

class PatientCheckUp
{
private:
        Patient patient;
        //  Doctor doctor;
        std::string status;
        // date dateOfCheckup;
        std::string diagnosis;
        std::string treatment;
};

class PatientOperation
{
private:
        Patient patient;
        // Doctor doctor;
        //   date operationDate;
        std::string operationType;
        std::string patientConditionPre;
        std::string patientConditionPost;
        std::string treatmentAdvice;
        std::string operationTheater;
};

class Card
{
private:
        std::string cardId;
};


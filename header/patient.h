#ifndef PATIENT_H
#define PATIENT_H
#include <fstream>
#include "person.h"
//std::fstream myFile;

class Patient {
public:
    std::string id;
    std::string fullName;
    std::string phoneNumber;

    Patient(std::string Id, std::string FullName, std::string PhoneNumber);
};

/*class Patient : public Person
{
public:
    int age;
    char sex;
    std::string address;
    std::string city;
    std::string entrydate;
    int entryNumber;
    std::string doctorRefferedTO;
    std::string diagnosis;
    std::string department;

public:
    Patient(std::string PersonId, std::string FullName, std::string PhoneNumber, int Age, char Sex, std::string Address, std::string City, std::string EntryDate, int EntryNumber, std::string DoctorRefferedTo, std::string Diagnosis, std::string Department);

      bool searchPatient(std::string ID)
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
          }
      }

      void registerPatient()
      {
          myFile.open("../data/Patient.txt", ios::app);
          if (myFile.is_open())
          {
              if (searchPatient(personId) == false)
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
                  cout << "This patient has already been added!" << endl;
              }
          }
      }

void getPatientDetails();
};*/

#endif
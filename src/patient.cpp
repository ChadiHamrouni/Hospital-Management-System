#include <iostream>
#include "imgui.h"

#include "../header/patient.h"
#include "../header/doctor.h"

Patient::Patient(std::string PersonId, std::string FullName, std::string PhoneNumber,
    int EntryNumber,
    int Age,
    std::string Sex,
    std::string Address,
    std::string City,
    std::string EntryDate,
    std::string DoctorRefferedTo,
    std::string Diagnosis,
    std::string Department) : Person(PersonId, FullName, PhoneNumber){

    age = Age;
    sex = Sex;
    address = Address;
    city = City;
    entrydate = EntryDate;
    entryNumber = EntryNumber;
    doctorRefferedTO = DoctorRefferedTo;
    diagnosis = Diagnosis;
    department = Department;
}

void Patient::getPatientDetails(Patient p){   
    std::cout << "ID: " << p.personId << std::endl;
    std::cout << "Full Name: " << p.fullName << std::endl;
    std::cout << "Phone Number: " << p.phoneNumber << std::endl;
    std::cout << "Entry Number: " << p.entryNumber << std::endl;
    std::cout << "Age: " << p.age << std::endl;
    std::cout << "Sex: " << p.sex << std::endl;
    std::cout << "Address: " << p.address << std::endl;
    std::cout << "City: " << p.city << std::endl;
    std::cout << "Entry Date: " << p.entrydate << std::endl;
    std::cout << "Doctor reffered to: " << p.doctorRefferedTO << std::endl;
    std::cout << "Diagnosis: " << p.diagnosis << std::endl;
    std::cout << "Department: " << p.department << std::endl;
}

void Patient::patientHeader() {
    ImGui::TableNextRow();
    ImGui::TableNextColumn();
    ImGui::Text("ID");
    ImGui::TableNextColumn();
    ImGui::Text("FULL NAME");
    ImGui::TableNextColumn();
    ImGui::Text("PHONE NUMBER");
    ImGui::TableNextColumn();
    ImGui::Text("ENTRY NUMBER");
    ImGui::TableNextColumn();
    ImGui::Text("AGE");
    ImGui::TableNextColumn();
    ImGui::Text("SEX");
    ImGui::TableNextColumn();
    ImGui::Text("ADDRESS");
    ImGui::TableNextColumn();
    ImGui::Text("CITY");
    ImGui::TableNextColumn();
    ImGui::Text("ENTRY DATE");
    ImGui::TableNextColumn();
    ImGui::Text("REFFERED TO");
    ImGui::TableNextColumn();
    ImGui::Text("DIAGNOSIS");
    ImGui::TableNextColumn();
    ImGui::Text("DEPARTMENT");
}

void Patient::patientList(Patient p){
    ImGui::TableNextRow();
    ImGui::TableNextColumn();
    ImGui::Text(p.personId.c_str());
    ImGui::TableNextColumn();
    ImGui::Text(p.fullName.c_str());
    ImGui::TableNextColumn();
    ImGui::Text(p.phoneNumber.c_str());
    ImGui::TableNextColumn();
    std::string entryN = std::to_string(p.entryNumber);
    ImGui::Text(entryN.c_str());
    ImGui::TableNextColumn();
    std::string age = std::to_string(p.age);
    ImGui::Text(age.c_str());
    ImGui::TableNextColumn();
    ImGui::Text(p.sex.c_str());
    ImGui::TableNextColumn();
    ImGui::Text(p.address.c_str());
    ImGui::TableNextColumn();
    ImGui::Text(p.city.c_str());
    ImGui::TableNextColumn();
    ImGui::Text(p.entrydate.c_str());
    ImGui::TableNextColumn();
    ImGui::Text(p.doctorRefferedTO.c_str());
    ImGui::TableNextColumn();
    ImGui::Text(p.diagnosis.c_str());
    ImGui::TableNextColumn();
    ImGui::Text(p.department.c_str());
}







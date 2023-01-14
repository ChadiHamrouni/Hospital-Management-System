#include <iostream>
#include "imgui.h"

#include "../header/person.h"

Person::Person(std::string PersonId, std::string FullName, std::string PhoneNumber){
    personId = PersonId;
    fullName = FullName;
    phoneNumber = PhoneNumber;
}

Person::Person(std::string PersonId, std::string FullName){
	personId = PersonId;
	fullName = FullName;
}

void Person::getPersonInfo(){
    std::cout << "PersonID: " << personId << std::endl;
    std::cout << "Full Name: " << fullName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
}

void Person::archives(Person person){
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
	ImGui::Text(person.personId.c_str());
	ImGui::TableNextColumn();
	ImGui::Text(person.fullName.c_str());
	ImGui::TableNextColumn();
	ImGui::Text(person.phoneNumber.c_str());
}
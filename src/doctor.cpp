#include <iostream>
#include "imgui.h"

#include "../header/doctor.h"

Doctor::Doctor(std::string PersonId, std::string FullName, std::string PhoneNumber, std::string Department, std::string Status, std::string Address, std::string Qualification) : Person(PersonId, FullName, PhoneNumber){   
    department = Department;
    status = Status;
    address = Address;
    qualification = Qualification;
}

Doctor::Doctor(std::string PersonId, std::string FullName, std::string Department, std::string Status) : Person(PersonId, FullName){
	department = Department;
	status = Status;
}

void Doctor::getDoctorDetails(Doctor doc){
    std::cout << "Full Name: " << doc.fullName << std::endl;
    std::cout << "Phone Number: " << doc.phoneNumber << std::endl;
    std::cout << "Department: " << doc.department << std::endl;
    std::cout << "Status: " << doc.status << std::endl;
    std::cout << "Address: " << doc.address << std::endl;
    std::cout << "Qualification: " << doc.qualification << std::endl;
}

void Doctor::doctorList(Doctor doc) {
	ImVec4 red = ImColor(127, 4, 38, 255);
	ImU32 select_color = ImColor(red);
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
	ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, select_color);
	ImGui::Text(doc.personId.c_str());

	ImGui::TableNextColumn();

	ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, select_color);
	ImGui::Text(doc.fullName.c_str());

	ImGui::TableNextColumn();

	ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, select_color);
	ImGui::Text(doc.department.c_str());

	ImGui::TableNextColumn();

	ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, select_color);
	ImGui::Text(doc.status.c_str());
}

void Doctor::doctorListColorless(Doctor doc) {
	ImGui::TableNextRow();
	ImGui::TableNextColumn();
	ImGui::Text(doc.personId.c_str());
	ImGui::TableNextColumn();
	ImGui::Text(doc.fullName.c_str());
	ImGui::TableNextColumn();
	ImGui::Text(doc.department.c_str());
	ImGui::TableNextColumn();
	ImGui::Text(doc.status.c_str());
}


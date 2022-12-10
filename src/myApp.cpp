#include <iostream>
#include "string"
#include "imgui.h"
#include "../myApp.h"
#include "../header/patient.h"
#include "../header/doctor.h"
#include "../header/department.h"
#include "imgui_internal.h"

namespace myApp {

	void Patients(Patient p) {
		ImGui::TableNextRow();
		ImGui::Separator();
		ImGui::TableNextColumn();
		ImGui::Separator();
		ImGui::Text(p.id.c_str());
		ImGui::Separator();
		ImGui::TableNextColumn();
		ImGui::Separator();
		ImGui::Text(p.fullName.c_str());
		ImGui::Separator();
		ImGui::TableNextColumn();
		ImGui::Separator();
		ImGui::Text(p.phoneNumber.c_str());
		ImGui::Separator();
	}
	void Doctors(Doctor doc) {
		ImGui::TableNextRow();
		ImGui::Separator();
		ImGui::TableNextColumn();
		ImGui::Separator();
		ImGui::Text(doc.personId.c_str());
		ImGui::Separator();
		ImGui::TableNextColumn();
		ImGui::Separator();
		ImGui::Text(doc.fullName.c_str());
		ImGui::Separator();
		ImGui::TableNextColumn();
		ImGui::Separator();
		ImGui::Text(doc.phoneNumber.c_str());
		ImGui::Separator();
		ImGui::TableNextColumn();
		ImGui::Separator();
		ImGui::Text(doc.department.c_str());
		ImGui::Separator();
		ImGui::TableNextColumn();
		ImGui::Separator();
		ImGui::Text(doc.status.c_str());
		ImGui::Separator();
		ImGui::TableNextColumn();
		ImGui::Separator();
		ImGui::Text(doc.address.c_str());
		ImGui::Separator();
		ImGui::TableNextColumn();
		ImGui::Separator();
		ImGui::Text(doc.qualification.c_str());
		ImGui::Separator();
	}
	void Departments(Department depart) {
		ImGui::TableNextRow();
		ImGui::Separator();
		ImGui::TableNextColumn();
		ImGui::Separator();
		ImGui::Text(depart.name.c_str());
		ImGui::Separator();
		ImGui::TableNextColumn();
		ImGui::Separator();
		ImGui::Text(depart.load.c_str());
		ImGui::Separator();
		ImGui::TableNextColumn();
		ImGui::Separator();
		ImGui::Text(depart.facilities.c_str());
		ImGui::Separator();
	}
	void Archives(Person per) {
		ImGui::TableNextRow();
		ImGui::Separator();
		ImGui::TableNextColumn();
		ImGui::Separator();
		ImGui::Text(per.personId.c_str());
		ImGui::Separator();
		ImGui::TableNextColumn();
		ImGui::Separator();
		ImGui::Text(per.fullName.c_str());
		ImGui::Separator();
		ImGui::TableNextColumn();
		ImGui::Separator();
		ImGui::Text(per.phoneNumber.c_str());
		ImGui::Separator();
	}
}





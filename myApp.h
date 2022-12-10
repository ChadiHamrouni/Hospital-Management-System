#pragma once
#include <string>
#include "./header/patient.h"
#include "./header/doctor.h"
#include "./header/department.h"
#include "./header/person.h"
namespace myApp {
	
	void Patients(Patient p);
	void Doctors(Doctor d);
	void Departments(Department depart);
	void Archives(Person per);
}

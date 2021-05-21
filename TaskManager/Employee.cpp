#include "Employee.hpp"
using namespace std;



string Employee::getEmployeeName() {
	return employeeName;
}

int Employee::getEmployeeId() {
	return employeeId;
}

int* Employee::getEmployeeWorkingHours(int day) {
	return employeeWorkingHours;
}

int Employee::getEmployeeTask() {
	return employeeTask;
}

void Employee::setEmployeeName(string newEmployeeName) {
	this->employeeName = newEmployeeName;
}

void Employee::setEmployeeId(int newEmployeeId) {
	this->employeeId = newEmployeeId;
}

void Employee::setEmployeeWorkingHours(int day, int hoursNum) {
	this->employeeWorkingHours[day] = hoursNum;
}

void Employee::setEmployeeTask(int newEmployeeTask) {
	this->employeeTask = newEmployeeTask;
}


ostream& operator<<(ostream& out, const Employee& it) {
	out << it.employeeName << endl;
	out << it.employeeId << " ";
	for (int i = 0; i < 7; i++) {
		out << it.employeeWorkingHours[i] << " ";
	}
	out << it.employeeTask;
}
//friend istream& operator>> (istream& in, Employee& it);

// is it necessary to compare employeeWorkingHours?
bool operator==(Employee& l, Employee& r) {
	return l.employeeId == r.employeeId && l.employeeName == r.employeeName && l.employeeTask == r.employeeTask;
}
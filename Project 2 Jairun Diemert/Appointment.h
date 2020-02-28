//File: Appointment.h
//Author: Jairun Diemert
//Class: COP3014
//Project: 2
//Description: This is the header file for the Appointment class.

#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include <string>
using namespace std;

class Appointment {
public:
	Appointment();
	Appointment(int timeScheduled, string patientName);
	int GetTimeScheduled();
	string GetPatientName();
	void SetPatientName(string patientName);
	void SetTimeScheduled(int timeScheduled);
	void AppointmentSchedular(string patientName, int timeScheduled, string doctorName);
	int DoctorLocator(string searchNameD);
	bool ScheduleOpen(int timeScheduled, int arrayLocationD);
	void ScheduleAppointment(int arrayLocationD, int timeScheduled, string patientName);
	void PrintPatients();
	void PrintDoctors();
	void PrintDoctorsANDAppointment();
	bool MenuPrompt();
	void RemoveAppointment(string doctor, int time);
	void CheckIfAppointmentOpen(string doctor, int time);
private:
	string patientNameP = "Empty";
	int timeScheduledP = 0;
};
#endif 
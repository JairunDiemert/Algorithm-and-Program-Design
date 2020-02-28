//File: Appointment.cpp
//Author: Jairun Diemert
//Class: COP3014
//Project: 2
//Description: This is the member function file for Appointment. 

#include <iostream>
#include<string>
using namespace std;

#include "PatientList.h"
#include "DoctorList.h"
#include "Appointment.h"

Appointment::Appointment()
{

};
Appointment::Appointment(int timeScheduled, string patientName)
{
	patientNameP = patientName;
	timeScheduledP = timeScheduled;
};
int Appointment::GetTimeScheduled()
{
	return timeScheduledP;
};
string Appointment::GetPatientName()
{
	return patientNameP;
}
void Appointment::SetPatientName(string patientName)
{
	patientNameP = patientName;
};
void Appointment::SetTimeScheduled(int timeScheduled)
{
	timeScheduledP = timeScheduled;
};
int Appointment::DoctorLocator(string searchNameD)
{
	for (int i = 0; i < DoctorList::size + 1; i++)
	{
		if (DoctorList::doctors[i].GetNameD() == searchNameD)
		{
			return i;
		}
	}
};
void Appointment::PrintPatients()
{
	for (int i = 0; i < PatientList::size; i++)
	{
		cout << "Name: " << PatientList::patients[i].GetNameP()
			<< ", Age: " << PatientList::patients[i].GetAgeP()
			<< ", Sex: " << PatientList::patients[i].GetSexP() << endl;
	}
};
void Appointment::PrintDoctors()
{
	for (int i = 0; i < DoctorList::size; i++)
	{
		cout << "Name: " << DoctorList::doctors[i].GetNameD()
			<< ", Age: " << DoctorList::doctors[i].GetAgeD()
			<< ", Specialty: " << DoctorList::doctors[i].GetSpecialtyD() << endl;
	}
};
void Appointment::PrintDoctorsANDAppointment()
{
	for (int i = 0; i < DoctorList::size; i++)
	{
		cout << endl;
		cout << "Name: " << DoctorList::doctors[i].GetNameD()
			<< ", Age: " << DoctorList::doctors[i].GetAgeD()
			<< ", Specialty: " << DoctorList::doctors[i].GetSpecialtyD() << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		for (int j = 0; j < 8; j++)
		{
			int val = (DoctorList::doctors[i].GetOpenApp()[j].GetTimeScheduled());
			if ((val == 8) || (val == 9) || (val == 10) || (val == 11))
			{
				cout << " " << DoctorList::doctors[i].GetOpenApp()[j].GetTimeScheduled() << ":00AM    ";
				cout << DoctorList::doctors[i].GetOpenApp()[j].GetPatientName() << endl;
			}
			if ((val == 1) || (val == 2) || (val == 3) || (val == 4))
			{
				cout << " " << DoctorList::doctors[i].GetOpenApp()[j].GetTimeScheduled() << ":00PM    ";
				cout << DoctorList::doctors[i].GetOpenApp()[j].GetPatientName() << endl;
			}
			if (val == 0)
			{
				cout << " OPEN " << endl;
			}

		}
	}
};
bool Appointment::ScheduleOpen(int timeScheduled, int arrayLocationD)
{
	for (int i = 0; i < 8; i++)
	{
		if (DoctorList::doctors[arrayLocationD].GetOpenApp()[i].GetTimeScheduled() == timeScheduled)
		{
			return false;
		}
	}
	for (int j = 0; j < 8; j++)
	{
		if (DoctorList::doctors[arrayLocationD].GetOpenApp()[j].GetTimeScheduled() == 0)
		{
			return true;
		}
	}
	return false;
};
void Appointment::ScheduleAppointment(int arrayLocationD, int timeScheduled, string patientName)
{
	for (int i = 0; i < 8; i++) 
	{
		if (DoctorList::doctors[arrayLocationD].GetOpenApp()[i].GetTimeScheduled() == 0) 
		{
			DoctorList::doctors[arrayLocationD].GetOpenApp()[i].SetTimeScheduled(timeScheduled);
			DoctorList::doctors[arrayLocationD].GetOpenApp()[i].SetPatientName(patientName);
			cout << "Appointment booked." << endl;
			break;
		}
	}
};
void Appointment::AppointmentSchedular(string patientName, int timeScheduled, string doctorName)
{
	int arrayLocationD = DoctorLocator(doctorName);
	if (arrayLocationD < 6)
	{
		if (ScheduleOpen(timeScheduled, arrayLocationD)) 
		{
			ScheduleAppointment(arrayLocationD, timeScheduled, patientName);
		}
		else
		{
			cout << "Appointment not available at that time." << endl;
		}
	}
	else
	{
		cout << endl <<"Your entry does not match a doctor on the doctor list." <<endl;
		cout << "Please try again." << endl;
	}
};
void Appointment::RemoveAppointment(string doctor, int time)
{
	int val = -1;
	int arrayLocationD = DoctorLocator(doctor);
	if (arrayLocationD < 6)
	{
		for (int i = 0; i < 8; i++)
		{
			if (DoctorList::doctors[arrayLocationD].GetOpenApp()[i].GetTimeScheduled() == time)
			{
				DoctorList::doctors[arrayLocationD].GetOpenApp()[i].SetTimeScheduled(0);
				DoctorList::doctors[arrayLocationD].GetOpenApp()[i].SetPatientName("Empty");
				cout << "The appointment has been cleared" << endl;
				val = 2;
				break;
			}
		}
		if (val == -1)
		{
			cout << endl << "This appointment time is already available." << endl;
		}
	}
		if (arrayLocationD >= 6)
	{
		cout << endl << "Your entry does not match a doctor on the doctor list." << endl;
		cout << "Please try again." << endl;
	}
};
void Appointment::CheckIfAppointmentOpen(string doctor, int time)
{
	int val = -1;
	int arrayLocationD = DoctorLocator(doctor);
	if (arrayLocationD < 6)
	{
		for (int i = 0; i < 8; i++)
		{
			if (DoctorList::doctors[arrayLocationD].GetOpenApp()[i].GetTimeScheduled() == time)
			{
				cout << endl << "Appointment time not available." << endl;
				val = 2;
				break;
			}
		}
		if (val == -1)
		{
			cout << endl << "Appointment time is OPEN." << endl;
		}
	}
	if (arrayLocationD >= 6)
	{
		cout << endl << "Your entry does not match a doctor on the doctor list." << endl;
		cout << "Please try again." << endl;
	}
};
bool Appointment::MenuPrompt()
{
	{
		int time;
		string patient;
		string doctor;
		string clear;
		Appointment start;
		bool end = false;
		char option = '0';


		cout << endl;
		cout << "Please choose an option below" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "1. Print doctor list." << endl;
		cout << "2. Print patient list." << endl;
		cout << "3. Schedule appointment." << endl;
		cout << "4. Remove Appointment." << endl;
		cout << "5. Print doctor list and the appointments scheduled." << endl;
		cout << "6. Check if appointment time is available." << endl;
		cout << "7. End Program." << endl;
		cout << ": ";
		cin >> option;
		switch (option) {
		case '1':
			cout << endl;
			start.PrintDoctors();
			cout << endl;
			system("pause");
			system("CLS");
			break;
		case '2':
			cout << endl;
			start.PrintPatients();
			cout << endl;
			system("pause");
			system("CLS");
			break;
		case '3':
			cout << endl <<"Please enter the patient name as it appears in the patient list." << endl;
			cout << ":";
			getline(cin, clear);
			getline(cin, patient);
			cout << endl << "Please enter the time you would like to book using the integer";
			cout << " format from the list below." << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "8  = 8:00AM" << endl;
			cout << "9  = 9:00AM" << endl;
			cout << "10 = 10:00AM" << endl;
			cout << "11 = 11:00AM" << endl;
			cout << "1  = 1:00PM" << endl;
			cout << "2  = 2:00PM" << endl;
			cout << "3  = 3:00PM" << endl;
			cout << "4  = 4:00PM" << endl;
			cout << ":";
			cin >> time;
			cout << endl <<"Please enter the doctor's name as it appears in the doctor list." << endl;
			cout << ":";
			getline(cin, clear);
			getline(cin, doctor);
			cout << endl;
			start.AppointmentSchedular(patient, time, doctor);
			cout << endl;
			system("pause");
			system("CLS");
			break;
		case '4':
			cout << endl << "Please enter the appointment time you would like to remove using the integer";
			cout << " format from the list below." << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "8  = 8:00AM" << endl;
			cout << "9  = 9:00AM" << endl;
			cout << "10 = 10:00AM" << endl;
			cout << "11 = 11:00AM" << endl;
			cout << "1  = 1:00PM" << endl;
			cout << "2  = 2:00PM" << endl;
			cout << "3  = 3:00PM" << endl;
			cout << "4  = 4:00PM" << endl;
			cout << ":";
			cin >> time;
			cout << endl << "Please enter the doctor's name as it appears in the doctor list." << endl;
			cout << ":";
			getline(cin, clear);
			getline(cin, doctor);
			cout << endl;
			start.RemoveAppointment(doctor, time);
			cout << endl;
			system("pause");
			system("CLS");
			break;
		case '5':
			cout << endl;
			start.PrintDoctorsANDAppointment();
			cout << endl;
			system("pause");
			system("CLS");
			break;
		case '6':
			cout << endl << "Please enter the appointment time you would like check using the";
			cout << " format from the list below." << endl << endl;
			cout << "8  = 8:00AM" << endl;
			cout << "9  = 9:00AM" << endl;
			cout << "10 = 10:00AM" << endl;
			cout << "11 = 11:00AM" << endl;
			cout << "1  = 1:00PM" << endl;
			cout << "2  = 2:00PM" << endl;
			cout << "3  = 3:00PM" << endl;
			cout << "4  = 4:00PM" << endl;
			cout << ":";
			cin >> time;
			cout << endl << "Please enter the doctor's name as it appears in the doctor list." << endl;
			cout << ":";
			getline(cin, clear);
			getline(cin, doctor);
			cout << endl;
			start.CheckIfAppointmentOpen(doctor, time);
			cout << endl;
			system("pause");
			system("CLS");
			break;
		case '7':
			end = true;
			break;
		default:
			cout << "Your entry was invalid please try again." << endl;
			break;
		}

		return end;
	}
};

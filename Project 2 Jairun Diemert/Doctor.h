//File: Doctor.h
//Author: Jairun Diemert
//Class: COP3014
//Project: 2
//Description: This is the header file for the Doctor class.

#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <string>
using namespace std;

#include "Appointment.h"

class Doctor {
public:
	Doctor(string name = "Empty", int age = 0, string specialty = "Empty");
	string GetNameD();
	int GetAgeD();
	string GetSpecialtyD();
	Appointment * GetOpenApp();
private:	
	string nameD;
	int ageD;
	string specialtyD;
	Appointment appointment[8];
};
#endif 

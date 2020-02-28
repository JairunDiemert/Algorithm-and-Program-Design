//File: Doctor.cpp
//Author: Jairun Diemert
//Class: COP3014
//Project: 2
//Description: This is the member function file for Doctor.

#include <iostream>
#include <string>
using namespace std;

#include "Doctor.h"
#include "Appointment.h"

Doctor::Doctor(string name, int age, string specialty)
{
	nameD = name;
	ageD = age;
	specialtyD = specialty;
};
string Doctor::GetNameD()
{
	return nameD;
};
int Doctor::GetAgeD()
{
	return ageD;
};
string Doctor::GetSpecialtyD()
{
	return specialtyD;
};
Appointment * Doctor::GetOpenApp()
{
	return appointment;
};
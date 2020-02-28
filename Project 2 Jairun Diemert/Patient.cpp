//File: Patient.cpp
//Author: Jairun Diemert
//Class: COP3014
//Project: 2
//Description: This is the member function file for Patient.

#include <iostream>
#include <string>
using namespace std;

#include "Patient.h"

Patient::Patient(string name, int age, string sex)
{
	nameP = name;
	ageP = age;
	sexP = sex;
};
string Patient::GetNameP()
{
	return nameP;
};
int Patient::GetAgeP()
{
	return ageP;
};
string Patient::GetSexP()
{
	return sexP;
};

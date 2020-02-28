//File: Patient.h
//Author: Jairun Diemert
//Class: COP3014
//Project: 2
//Description: This is the header file for the Patient class.

#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
using namespace std;

class Patient {
public:
	Patient(string name = "Empty", int age = 0, string sex = "Empty");
	string GetNameP();
	int GetAgeP();
	string GetSexP();
private:	
	string nameP;
	int ageP;
	string sexP;
};
#endif 


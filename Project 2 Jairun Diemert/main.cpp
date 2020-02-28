//File: main.cpp
//Author: Jairun Diemert
//Class: COP3014
//Project: 2
//Description: This is the main source file of my project. 

#include <iostream>
using namespace std;

#include "Appointment.h"
#include "DoctorList.h"

int main()
{
	Appointment start;
	while (!start.MenuPrompt()) {};
}
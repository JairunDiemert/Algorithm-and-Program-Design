#include <iostream>
using namespace std;

#include "DateClass.h"

Date::Date() {
	month = 01;
	day = 01;
	year = 1900;
	cout << "default constructor called" << endl << endl;
};
Date::Date(int monthTemp, int dayTemp, int yearTemp) {
	month = monthTemp;
	day = dayTemp;
	year = yearTemp;
	cout << "second construct called" << endl << endl;
};
Date::Date(const Date& dateCopy) {
	month = dateCopy.month;
	day = dateCopy.day;
	year = dateCopy.year;
	cout << "copy construct called" << endl << endl;
};
Date::~Date() {
	cout << "Date deleted" << endl << endl;
};
int Date::GetMonth() {
	return month;
};
void Date::SetMonth(int monthTemp) {
	month = monthTemp;
};
int Date::GetDay() {
	return day;
};
void Date::SetDay(int dayTemp) {
	day = dayTemp;
};
int Date::GetYear() {
	return year;
};
void Date::SetYear(int yearTemp) {
	year = yearTemp;
};
void Date::PrintDate() {
	cout << month << "/" << day << "/" << year;
};
void Date::LeapCheck() {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				cout << year << " is a leap year." << endl << endl;
			}
			else {
				cout << year << " is not a leap year." << endl << endl;
			}
		}
		else {
			cout << year << " is a leap year." << endl << endl;
		}
	}
	else {
		cout << year << " is not a leap year." << endl << endl;
	}
};
void Date::CompareDates(Date date1, Date date2) {
	if (year < date2.year) {
		date1.PrintDate();
		cout << " < ";
		date2.PrintDate();
		cout << endl << endl;
	}
	if (year > date2.year) {
		date1.PrintDate();
		cout << " > ";			
		date2.PrintDate();
		cout << endl << endl;
	}
	if (year == date2.year) {
		if (month < date2.month) {
			date1.PrintDate();
			cout << " < ";
			date2.PrintDate();
			cout << endl << endl;
		}
		if (month > date2.month) {
			date1.PrintDate();
			cout << " > ";
			date2.PrintDate();
			cout << endl << endl;
		}
		if (month == date2.month) {
			if (day < date2.day) {
				date1.PrintDate();
				cout << " < ";
				date2.PrintDate();
				cout << endl << endl;
			}
			if (day > date2.day) {
				date1.PrintDate();
				cout << " > ";
				date2.PrintDate();
				cout << endl << endl;
			}
			if (day == date2.day) {
				date1.PrintDate();
				cout << " = ";
				date2.PrintDate();
				cout << endl << endl;
			}
		}
	}
};
void Date::DifferenceDates(Date date1, Date date2) {
	int date1Sum, date2Sum;

	if (month < 3) {
		year--; 
		month = month + 12;
		date1Sum = 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + day - 306;
		year++;
		month = month - 12;
	}
	if (month >= 3) {
		date1Sum = 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + day - 306;
	}
	if (date2.month < 3) {
		date2.year--;
		date2.month = date2.month + 12;
		date2Sum = 365 * date2.year + date2.year / 4 - date2.year / 100 + date2.year / 400 + (153 * date2.month - 457) / 5 + date2.day - 306;
		date2.year++;
		date2.month = date2.month - 12;
	}
	if (date2.month >= 3) {
		date2Sum = 365 * date2.year + date2.year / 4 - date2.year / 100 + date2.year / 400 + (153 * date2.month - 457) / 5 + date2.day - 306;
	}
	if (date1Sum > date2Sum) {
		date1, PrintDate();
		cout << " - "; 
		date2.PrintDate(); 
		cout << " = " << date1Sum - date2Sum << " days" << endl << endl;
	}
	if (date1Sum < date2Sum) {
		date2, PrintDate();
		cout << " - ";
		date1.PrintDate();
		cout << " = " << date2Sum - date1Sum << " days" << endl << endl;
	}
	if (date1Sum == date2Sum) {
		date1, PrintDate();
		cout << " - ";
		date2.PrintDate();
		cout << " = 0 days" << endl << endl;
	}
};
void Date::DayOfWeek(Date date1) {
	int date1Sum, dayOfWeek;

	if (month < 3) {
		year--;
		month = month + 12;
	}
	date1Sum = 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + day - 306;
	dayOfWeek = date1Sum % 7;
	cout << dayOfWeek << endl << endl;
	switch (dayOfWeek) {
	case 1: date1.PrintDate(); cout << " is a Monday." << endl << endl; break;
	case 2: date1.PrintDate(); cout << " is a Tuesday." << endl << endl; break;
	case 3: date1.PrintDate(); cout << " is a Wednesday." << endl << endl; break;
	case 4: date1.PrintDate(); cout << " is a Thursday." << endl << endl; break;
	case 5: date1.PrintDate(); cout << " is a Friday." << endl << endl; break;
	case 6: date1.PrintDate(); cout << " is a Saturday." << endl << endl; break;
	case 0: date1.PrintDate(); cout << " is a Sunday." << endl << endl; break;
	}
};

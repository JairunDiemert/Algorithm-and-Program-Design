#include <iostream>
using namespace std;

#include "DateClass.h"


int main() {
	Date dateDefault;
	Date date1(11, 16, 2018);
	Date date2(01, 01, 1900);
	Date date3 = date1;
	date1.LeapCheck();
	date1.CompareDates(date1, date2);
	date1.DifferenceDates(date1, date2);
	date1.DayOfWeek(date1);

	system("pause");

	return 0;
}
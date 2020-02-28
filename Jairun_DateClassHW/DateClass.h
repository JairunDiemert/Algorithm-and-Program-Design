#ifndef DATECLASS_H_
#define DATECLASS_H_

class Date {

public:
	Date();
	Date(int monthTemp, int dayTemp, int yearTemp);
	Date(const Date& dateCopy);
	~Date();
	int GetMonth();
	void SetMonth(int monthTemp);
	int GetDay();
	void SetDay(int dayTemp);
	int GetYear();
	void SetYear(int yearTemp);
	void PrintDate();
	void LeapCheck();
	void CompareDates(Date date1, Date date2);
	void DifferenceDates(Date date1, Date date2);
	void DayOfWeek(Date date1);
private:
	int month;
	int day;
	int year;
};

#endif /* DATECLASS_H_ */
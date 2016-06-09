#pragma once
class Date
{
	int day;
	int year;
	int month;
public:
	Date(){}
	Date(int d,int m,int y);
	void Set_day(int val);
	int  Get_day();
	void Set_month(int val);
	int  Get_month();
	void Set_year(int val);
	int  Get_year();
	int No_Of_Days(Date &other);
	~Date();
};


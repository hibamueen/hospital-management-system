#pragma once
#include "Patient.h"
#include "Date.h"
#include <iostream>
class Room
{
	bool available;
	Patient * p;
	Date Admit;
	Date Discharge;
public:
	Room() { available = true; }
	Room(bool a);
	bool Get_available();
	void Set_available(bool x);
	void Set_Patient(Patient q);
	void Set_Admit(Date &d) 
	{
		Admit.Set_day(d.Get_day());
		Admit.Set_month(d.Get_month());
		Admit.Set_year(d.Get_year());
	}
	Date Get_Admit()
	{
		return Admit;
	}
	void Set_Discharge(Date &d)
	{
		Discharge.Set_day(d.Get_day());
		Discharge.Set_month(d.Get_month());
		Discharge.Set_year(d.Get_year());
	}
	Patient & Get_Patient();
	~Room();
};


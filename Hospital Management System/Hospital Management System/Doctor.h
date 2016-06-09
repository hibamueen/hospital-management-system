#pragma once
#include<iostream>
#include<string>
#include<conio.h>
#include "Patient.h"
using namespace std;
class Doctor
{
	string name, Field;
	int age, id, size, index, fees;
	char gender;
	double contact;
	Patient * ptr;
	bool slot;
public:
	Doctor() { slot = true; ptr = NULL; }
	Doctor(Doctor &q)
	{
		if (size > 10)
			size = 10;
		else if (size < 5)
			size = 5;
		this->size = q.size;
		this->name = q.name;
		this->age = q.age;
		this->id = q.id;
		this->gender = q.gender;
		this->contact = q.contact;
		this->Field = q.Field;
		this->fees = q.fees;
		this->ptr = new Patient[size]();
		this->index = 0;
		slot = true;
	}
	Doctor(string name, string Field, int age, int id, int fees, int size, char gender, double contact);
	void Set_Field(string val);
	string  Get_Field();
	void print();
	void Set_contact(double val);
	double  Get_contact();
	void Set_gender(char val);
	char Get_gender();
	void Set_id(int val);
	int  Get_id();
	void Set_age(int val);
	int  Get_age();
	void Set_fees(int val);
	int  Get_fees();
	bool Get_Slot() { return slot; }
	void Set_Slot(bool x) { slot = x; }
	void Set_name(string val);
	string  Get_name();
	void update(int ID)
	{
		ptr[index - 1].Set_id(ID);
	}
	void insert_patient(Patient q) 
	{ 
		if (index < size)
		{
			ptr[index].Set_name(q.Get_name());
			ptr[index].Set_id(q.Get_id());
			ptr[index].Set_gender(q.Get_gender());
			ptr[index].Set_contact(q.Get_contact());
			ptr[index].Set_dep(q.Get_dep());
			ptr[index++].Set_age(q.Get_age());
		}
		else
			cout << Field << " Doctor Cannot Handle More Patients. Sorry\n";
	}
	void delete_patient(int ID)
	{
		for (int i = 0; i < index ; i++)
		{
			if (ptr[i].Get_id() == ID)
			{
				ptr[i].~Patient();
				for (int j = i; j < index - 1; j++)
				{
					Patient temp = ptr[j];
					ptr[j] = ptr[j + 1];
					ptr[j + 1] = temp;
				}
				index--;
				break;
			}
		}
	}
	~Doctor();
};
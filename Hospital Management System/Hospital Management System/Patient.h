#pragma once
#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

class Patient
{
	string name, department;
	int age, bill, id;
	char gender;
	double contact;
public:
	Patient() {};
	Patient(string name, int age, int id,char gender, double contact, string department);
	void print();
	void Set_contact(double val);
	double  Get_contact();
	void Set_gender(char val);
	char Get_gender();
	void Set_age(int val);
	int  Get_age();
	void Set_bill(int val);
	int  Get_bill();
	void Set_name(string val);
	void Set_id (int val){id = val;}
	int  Get_id (){return id;}
	string  Get_name();
	void Set_dep(string val) { department = val; }
	string  Get_dep() { return department; }
	~Patient();
};


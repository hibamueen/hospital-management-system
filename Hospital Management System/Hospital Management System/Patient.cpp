#include "Patient.h"

Patient::Patient(string name, int age,int id, char gender, double contact, string department)
{
	this->name = name;
	this->age = age;
	this->gender = gender;
	this->contact = contact;
	this->bill = 2000;
	this->department = department;
	this->id = id;
}

void Patient::print()
{
	cout << "Name :" << name << endl;
	cout << "Age :" << age << endl;
	cout << "Gender :" << gender << endl;
	cout << "Contact :" << contact << endl;
	cout << "Department :" << department << endl;
}

void Patient::Set_contact(double val)
{
	contact = val;
}

double Patient::Get_contact()
{
	return contact;
}

void Patient::Set_gender(char val)
{
	gender = val;
}

char Patient::Get_gender()
{
	return gender;
}

void Patient::Set_age(int val)
{
	age = val;
}

int Patient::Get_age()
{
	return age;
}

void Patient::Set_bill(int val)
{
	bill = val;
}

int Patient::Get_bill()
{
	return bill;
}

void Patient::Set_name(string val)
{
	name = val;
}

std::string Patient::Get_name()
{
	return name;
}

Patient::~Patient()
{

}

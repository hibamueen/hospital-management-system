#include "Doctor.h"

Doctor::Doctor(string name, string Field, int age, int id, int fees, int size, char gender, double contact)
{
	if (size > 10)
		size = 10;
	else if (size < 5)
		size = 5;
	this->size = size;
	this->name = name;
	this->age = age;
	this->id = id;
	this->gender = gender;
	this->contact = contact;
	this->Field = Field;
	this->fees = fees;
	this->ptr = new Patient[size]();
	this->index = 0;
	slot = true;
}

void Doctor::Set_Field(string val)
{
	Field = val;
}

std::string Doctor::Get_Field()
{
	return Field;
}

void Doctor::print()
{
	cout << "Name :" << name << endl;
	cout << "Age :" << age << endl;
	cout << "Id :" << id << endl;
	cout << "Gender :" << gender << endl;
	cout << "Field :" << Field << endl;
	cout << "Contact :" << contact << endl;
	cout << "Fees :" << fees << endl;
	cout << "Patients :" << endl;
	cout << "\n---------------------------------------\n" << endl;
	for (int i = 0; i < index ; i++)
	{
		ptr[i].print();
		cout << "\n---------------------------------------" << endl;
	}
}

void Doctor::Set_contact(double val)
{
	contact = val;
}

double Doctor::Get_contact()
{
	return contact;
}

void Doctor::Set_gender(char val)
{
	gender = val;
}

char Doctor::Get_gender()
{
	return gender;
}

void Doctor::Set_id(int val)
{
	id = val;
}

int Doctor::Get_id()
{
	return id;
}

void Doctor::Set_age(int val)
{
	age = val;
}

int Doctor::Get_age()
{
	return age;
}

void Doctor::Set_fees(int val)
{
	fees = val;
}

int Doctor::Get_fees()
{
	return fees;
}

void Doctor::Set_name(string val)
{
	name = val;
}

std::string Doctor::Get_name()
{
	return name;
}

Doctor::~Doctor()
{
	//delete ptr;
}

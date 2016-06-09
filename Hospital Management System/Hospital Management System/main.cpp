#include<iostream>
#include<string>
#include<conio.h>
#include "Room.h"
#include "Doctor.h"
void Insert_Doctor(Doctor temp[], int &index);
void Search_Doctor(Doctor temp[]);
void Delete_Doctor(Doctor temp[]);
void Insert_Patient(Room temp[], int &index,Doctor temp1[]);
void Search_Patient(Room temp[]);
void Check_Out(Room temp[],Doctor temp2[]);
bool r = false;
using namespace std;

void main()
{
	Doctor doc[5];
	Room rm[25];
	int dindex = 0, rindex = 0;
	while (true)
	{
		system("CLS");
		cout << "___________________________________\n\nHOSPITAL MANAGEMENT SYSTEM\n___________________________________\n";
		cout << "Select:\n1.Patient\n2.Doctor\n3.Exit\n>";
		int a, b = 0, c = 0; cin >> a;
		switch (a)
		{
		case 1:
			if (!r)
			{
				cout << "Please Add a Doctor First to Admit Patients." << endl;
				system("pause");
				break;
			}
			while (b!=4)
			{
				system("CLS");
				cout << "___________________________________\nPATIENT MENU\n___________________________________\n";
				cout << "Select:\n1.Register New Patient\n2.View info\n3.Check-out\n4.Back\n>";
				cin >> b;
				switch (b)
				{
				case 1:
					Insert_Patient(rm, rindex, doc);
					break;
				case 2:
					Search_Patient(rm);
					break;
				case 3:
					Check_Out(rm, doc);
					break;
				case 4:
					break;
				default:
					cout << "\nInvalid Input!" << endl;
					break;
				}
			}
			break;
		case 2:
			while (c != 4)
			{
				system("CLS");
				cout << "___________________________________\nDOCTOR MENU\n___________________________________\n";
				cout << "Select:\n1.Add\n2.View info\n3.Delete\n4.Back\n>";
				cin >> c;
				switch (c)
				{
				case 1:
					Insert_Doctor(doc, dindex);
					break;
				case 2:
					Search_Doctor(doc);
					break;
				case 3:
					
					break;
				case 4:
					break;
				default:
					cout << "\nInvalid Input!" << endl;
					break;
				}
			}
			break;
		case 3:
			exit(0);
			break;
		}
	}
}

void Insert_Doctor(Doctor temp[], int &index)
{
	if (index == 5)
		index = 0;
	system("CLS");
	cout << "________________\nNEW DOCTOR\n________________\n";
	string name,field;
	int age, size;
	char gender;
	double contact;

	cout << "Enter:\nName: ";
	cin.ignore();
	getline(cin, name);
	cout << "Field : ";
	cin >> field;
	cout << "Gender (M,F) : ";
	cin >> gender;
	cout << "Age: ";
	cin >> age;
	cout << "Max # of Patients: ";
	cin >> size;
	cout << "Contact #: ";
	cin >> contact;
	for (int i = 0; i < 5 ; i++)
	{
		if (!temp[i].Get_Slot() && temp[i].Get_Field() == field)
		{
			cout << "We already have a Doctor in this field and can't hire more.\n";
			system("pause");
			return;
		}
	}
	Doctor t(name, field, age, 0, 5000, size, gender, contact);
	for (int i = index; i < 5; i++)
	{
		if (temp[i].Get_Slot())
		{
			temp[i] = t;
			temp[i].Set_Slot(false);
			index = i;
			index = i + 1;
			temp[i].Set_id(i);
			cout << "Doctor's ID :" << i + 1 << endl;
			r = true;
			break;
		}
	}
	system("pause");
}

void Search_Doctor(Doctor temp[])
{
	int id;
	system("CLS");
	cout << "________________\nDOCTOR'S INFO\n________________\n";
	cout << "Enter ID: ";
	cin >> id;

	if (!temp[id-1].Get_Slot())
	{
		temp[id - 1].print();
	}
	else
		cout << "No Such Record Exists!" << endl;
	system("pause");
}

void Delete_Doctor(Doctor temp[]);

void Insert_Patient(Room temp[], int &index,Doctor temp1[])
{
	if (index == 25)
		index = 0;
	string name, type, department;
	int age,day,month,year;
	char gender;
	double contact;
	Date t;

	system("CLS");
	cout << "________________\nNEW REGISTRATION\n________________\n";
	cout << "Enter:\nName: ";
	cin.ignore();
	getline(cin, name);
	cout << "Gender (M,F) : ";
	cin >> gender;
	cout << "Age: ";
	cin >> age;
	cout << "Date of Admission: \nDay :";
	cin >> day;
	cout << "Month :";
	cin >> month;
	cout << "Year :";
	cin >> year;
	cout << "Department : ";
	cin >> department;
	cout << "Contact # : ";
	cin >> contact;
	t.Set_day(day);
	t.Set_month(month);
	t.Set_year(year);
	
	Patient tt(name, age, 0, gender, contact, department);
	bool v = false;
	int w = 0;
	for (; w < 5 ; w++)
	{
		if (temp1[w].Get_Field() == department)
		{
			temp1[w].insert_patient(tt);
			v = true;
			break;
		}
	}
	if (!v)
	{
		cout << "We don't have an " << department << " Doctor, kindly visit another Hospital." << endl;
		return;
	}
	if (v)
	{
		bool f = true;
		for (int i = index; i != index - 1; i++)
		{
			if (temp[i].Get_available())
			{
				tt.Set_id(i);
				temp1[w].update(i);
				temp[i].Set_Patient(tt);
				temp[i].Set_available(false);
				temp[i].Set_Admit(t);
				index = i;
				index++;
				f = false;
				cout << "Kindly note your Room # : " << i + 1 << endl;
				break;
			}
			if (i == 24)
				i = 0;
		}

		if (f)
		{
			cout << "\nSorry, No rooms are available.Please visit another Hospital." << endl;
			temp1[w].delete_patient(index - 1);
		}
		system("pause");
	}
}

void Search_Patient(Room temp[])
{
	system("CLS");
	cout << "________________\nPATIENT'S INFO\n________________\n";
	int id;
	cout << "Enter Patient's Room #:";
	cin >> id;

	if (!temp[id - 1].Get_available())
	{
		temp[id - 1].Get_Patient().print();
		cout << "Date of Admission :" << temp[id - 1].Get_Admit().Get_day() << "/" << temp[id - 1].Get_Admit().Get_month() << "/" << temp[id - 1].Get_Admit().Get_year() << endl;
	}
	else
		cout << "No Such Record Exists!" << endl;
	system("pause");
}

void Check_Out(Room temp[],Doctor temp2[])
{
	int id,day,month,year;
	Date t;
	system("CLS");
	cout << "________________\nCHECK OUT\n________________\n";
	cout << "Enter Patient's Room #:";
	cin >> id;

	if (!temp[id - 1].Get_available())
	{
		temp[id - 1].Get_Patient().print();
		cout << "Date of Admission :" << temp[id - 1].Get_Admit().Get_day() << "/" << temp[id - 1].Get_Admit().Get_month() << "/" << temp[id - 1].Get_Admit().Get_year() << endl;
		cout << "Enter Date Of Discharge to Calculate Total Bill :\nDay :";
		cin >> day;
		cout << "Month :";
		cin >> month;
		cout << "Year :";
		cin >> year;
		t.Set_day(day);
		t.Set_month(month);
		t.Set_year(year);
		temp[id - 1].Set_Discharge(t);
		int fee = temp[id - 1].Get_Admit().No_Of_Days(t);
		cout << "Days in Hospital :" << fee << endl;
		cout << "Room Fee :" << 2000 * fee << endl;
		cout << "Doctor's Fee :" << 5000 << endl;
		cout << "Total Bill :" << 5000 + 2000 * fee << endl;
		int w = 0;
		for (; w < 5; w++)
		{
			if (temp2[w].Get_Field() == temp[id - 1].Get_Patient().Get_dep())
			{
				temp2[w].delete_patient(temp[id - 1].Get_Patient().Get_id());
				break;
			}
		}
		temp[id - 1].Get_Patient().~Patient();
		temp[id - 1].Set_available(true);
	}
	else
		cout << "No Such Record Exists!" << endl;
	system("pause");
}
#include "Room.h"



Room::Room(bool a)
{
	available = a;
}


bool Room::Get_available()
{
	return available;
}

void Room::Set_available(bool x)
{
	available = x;
}

void Room::Set_Patient(Patient q)
{
	p = new Patient(q.Get_name(), q.Get_age(),q.Get_id(), q.Get_gender(), q.Get_contact(), q.Get_dep());
}

Patient & Room::Get_Patient()
{
	return *p;
}

Room::~Room()
{
	delete p;
	p = NULL;
}

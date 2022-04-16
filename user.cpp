#include "user.h"
#include "trip.h"

user::user()
{
	name = "-";
	email = "-";
	phone_number = "-";
	current_trip = nullptr;
}
user::user(string name, date DOB, string email, string phone):DOB(DOB)
{
	current_trip = nullptr;
	this->name = name;
	this->email = email;
	phone_number = phone;
}
void user::print()
{
	cout << "Name: " << name << endl;
	cout << "Date of birth: " << DOB << endl;
	cout << "Email: " << email << endl;
	cout << "Phone number: " << phone_number << endl;
	cout << "Total trips = " << trips.size() << endl;
}
void user::printTrips()
{
	cout << "<<<< Trips of " << name <<" >>>>"<< endl;
	for (int i = 0; i < trips.size(); i++)
	{
		cout << *trips.at(i) << endl;
	}
}
void user::change_name(string name)
{
	this->name = name;
}
void user::change_phone_number(string phone_number)
{
	this->phone_number = phone_number;
}
void user::change_DOB(date DOB)
{
	this->DOB = DOB;
}
void user::change_email(string email)
{
	this->email = email;
}
trip* user::bookRide(string a, string b)
{
	return nullptr;
}
void user::pickARide(trip*) {}
void user:: endARide() {}
user::~user()
{
	cout << "~user is called" << endl;
}
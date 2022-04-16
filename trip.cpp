#include "trip.h"
#include "passanger.h"
#include "driver.h"

trip::trip()
{
	status = "";
	pick_up = "";
	drop_off = "";
}
void trip::change_status(string status)
{
	this->status = status;
}
void trip::set_pick_up(string pick)
{
	this->pick_up = pick;
}
void trip::set_date(date d)
{
	trip_date = d;
}
void trip::set_drop_off(string drop)
{
	this->drop_off = drop;
}
string trip::get_status()
{
	return status;
}
ostream& operator<<(ostream& osObject, trip &T)
{
	osObject << "Status: " << T.status << endl;
	osObject << "Date: " << T.trip_date << endl;
	osObject << "Pick up location: " << T.pick_up << endl;
	osObject << "Drop off location: " << T.drop_off << endl;
	osObject << "Passanger name: " << T.P->get_name();
	if (T.status == "complete")
	{
		cout << "\nDriver name: "<< T.D->get_name() << endl;
		cout << "Passanger's rating: " << T.passanger_rating << endl;
		cout << "Driver's rating: " << T.driver_rating << endl;
	}
	return osObject;
}
trip::~trip()
{
	P = nullptr;
	D = nullptr;
	cout << "~trip()" << endl;
}
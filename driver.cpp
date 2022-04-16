#include "driver.h"

driver::driver(){}
driver::driver(string name, date DOB, string email, string phone, string license, string id):
user(name,DOB,email,phone)
{
	driving_license_number = license;
	vehicle_id_number = id;
}
void driver::print()
{
	this->user::print();
	cout << "Driving license number: " << this->driving_license_number << endl;
	cout << "Vehicle identification number: " << this->vehicle_id_number << endl;
	cout << "Status: ";
	if (this->current_trip == nullptr || this->current_trip->get_status() == "complete" || this->current_trip->get_status() == "canceled")
	{
		cout << "currently not driving" << endl;
	}
	else if (this->current_trip->get_status() == "In progress")
	{
		cout << "currently driving" << endl;
	}
}
ostream& operator<<(ostream& osObject, driver &other)
{
	other.print();
	return osObject;
}
void driver::pickARide(trip* other)
{
	if (other->get_status() == "searching for driver")
	{
		other->change_status("In progress");
		other->D = this;
		this->current_trip = other;
		this->trips.push_back(current_trip);
	}
	else if (other->get_status() == "complete" || other->get_status() == "canceled")
	{
		cout << "This ride is not looking for a driver" << endl;
	}

}
void driver::rate(trip* other, int rating)
{
	ratePassanger(other, rating);
}
void driver::ratePassanger(trip* other, int rating)
{
	if (other->get_status() == "In progress" || other->get_status() == "canceled")
	{
		cout << "Error in rating passanger" << endl;
	}
	else if (rating<=5 && rating>=1)
	{
		other->passanger_rating = rating;
	}
	else
	{
		cout << "Rating should be between 1 to 5" << endl;
	}
}
string driver::get_name()
{
	return name;
}
void driver::endARide()
{
	current_trip->change_status("complete");
	current_trip = nullptr;
}
float driver::getAvgRating()
{
	float avgrating = 0.0;
	int completed_trips = 0;
	for (int i = 0; i < trips.size(); i++)
	{
		if (trips.at(i)->get_status() == "complete")
		{
			avgrating += trips.at(i)->driver_rating;
			completed_trips++;

		}
	}
	return avgrating / completed_trips;
}
driver::~driver()
{
	cout << "~driver()" << endl;
}
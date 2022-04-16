#include "passanger.h"

passanger::passanger(){}
passanger::passanger(string name, date DOB, string email, string phone, payment method) :
user(name, DOB, email, phone)
{
	methods.push_back(method);
}
void passanger::print()
{
	this->user::print();
	for (auto i = 0; i < this->methods.size(); i++)
	{
		cout << this->methods.at(i) << endl;
	}
	cout << "Status: ";
	if (this->current_trip == nullptr || this->current_trip->get_status() == "complete" || this->current_trip->get_status() == "canceled")
	{
		cout << "currently not riding" << endl;
	}
	else if (this->current_trip->get_status() == "In progress")
	{
		cout << "currently riding" << endl;
	}
}

ostream& operator<<(ostream& osObject, passanger &P)
{
	P.print();
	return osObject;
}
trip* passanger::bookRide(string pick, string drop)
{
	if (current_trip != nullptr)
	{
		if (current_trip->get_status() != "complete")
		{
			if (current_trip->get_status() != "canceled")
			{
				cout << "\nCannot book more than one ride" << endl;
				return nullptr;
			}
		}
		if (current_trip->get_status() == "complete" || current_trip->get_status() == "canceled")
		{
			current_trip = nullptr; //deleting perivious trip address
		}
	}
	if (current_trip == nullptr)
	{
		current_trip = new trip;
		current_trip->change_status("searching for driver");
		current_trip->set_pick_up(pick);
		current_trip->set_drop_off(drop);
		current_trip->P = this;
		this->trips.push_back(current_trip);
		cout << "Ride successfully booked" << endl;
	}
	return current_trip;
}
string passanger::get_name()
{
	return name;
}
void passanger::rate(trip* other, int rating)
{
	rateDriver(other, rating);
}
void passanger::rateDriver(trip* other, int rating)
{
	if (other->get_status() == "In progress" || other->get_status() == "canceled")
	{
		cout << "Error in rating driver\n" << endl;
	}
	else
	{
		other->driver_rating = rating;
	}
}
void passanger::cancelRide()
{
	if (this->current_trip->get_status() == "canceled")
	{
		cout << "Error in canceling this ride" << endl;
	}
	else
	{
		this->current_trip->change_status("canceled");
	}
}
void passanger::add_payment_method(const payment &other)
{
	if (methods.size() < 3)
	{
		methods.push_back(other);
		cout << "Payment method added successfully" << endl;
		cout << "Total payment methods: " << methods.size() << endl;
	}
	else
	{
		cout << "You already have 3 paymnet methods" << endl;
	}
}
float passanger::getAvgRating()
{
	float avgrating = 0.0;
	int completed_trips = 0;
	for (auto i = 0; i < trips.size(); i++)
	{
		if (trips.at(i)->get_status() == "complete")
		{
			avgrating += trips.at(i)->passanger_rating;
			completed_trips++;
		}
	}
	return avgrating / completed_trips;
}
void passanger::delete_payment_method(int method_number)
{
	if (methods.size() > 0)
	{
		methods.erase(methods.begin() + (method_number - 1));
		cout << "Payment method " << method_number << " deleted successfully" << endl;
	}
	else
	{
		cout << "You have no payment method to delete" << endl;
	}
}
passanger::~passanger()
{
	cout << "~passanger()" << endl;
}
#pragma once
#include <vector>
#include "date.h"
#include "trip.h"


class user
{
protected:
	string name;
	date DOB;
	string email;
	string phone_number;
	vector <trip*> trips;
	trip* current_trip;
public:
	user();
	user(string, date, string, string);
	virtual void print() = 0;
	virtual trip* bookRide(string, string);
	virtual void pickARide(trip*);
	virtual void endARide();
	virtual void rate(trip*, int) = 0; //pure virtual
	void printTrips();
    virtual float getAvgRating() = 0; //pure virtual
	void change_name(string);
	void change_phone_number(string);
	void change_DOB(date);
	void change_email(string);
	~user();
};
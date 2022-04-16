#pragma once
#include "date.h"

class passanger;
class driver;

class trip
{
private:
	string status;
	date trip_date;
	string pick_up;
	string drop_off;
	passanger* P;
	driver* D;
	int driver_rating;
	int passanger_rating;
public:
	trip();
	void change_status(string);
	string get_status();
	void set_pick_up(string);
	void set_date(date);
	void set_drop_off(string);
	friend ostream& operator<<(ostream&, trip&);
	friend class passanger;
	friend class driver;
	~trip();
};
#pragma once
#include "user.h"

class driver: public virtual user
{
private:
	string driving_license_number;
	string vehicle_id_number;
public:
	driver();
	driver(string, date, string, string, string, string);
	void pickARide(trip*);
	void endARide();
	void print();
	string get_name();
	void rate(trip*, int);
	void ratePassanger(trip* , int);
	float getAvgRating();
	friend ostream& operator<<(ostream&, driver&);
	~driver();
};
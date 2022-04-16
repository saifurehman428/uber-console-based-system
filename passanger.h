#pragma once
#include "user.h"
#include "payment.h"
#include "date.h"

class passanger : public virtual user
{
private:
	vector <payment> methods;
public:
	passanger();
	passanger(string, date, string, string, payment);
	friend ostream& operator<<(ostream&, passanger&);
	void add_payment_method(const payment&);
	float getAvgRating();
	void rate(trip*, int);
	void print();
	void delete_payment_method(int);
	void cancelRide();
	void rateDriver(trip*, int);
	string get_name();
	trip* bookRide(string, string);
	~passanger();
};

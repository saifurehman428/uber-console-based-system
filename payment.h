#pragma once
#include <iostream>
using namespace std;

class payment
{
private:
	string payment_type;
	string card_num;
public:
	payment();
	payment(string, string); //if card payment method
	payment(string); //if cash payment method
	friend ostream& operator<<(ostream&,payment&);
	void set_card_number(string);
	string get_card_number();
	~payment();
};


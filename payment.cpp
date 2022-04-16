#include "payment.h"

payment::payment()
{
	payment_type = "";
	card_num = "";
}
payment::payment(string payment_type)
{
	this->payment_type = payment_type;
	this->card_num = "xxxx";
}
payment::payment(string card_num, string payment_type)
{
	this->payment_type = payment_type;
	this->card_num = card_num;
}
ostream& operator<<(ostream& osObject, payment& P)
{
	osObject << "Method: " << P.payment_type;
	if (P.card_num != "xxxx")
	{
		osObject << ", Card Number: " << P.card_num;
	}
	return osObject;
}
void payment::set_card_number(string card_num)
{
	this->card_num = card_num;
}
string payment::get_card_number()
{
	return card_num;
}
payment::~payment()
{
	cout << "~payment()" << endl;
}
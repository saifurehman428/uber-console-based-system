#pragma once
#include <iostream>
using namespace std;


class date
{
private:
	int Date;
	int month;
	int year;
public:
	date(int,int,int);
	date();
	friend ostream& operator<<(ostream&, date);
	void set_date(int);
	void set_month(int);
	void set_year(int);
	int get_date();
	int get_month();
	int get_year();
};

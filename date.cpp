#include "date.h"
#include <ctime>
date::date(int d, int m, int y)
{
	set_date(d);//current date 
	set_month(m);//current month
	set_year(y);//current year
}
date::date()
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	set_year(1900 + newtime.tm_year);
	set_month(1 + newtime.tm_mon);
	set_date(newtime.tm_mday);
}
ostream& operator<<(ostream& osObject, date D)
{
	cout << D.Date << "/" << D.month << "/" << D.year;
	return osObject;
}
void date::set_date(int d)
{
	Date = d;
}
void date::set_month(int m)
{
	month = m;
}
void date::set_year(int y)
{
	year = y;
}
int date::get_date()
{
	return Date;
}
int date::get_month()
{
	return month;
}
int date::get_year()
{
	return year;
}
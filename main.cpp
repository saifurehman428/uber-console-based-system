#include <iostream>
#include <fstream>
#include <string>
#include "payment.h"
#include "driver.h"
#include "date.h"
#include "passanger.h"
#include "trip.h"
using namespace std;

const int SIZE = 20;
//an array of trips to keep pointers of all the trips of uber application
//This array will keep data of all the trips ever created. 
trip** uberTrips = new trip * [SIZE];
int n = 0;
void addToUberTrips(trip* t)// function to add new trips to uberTrips
{
	if (n < SIZE - 1 && t != nullptr)
	{
		uberTrips[n++] = t;
	}
}
void printUberTrips() //function to print uberTrips
{
	cout << "\n\nThere are total " << n << " trips on uber server\n\n";
	for (int i = 0; i < n; i++)
	{
		cout << i << " " << *uberTrips[i] << endl;
	}
}
user** usersArray = new user * [SIZE];
int users_count = 0;
void addToUsersArray(user *u)
{
	if (users_count < SIZE && u != nullptr)
	{
		usersArray[users_count++] = u;
	}
}
void printUsersArray() 
{
	cout << "\n\nThese are the "<<users_count<<" users on uber server\n\n";
	for (int i = 0; i < users_count; i++)
	{
		cout << i <<" ";
		usersArray[i]->print();
		cout << endl;
	}
}
void loadFile(string file_name)
{
	ifstream inFile;
	inFile.open(file_name);
	string temp;
	user* U;
	while (!inFile.eof())
	{
		getline(inFile, temp, ',');
		if (temp == "p")
		{
			U = new passanger();
			getline(inFile, temp, ',');
			U->change_name(temp);
			getline(inFile, temp, '-');
			date d;
			d.set_date(stoi(temp));
			getline(inFile, temp, '-');
			d.set_month(stoi(temp));
			getline(inFile, temp, ',');
			d.set_year(stoi(temp));
			U->change_DOB(d);
			getline(inFile, temp, ',');
			U->change_email(temp);
			getline(inFile, temp, '\n');
			U->change_phone_number(temp);
			addToUsersArray(U);
			U = nullptr;
		}
		else if(temp == "d")
		{
			U = new driver();
			getline(inFile, temp, ',');
			U->change_name(temp);
			getline(inFile, temp, '-');
			date d;
			d.set_date(stoi(temp));
			getline(inFile, temp, '-');
			d.set_month(stoi(temp));
			getline(inFile, temp, ',');
			d.set_year(stoi(temp));
			U->change_DOB(d);
			getline(inFile, temp, ',');
			U->change_email(temp);
			getline(inFile, temp, '\n');
			U->change_phone_number(temp);
			addToUsersArray(U);
			U = nullptr;
		}
	}
}
user* highlyrated()
{
	cout << "\n\nHighly rated user is\n\n";
	user* temp = usersArray[0];
	for  ( int i = 2; i < users_count; i++)
	{
		if (temp->getAvgRating() < usersArray[i]->getAvgRating())
		{
			temp = usersArray[i];
		}
	}
	return temp;
}
user* highlyrated_driver()
{
	cout << "\n\nHighly rated driver is\n\n";
	driver* temp1;
	driver* temp2;
	user* highlyrated;
	for (int i = 0; i < users_count; i++)
	{
		temp1 = dynamic_cast<driver*>(usersArray[i]);
		if (temp1 != nullptr)
		{
			highlyrated = temp1;
			for (int j = i+1; j < users_count; j++)
			{
				if (temp1->getAvgRating() < usersArray[j]->getAvgRating())
				{
					temp2 = dynamic_cast<driver*>(usersArray[j]);
					if (temp2 != nullptr)
					{
						highlyrated = usersArray[j];
					}
				}
			}
			return highlyrated;
			break;
		}
	}
	return nullptr;
}
void de_allocate_users()
{
	for (int i = 0; i < users_count; i++)
	{
		passanger* temp_pass = dynamic_cast<passanger*>(usersArray[i]);
		driver* temp_driv = dynamic_cast<driver*>(usersArray[i]);
		if (temp_pass != nullptr)
		{
			delete temp_pass;
		}
		else if (temp_driv)
		{
			delete temp_driv;
		}
	}
	delete usersArray;
}
void de_allocate_trips()
{
	for (int i = 0; i < n; i++)
	{
		delete *(uberTrips+i);
	}
	delete uberTrips;
}

void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	passanger* p1 = new passanger("P1", date(10, 10, 1990), "ali@yahoo.com", "0334564334", payment("111-222-333-333", "card"));
	driver* d1 = new driver("D1", date(16, 1, 1990), "ayesha@yahoo.com", "0357757585", "Lin1197717", "VIN9817917");

	//////Test Case 1, user books, driver picks, driver ends (rating can be given only in this case)
	cout << *p1 << endl;
	cout << *d1 << endl;

	addToUberTrips(p1->bookRide("A", "B"));// will create a new trip and add it to uberTrips array
	cout << *uberTrips[n - 1];// will print this trip
	addToUberTrips(p1->bookRide("C", "D"));//prints error as p1 has already booked a ride
	d1->pickARide(uberTrips[n - 1]); //will assign  d1 to uberTrip[0], the status of this ride will also change to InProgress
	d1->ratePassanger(uberTrips[n - 1], 5); //error as the trip is not complete
	p1->rateDriver(uberTrips[n - 1], 4); //error as the trip is not complete

	cout << *p1 << endl;
	cout << *d1 << endl;

	d1->endARide(); //will change the status of uberTrip[0] to Complete

	d1->ratePassanger(uberTrips[n - 1], 5); //error as the trip is not complete
	p1->rateDriver(uberTrips[n - 1], 4); //error as the trip is not complete
	cout << *uberTrips[n - 1] << endl;
	cout << *p1 << endl;
	cout << *d1 << endl;
	d1->pickARide(uberTrips[n - 1]);//prints error as the ride is completed
	cout << "-------------------------------------" << endl;



	//////Test case 2: User books, driver picks, user cancels, ratings are not applicable to cancelled ride
	addToUberTrips(p1->bookRide("C", "D"));
	d1->pickARide(uberTrips[n - 1]);
	cout << *p1 << endl;
	cout << *d1 << endl;
	p1->cancelRide();
	p1->cancelRide();//error as there is no current ride
	cout << *p1 << endl;
	cout << *d1 << endl;
	d1->ratePassanger(uberTrips[n - 1], 5); //error as the ride was not complete
	p1->rateDriver(uberTrips[n - 1], 5); //error as the ride was not complete
	cout << "-------------------------------------" << endl;


	////Test Case 3: User Books, user Cancels, driver cannot pick this ride now, ratings are not applicable to this ride
	addToUberTrips(p1->bookRide("D", "E"));
	p1->cancelRide();
	d1->pickARide(uberTrips[n - 1]); //error as this ride is not looking for driver
	d1->ratePassanger(uberTrips[n - 1], 5); //error as the ride was not complete
	p1->rateDriver(uberTrips[n - 1], 5); //error as the ride was not complete
	cout << "-------------------------------------" << endl;

	////Test Case 4: getting avg ratings adn print trip funnction
	//Adding some more test data
	addToUberTrips(p1->bookRide("X", "Y"));
	d1->pickARide(uberTrips[n - 1]);
	d1->endARide();
	d1->ratePassanger(uberTrips[n - 1], 3);
	p1->rateDriver(uberTrips[n - 1], 5);

	addToUberTrips(p1->bookRide("X", "Y"));
	d1->pickARide(uberTrips[n - 1]);
	d1->endARide();
	d1->ratePassanger(uberTrips[n - 1], 6);//error as the rating is not between 1 and 5 
	d1->ratePassanger(uberTrips[n - 1], 4);
	d1->ratePassanger(uberTrips[n - 1], 3);// will upate the passanging rating from 4 to 3
	p1->rateDriver(uberTrips[n - 1], 1);

	p1->printTrips();
	d1->printTrips();
	cout << p1->getAvgRating() << endl;
	cout << d1->getAvgRating() << endl;

	/***********************************MODULE 3*************************************/
	loadFile("data.txt");
	addToUberTrips(usersArray[0]->bookRide("F", "G"));
	usersArray[1]->pickARide(uberTrips[n - 1]);
	usersArray[1]->endARide();
	usersArray[0]->rate(uberTrips[n - 1], 5);
	usersArray[1]->rate(uberTrips[n - 1], 4);
	addToUberTrips(usersArray[2]->bookRide("Q", "W"));
	usersArray[1]->pickARide(uberTrips[n - 1]);
	usersArray[1]->endARide();
	usersArray[2]->rate(uberTrips[n - 1], 4);
	usersArray[1]->rate(uberTrips[n - 1], 3);
	addToUberTrips(usersArray[5]->bookRide("O", "P"));
	usersArray[1]->pickARide(uberTrips[n - 1]);
	usersArray[1]->endARide();
	usersArray[5]->rate(uberTrips[n - 1], 5);
	usersArray[1]->rate(uberTrips[n - 1], 4);
	addToUsersArray(d1);
	addToUsersArray(p1);
	printUberTrips();
	highlyrated()->print();
	highlyrated_driver()->print();
	printUsersArray();
	cout << "n = " << n << endl;
	de_allocate_users();
	de_allocate_trips();
}
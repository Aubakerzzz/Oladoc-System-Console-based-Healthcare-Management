#pragma once
#include "Feedback.h"
#include "Appointment.h"
#include "Oladoc.h"
#include "Person.h"
#include "ContactInformation.h"
#include "Credentials.h"
#include<iostream>
using namespace std;

class Doctor :public Person {
private:
	string category;
	string ratings;
	string hourlyCharge;
	string availability;
	string objType = "Doctor";
public:
	
	virtual string getobjType();
	void set_Category(string category);
	void set_Ratings(string ratings);
	void hourly_charge(string hour);
	virtual string get_Category()const;
	string get_Ratings()const;
	virtual string get_hourly_charge()const;
	string available();
	virtual void insertData(string name, string gender, string dob, string cNIC, string city, string username, string password, string phoneNumber, string email, string address, string category, string ratings, string hourlyCharge, string availability);
	virtual void display();
	
};

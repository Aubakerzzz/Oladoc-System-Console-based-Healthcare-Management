#pragma once
#include "Feedback.h"
#include "Appointment.h"
#include "Oladoc.h"
#include "Person.h"
#include "ContactInformation.h"
#include "Credentials.h"
#include<iostream>
using namespace std;

class Admin:public Person {
private:
	string objTypeAdmin = "Admin";
public:

	virtual string getobjType();
	virtual void insertData(string name, string gender, string dob, string cNIC, string city, string username, string password, string phoneNumber, string email, string address);
	virtual void display();
	
};





#pragma once
#include<iostream>
using namespace std;
#include <string>

class ContactInformation {
private:

	string phoneNumber;
	string email;
	string adress;
public:
	ContactInformation();
	void setPhoneNumber(string phone_number);
	void setEmail(string email);
	void setAddress(string adress);
	string  getPhoneNumber()const;
	string getEmail()const;
	string getAddress()const;
	void populate(string email, string phoneNumber, string address);


};


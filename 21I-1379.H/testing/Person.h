#pragma once
#include<iostream>
using namespace std;
#include<string>
#include "ContactInformation.h"
#include "Credentials.h"

class Person {
protected:
	string name;
	string gender;
	string dob;
	string cNIC;
	string city;
	Credentials credential;
	ContactInformation contact;
public:
	void setName(string name);
	void setGender(string gender);
	void setDate(string date);
	void setCNIC(string cnic);
	void setCity(string city);
	string getName()const;
	string getGender()const;
	string getDate()const;
	string getCNIC()const;
	string getCity()const;
	ContactInformation getContactInformation();
	Credentials getCredentials();
	virtual void insertData(string name, string gender, string dob, string cNIC, string city, string username, string password, string phoneNumber, string email, string address, string patientBalance){}
	virtual void insertData(string name, string gender, string dob, string cNIC, string city, string username, string password, string phoneNumber, string email, string address, string category, string ratings, string hourlyCharge, string availability){}
	virtual void insertData(string name, string gender, string dob, string cNIC, string city, string username, string password, string phoneNumber, string email, string address) {}
	virtual void display(){}
	virtual string getobjType();
	virtual string get_hourly_charge()const { return ""; }
	virtual void updatePatientBalance(int balance){}
	virtual string get_Category()const { return ""; }
};



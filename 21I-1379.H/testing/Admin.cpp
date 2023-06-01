#include "Admin.h"
#include "Feedback.h"
#include "Appointment.h"
#include "Oladoc.h"
#include "Person.h"
#include "ContactInformation.h"
#include "Credentials.h"
#include<iostream>
using namespace std;


string Admin::getobjType() {
	return this->objTypeAdmin;
}


void Admin::insertData(string name, string gender, string dob, string cNIC, string city, string username, string password, string phoneNumber, string email, string address) {
	
	// Inserting Data For Admin
	this->name = name;
	this->gender = gender;
	this->dob = dob;
	this->cNIC = cNIC;
	this->city = city;
	this->credential.populate(username, password);
	this->contact.populate(email, phoneNumber, address);
}

void Admin::display() {

	// Displaying Data For Admin
	cout << "====================================" << endl;
	cout << "Name" << this->name << endl;
	cout << "Gender" << this->gender << endl;
	cout << "Date Of Birth" << this->dob << endl;
	cout << "CNIC" << this->cNIC << endl;
	cout << "CITY" << this->city << endl;
	cout << "User Name" << this->credential.getUserName() << endl;
	cout << "Password" << this->credential.getPassword() << endl;
	cout << "Email" << this->contact.getEmail() << endl;
	cout << "PhoneNumber" << this->contact.getPhoneNumber() << endl;
	cout << this->contact.getAddress() << endl;
	cout << "====================================" << endl;
}
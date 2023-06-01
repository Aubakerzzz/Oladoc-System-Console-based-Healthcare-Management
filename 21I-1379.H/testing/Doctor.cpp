#include "Doctor.h"
#include "Feedback.h"
#include "Appointment.h"
#include "Oladoc.h"
#include "Person.h"
#include "ContactInformation.h"
#include "Credentials.h"
#include<iostream>
using namespace std;

string Doctor::getobjType() {
	return this->objType;
}

void Doctor::set_Category(string category) {
	this->category = category;
}

void Doctor::set_Ratings(string ratings) {
	this->ratings = ratings;
}

void Doctor::hourly_charge(string hour) {
	hourlyCharge = hour;
}

string Doctor::available() {
	return availability;
}


string Doctor::get_Category()const {
	return category;
}

string Doctor::get_Ratings()const {
	return ratings;
}

string Doctor::get_hourly_charge()const {
	return hourlyCharge;
}


void Doctor::insertData(string name, string gender, string dob, string cNIC, string city, string username, string password, string phoneNumber, string email, string address, string category, string ratings, string hourlyCharge, string availability) {
	
	//Setting Data For Patient
	this->name = name;
	this->gender = gender;
	this->dob = dob;
	this->cNIC = cNIC;
	this->city = city;
	this->contact.populate(email, phoneNumber, address);
	this->credential.populate(username, password);
	this->category = category;
	this->ratings = ratings;
	this->hourlyCharge = hourlyCharge;
	this->availability = availability;
 }

void Doctor::display(){

	// Displaying Credentials Of Doctor
	cout << "==========================================" << endl;
	cout << "Name" << this->name << endl;
	cout << "Gender" << this->gender << endl;
	cout << "Date Of Birth" << this->dob << endl;
	cout << "CNIC" << this->cNIC << endl;
	cout << "City"<< this->city << endl;
	cout << "User Name" << this->credential.getUserName() << endl;
	cout << "Password" << this->credential.getPassword() << endl;
	cout << "Email" << this->contact.getEmail() << endl;
	cout << "PhoneNumber" << this->contact.getPhoneNumber() << endl;
	cout << "Address" << this->contact.getAddress() << endl;
	cout << "Category" << this->category << endl;
	cout << "Ratings" << this->ratings << endl;
	cout << "Hourly Charge" << this->hourlyCharge << endl;
	cout << "Avaiability" << this->availability << endl;
	cout << "============================================" << endl;
}
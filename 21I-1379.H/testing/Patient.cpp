#include "Patient.h"
#include "Doctor.h"
#include "Feedback.h"
#include "Appointment.h"
#include "Person.h"
#include "ContactInformation.h"
#include "Credentials.h"
#include<iostream>
using namespace std;

string Patient::getobjType() {
	return objTypePatient;
}

void Patient::setPatientBalance(int balance) {
	this->patientBalance = balance;
}

int Patient::getPatientBalance()const {
	return patientBalance;
}

void Patient::insertData(string name, string gender, string dob, string cNIC, string city, string username, string password, string phoneNumber, string email, string address, string patientBalance) {
	
	// Inserting Data for Patient
	this->name = name;
	this->gender = gender;
	this->dob = dob;
	this->cNIC = cNIC;
	this->city = city;
	this->credential.populate(username, password);
	this->contact.populate(email, phoneNumber, address);
	this->patientBalance = stoi(patientBalance);
}

void Patient::display() {
	// Displaying Credentials Of Patient
	cout << "============================================" << endl;
	cout << "Name:" << this->name << endl;
	cout << "Gender:" << this->gender << endl;
	cout << "Date Of Birth:" << this->dob << endl;
	cout << "CNIC" << this->cNIC << endl;
	cout << "City" << this->city << endl;
	cout << "User Name:" << this->credential.getUserName() << endl;
	cout << "Password:" << this->credential.getPassword() << endl;
	cout << "Email:"<< this->contact.getEmail() << endl;
	cout << "PhoneNumber" << this->contact.getPhoneNumber() << endl;
	cout << "Address" << this->contact.getAddress() << endl;
	cout << "Patient Balance:" << this->patientBalance << endl;
	cout << "============================================" << endl;
}

void Patient::updatePatientBalance(int balance) {
	this->patientBalance += balance;
}
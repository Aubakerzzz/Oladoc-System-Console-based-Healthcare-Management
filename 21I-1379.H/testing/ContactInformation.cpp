#include "ContactInformation.h"
#include "Credentials.h"
#include "Person.h"


ContactInformation::ContactInformation() {

	phoneNumber = "";
	email = "";
	adress = "";

}

void ContactInformation::setPhoneNumber(string phone_number) {
	this->phoneNumber = phone_number;
}

void ContactInformation::setEmail(string email) {
	this->email = email;
}

void ContactInformation::setAddress(string adress) {
	this->adress = adress;
}


string ContactInformation::getPhoneNumber()const {
	return phoneNumber;
}

string ContactInformation::getEmail()const {
	return email;
}

string ContactInformation::getAddress()const {
	return adress;
}


void ContactInformation::populate(string email, string phoneNumber, string address) {
	//Setting Data 
	this->email = email;
	this->phoneNumber = phoneNumber;
	this->adress = address;
}


#include "Person.h"
#include "ContactInformation.h"
#include "Credentials.h"

void Person::setName(string name) {
	this->name = name;
}

void Person::setGender(string gender) {
	this->gender = gender;

}

void Person::setDate(string date) {
	this->dob = date;

}

void Person::setCNIC(string cnic) {
	this->cNIC = cnic;
}

void  Person::setCity(string city) {
	this->city = city;
}

string Person::getName()const {
	return name;
}

string Person::getGender()const {
	return gender;
}

string Person::getDate()const {
	return dob;
}

string Person::getCNIC()const {
	return cNIC;
}

string Person::getCity()const {
	return city;
}

ContactInformation Person::getContactInformation() {

	return this->contact;

}

Credentials Person::getCredentials() {

	return this->credential;

}

string Person::getobjType() {

	return "Person";
}

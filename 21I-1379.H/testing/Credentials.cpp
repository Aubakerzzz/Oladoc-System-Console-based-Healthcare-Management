#include "Credentials.h"
#include "ContactInformation.h"
#include "Person.h"


Credentials::Credentials() {

	userName = "";
	password = "";

}

void Credentials::setUserName(string userName) {
	this->userName = userName;
}

void Credentials::setPassword(string password) {
	this->password = password;
}


string Credentials::getUserName()const {
	return userName;
}

string Credentials::getPassword()const {
	return password;
}


void Credentials::populate(string username, string password) {
	this->userName = username;
	this->password = password;
}


#include "Payment.h"
#include "Appointment.h"
#include "Oladoc.h"
#include "Person.h"
#include "ContactInformation.h"
#include "Credentials.h"
#include<iostream>
using namespace std;


void Payment::set_paymentAmount(string amount) {
	this->paymentAmount = amount;
}
void Payment::set_paymentType(string type) {
	this->paymentType = type;
}
void Payment::set_status(string status) {
	this->Status = status;
}
string Payment::get_paymentAmount()const {
	return paymentAmount;
}
string Payment::get_paymentType()const {
	return paymentType;
}
string Payment::get_status() {
	return this->Status;
}



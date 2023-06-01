#include "Appointment.h"
#include "Oladoc.h"
#include "Person.h"
#include "ContactInformation.h"
#include "Credentials.h"
#include<iostream>
using namespace std;


void Appointment::set_ID(string id) {
	this->appointmentID = id;
}

string  Appointment::get_ID()const {
	return appointmentID;
}
void Appointment::set_Time(string time) {
	this->appointmentTime = time;
}
string Appointment::get_Time()const {
	return appointmentTime;
}

void Appointment::set_Status(string status) {
	this->appointmentStatus = status;
}
string Appointment::get_Status()const {
	return appointmentStatus;
}

void Appointment::set_appointment(string appointmentID, string appointmentTime, string paymentAmount, string paymentType, string paymentStatus, string FeedbackRating, string FeedbackReview, Person* patient, Person* doctor) {
	this->appointmentID = appointmentID;
	this->appointmentTime = appointmentTime;
	this->payment.set_paymentAmount(paymentAmount);
	this->payment.set_paymentType(paymentType);
	this->payment.set_status(paymentStatus);
	this->patient = patient;
	this->doctor = doctor;
	this->feedback.setfeedBackRating(FeedbackRating);
	this->feedback.setfeedbackReview(FeedbackReview);
}

void Appointment::displayAppointments() {
	cout << "Appointment ID: " << this->appointmentID << endl;
	cout << "Appointment Date/Time: " << this->appointmentTime << endl;
	cout << "Appointment Status: " << this->appointmentStatus << endl;
	cout << "Doctor Name: " << this->doctor->getName() << endl;
	cout << "Patient Name: " << this->patient->getName() << endl;
	cout << "Payment Amount: " << this->payment.get_paymentAmount() << endl;
	cout << "Payment Status: " << this->payment.get_status() << endl;
	cout << "Payment Type: " << this->payment.get_paymentType() << endl;
	cout << "Feedback Rating: " << this->feedback.getFeedBackRating() << endl;
	cout << "Feedback Review: " << this->feedback.getFeedBackReview() << endl;
}

void Appointment::viewAppointment() {
	cout << "Appointment ID: " << this->appointmentID << endl;
	cout << "Appointment Date/Time: " << this->appointmentTime << endl;
	cout << "Appointment Status: " << this->appointmentStatus << endl;
	cout << "Patient Name: " << this->patient->getName() << endl;
}

Person* Appointment::getPatient() {
	return this->patient;
}

Person* Appointment::getDoctor() {
	return this->doctor;
}
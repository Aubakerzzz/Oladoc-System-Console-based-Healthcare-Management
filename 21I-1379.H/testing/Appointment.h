#pragma once
#include "Person.h"
#include "ContactInformation.h"
#include "Credentials.h"
#include "Payment.h"
#include "Feedback.h"
#include<iostream>
using namespace std;

class Appointment {
private:
	static int id;
	string appointmentID;
	string appointmentTime;
	string appointmentStatus;
	Person* patient;
	Person* doctor;
	Payment payment;
	Feedback feedback;

public:
	void set_ID(string id);
	string get_ID()const;
	void set_Time(string time);
	string get_Time()const;
	void set_Status(string status);
	string get_Status()const;
	void set_appointment(string appointmentID, string appointmentTime, string paymentAmount, string paymentType, string paymentStatus, string FeedbackRating, string FeedbackReview, Person* patient, Person* doctor);
	void displayAppointments();
	void viewAppointment();
	Person* getPatient();
	Person* getDoctor();
	Feedback getFeedback() { return this->feedback; }
};


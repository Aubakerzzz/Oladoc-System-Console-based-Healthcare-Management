#pragma once
#include "Doctor.h"
#include "Feedback.h"
#include "Appointment.h"
#include "Oladoc.h"
#include "Person.h"
#include "ContactInformation.h"
#include "Credentials.h"
#include<iostream>
using namespace std;

class Patient:public Person{
private:
	int patientBalance = 0;
	string objTypePatient = "Patient";
public:
	virtual string getobjType();
	void setPatientBalance(int balance);
	int getPatientBalance()const;
	virtual void insertData(string name, string gender, string dob, string cNIC, string city, string username, string password, string phoneNumber, string email, string address, string patientBalance);
	virtual void display();
	virtual void updatePatientBalance(int balance);
};


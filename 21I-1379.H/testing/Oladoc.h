#pragma once
#include<iostream>
using namespace std;
#include "Person.h"
#include"Admin.h"
#include "Appointment.h"
#include "ContactInformation.h"
#include "Credentials.h"

class Oladoc {
private:
	Person* person[10];
	int counter = 0;
	Appointment appointment[25];
	int appointmentsCount = 0;
	Person* currentPerson = NULL;
	

public:
	
	void Admin_Data_File();
	void Patient_Data_File();
	void Doctor_Data_File();
	void Appointment_Data_File();

	int get_counter();
	void display();

	bool validateAdminCredentials(string username, string password);
	bool validatePatientCredentials(string userName, string password);
	bool validateDoctorCredentials(string username, string password);
	
	void registerPatient();
	void registerDoctor();

	void loginAdmin();
	void loginPatient();
	void loginDoctor();

	void bookAppointment();
	void cancelAppointment();
	void viewAppointmentsHistory();
	void searchDoctors();
	void giveFeedback();

	void displayCurrentUser();


	//admin control
	void viewPatients();
	void viewDoctors();
	void viewAppointments();

	//doctor control
	void manageAppointments();

};

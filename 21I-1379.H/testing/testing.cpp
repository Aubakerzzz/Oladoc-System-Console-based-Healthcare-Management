#include<iostream>
#include<fstream>
#include<string>
#include"Oladoc.h"
using namespace std;


int main() {

	int option;
	Oladoc ola;

	//Loading the data from the file into the system
	ola.Admin_Data_File();
	ola.Doctor_Data_File();
	ola.Patient_Data_File();
	ola.Appointment_Data_File();


	while (true) {

		cout << "==============================================" << endl
			<< "Enter (1) to Register User as Patient" << endl
			<< "Enter (2) to Register User as Doctor" << endl
			<< "Enter (3) to Login as Admin" << endl
			<< "Enter (4) to Login as Patient" << endl
			<< "Enter (5) to Login as Doctor" << endl
			<< "Enter (6) to Exit" << endl
			<< "Your option: ";
		cin >> option;
		cout << "==============================================" << endl;

		if (option == 1) {
			ola.registerPatient();
		}
			
		if (option == 2) {
			ola.registerDoctor();
		}

		if (option == 3) {
			ola.loginAdmin();
			while (true) {
				int menuOption;
				cout << "==============================================" << endl;
				cout << "Enter (1) to view all patients data" << endl
					<< "Enter (2) to view all doctors data" << endl
					<< "Enter (3) to view all appointments data" << endl
					<< "Enter (4) to logout" << endl
					<< "Enter (5) to  view profile" << endl
					<< "Your option: ";
				cin >> menuOption;
				cout << "==============================================" << endl;
				if (menuOption == 1) {
					ola.viewPatients();
				}
				else if (menuOption == 2) {
					ola.viewDoctors();
				}
				else if (menuOption == 3) {
					ola.viewAppointments();
				}
				else if (menuOption == 4) {
					break;
				}
				else if (menuOption == 5) {
					ola.displayCurrentUser();
				}
			}
		}
			
		if (option == 4) {
			ola.loginPatient();
			while (true) {
				int menuOption;
				//Giving Option to user For Appointment , Feedback and if User want to exit
				cout << "==============================================" << endl;
				cout << "Enter (1) to book appointment" << endl
					<< "Enter (2) to cancel appointment" << endl
					<< "Enter (3) to view appointments history" << endl
					<< "Enter (4) to search doctors" << endl
					<< "Enter (5) to give feedback" << endl
					<< "Enter (6) to logout" << endl
					<< "Enter (7) to  view profile" << endl
					<< "Your option: ";
				cin >> menuOption;
				cout << "==============================================" << endl;

				if (menuOption == 1) {
					ola.bookAppointment();
				}
				else if (menuOption == 2) {
					ola.cancelAppointment();
				}
				else if (menuOption == 3) {
					ola.viewAppointmentsHistory();
				}
				else if (menuOption == 4) {
					ola.searchDoctors();
				}
				else if (menuOption == 5) {
					ola.giveFeedback();
				}
				else if (menuOption == 6) {
					break;
				}
				else if (menuOption == 7) {
					ola.displayCurrentUser();
				}
			}
		}
			

		if (option == 5) {
			ola.loginDoctor();
			while (true) {
				int menuOption;
				//Giving Option to user For Appointment , Feedback and if User want to exit
				cout << "==============================================" << endl
					<< "Enter (1) to view the profile" << endl
					<< "Enter (2) to view the appointments history" << endl
					<< "Enter (3) to check pending appointments" << endl
					<< "Enter (4) to logout" << endl
					<< "Your option: ";
				cin >> menuOption;
				cout << "==============================================" << endl;
				if (menuOption == 1) {
					ola.displayCurrentUser();
				}
				else if (menuOption == 2) {
					ola.viewAppointmentsHistory();
				}
				else if (menuOption == 3) {
					ola.manageAppointments();
				}
				else if (menuOption == 4) {
					break;
				}
			}
		}
			
		if (option == 6) {
			break; 
		}
	
	}
	return 0;
}



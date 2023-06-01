#include "Oladoc.h"
#include "Person.h"
#include "ContactInformation.h"
#include "Credentials.h"
#include "Admin.h"
#include "Patient.h"
#include "Doctor.h"
#include <string>
#include <fstream>
#include<iostream>
using namespace std;




bool Oladoc::validateDoctorCredentials(string username, string password) {
	Person* temp = new  Doctor;
	for (int i = 0; i < this->counter; i++) {
		if (this->person[i]->getobjType() == "Doctor") {
			temp = this->person[i];
			//Checking for credentials of User
			if (temp->getCredentials().getUserName() == username && temp->getCredentials().getPassword() == password) {
				this->currentPerson = temp;
				return true;
			}
		}
	}
	return false;
}


bool Oladoc::validatePatientCredentials(string userName, string password) {
	//object of person for Patient 
	Person* temp = new  Patient;
	//Cheking for person user name 
	for (int i = 0; i < this->counter; i++) {
		if (this->person[i]->getobjType() == "Patient") {
			temp = this->person[i];
			// giving true if userName and password are Valid
			if (temp->getCredentials().getUserName() == userName && temp->getCredentials().getPassword() == password) {
				this->currentPerson = temp;
				return true;
			}
		}
	}
	return false;
}

bool Oladoc::validateAdminCredentials(string username, string password) {
	// object of person for Admin
	Person* temp = new Admin;
	for (int i = 0; i < this->counter; i++) {
		if (this->person[i]->getobjType() == "Admin") {
			temp = this->person[i];
			// giving true if userName and password are Valid
			if (temp->getCredentials().getUserName() == username && temp->getCredentials().getPassword() == password) {
				this->currentPerson = temp;
				return true;
			}
		}
	}
	return false;
}


int Oladoc::get_counter() {
	return this->counter;
}

void Oladoc::Admin_Data_File() { // Reading and Writing From File

	string arrays[15] = { "" };
	int tempCounter = 0;
	//reading from the file
	ifstream inputFile("Admin.txt");
	while (!inputFile.eof()) {
		getline(inputFile, arrays[tempCounter]);
		arrays[tempCounter++] += ",";
		if (inputFile.eof())
			break;
	}
	inputFile.close();
	//storing the parsed data from the file of all the admins
	string parsedArrays1[15][10] = { "" };
	for (int i = 0; i < tempCounter; i++) {
		int count = 0;
		for (int j = 0; j < arrays[i].length(); j++) {
			if (arrays[i][j] != ',') {
				parsedArrays1[i][count] += arrays[i][j];
			}
			else {
				count++;
			}
		}
	}

	//creating the object and storing the data into them
	for (int i = 0; i < tempCounter; i++) {
		person[this->counter] = new Admin;
		person[this->counter]->insertData(parsedArrays1[i][0], parsedArrays1[i][1], parsedArrays1[i][2], parsedArrays1[i][3], parsedArrays1[i][4], parsedArrays1[i][5], parsedArrays1[i][6], parsedArrays1[i][7], parsedArrays1[i][8], parsedArrays1[i][9]);
		this->counter++;
	}

}

void Oladoc::Patient_Data_File() {
	string arrays[15] = { "" };
	int tempCounter = 0;
	//reading from the file
	ifstream inputFile("Patient.txt");
	while (!inputFile.eof()) {
		getline(inputFile, arrays[tempCounter]);
		arrays[tempCounter++] += ",";
		if (inputFile.eof())
			break;
	}
	inputFile.close();
	//storing the parsed data from the file of all the patients
	string parsedArrays2[15][11] = { "" };
	for (int i = 0; i < tempCounter; i++) {
		int count = 0;
		for (int j = 0; j < arrays[i].length(); j++) {
			if (arrays[i][j] != ',') {
				parsedArrays2[i][count] += arrays[i][j];
			}
			else {
				count++;
			}
		}
	}
	
	//creating the object and sotring the data into them
	for (int i = 0; i < tempCounter; i++) {
		person[this->counter] = new Patient;
		person[this->counter]->insertData(parsedArrays2[i][0], parsedArrays2[i][1], parsedArrays2[i][2], parsedArrays2[i][3], parsedArrays2[i][4], parsedArrays2[i][5], parsedArrays2[i][6], parsedArrays2[i][7], parsedArrays2[i][8], parsedArrays2[i][9], parsedArrays2[i][10]);
		this->counter++;
	}	

}

void Oladoc::Doctor_Data_File() {
	string arrays[15] = { "" };
	int tempCounter = 0;
	//reading from the file
	ifstream inputFile("Doctor.txt");
	while (!inputFile.eof()) {
		getline(inputFile, arrays[tempCounter]);
		arrays[tempCounter++] += ",";
		if (inputFile.eof())
			break;
	}
	inputFile.close();
	//storing the parsed data from the file of all the doctors
	string parsedArrays3[15][14] = { "" };
	for (int i = 0; i < tempCounter; i++) {
		int count = 0;
		for (int j = 0; j < arrays[i].length(); j++) {
			if (arrays[i][j] != ',') {
				parsedArrays3[i][count] += arrays[i][j];
			}
			else {
				count++;
			}
		}
	}
	//creating the object and sotring the data into them
	for (int i = 0; i < tempCounter; i++) {
		person[this->counter] = new Doctor;
		person[this->counter]->insertData(parsedArrays3[i][0], parsedArrays3[i][1], parsedArrays3[i][2], parsedArrays3[i][3], parsedArrays3[i][4], parsedArrays3[i][5], parsedArrays3[i][6], parsedArrays3[i][7], parsedArrays3[i][8], parsedArrays3[i][9], parsedArrays3[i][10], parsedArrays3[i][11], parsedArrays3[i][12], parsedArrays3[i][13]);
		this->counter++;
	}
}

void Oladoc::display() {
	for (int i = 0; i < this->counter; i++) {
		this->person[i]->display();
		cout << endl;
	}
}


void Oladoc::registerPatient() {

	string email_Patient;
	string password_Patient;
	string name;
	string gender;
	string dob;
	string cNIC;
	string city;
	string username;
	string phoneNumber;
	string address;
	string patientBalance;
	bool flags1 = false;
	bool flags2 = false;
	bool flags3 = false;
	bool flag1 = false;
	bool flag2 = false;
	int tempSize = 0;

	cout << "Enter Name" << endl;
	cin >> name;
	cout << "Enter Gender" << endl;
	cin >> gender;
	cout << "Enter Date Of Birth" << endl;
	cin >> dob;
	cout << "Enter city" << endl;
	cin >> city;
	cout << "Enter UserName" << endl;
	cin >> username;
	cout << "Enter Address" << endl;
	cin >> address;
	int initialpatientBalance = 0;
	patientBalance = "3500";
	initialpatientBalance = stoi(patientBalance);

	cout << "Enter Phone Number" << endl;
	cin >> phoneNumber;

	do {
		cout << "Enter CNIC" << endl;
		cin >> cNIC;
		if (cNIC.length() < 13)
			cout << "In-valid CNIC" << endl;
	} while (cNIC.length() < 13);
	do {
		cout << "Enter Email " << endl;
		cin >> email_Patient;
		for (int i = 0; i < email_Patient.length(); i++) {
			if (email_Patient[i] == '@')
				flag1 = true;
		}
		tempSize = email_Patient.size() - 4;
		// input validation
		if ((email_Patient[tempSize] == '.') && (email_Patient[tempSize + 1] == 'c') && (email_Patient[tempSize + 2] == 'o') && (email_Patient[tempSize + 3] == 'm'))
			flag2 = true;
		// input validation
		if ((flag1 == false) || (flag2 == false)) {
			cout << "Invalid Email" << endl;
			cout << "Re-Enter the Email" << endl;
		}
		// input validation
	} while ((flag1 == false) || (flag2 == false));
	do {
		cout << "Enter Password" << endl;
		cin >> password_Patient;

		for (int i = 0; i < password_Patient.length(); i++) {
			// input validation
			if (password_Patient[i] >= 97 && password_Patient[i] <= 122)
				flags1 = true;
			// input validation
			if (password_Patient[i] >= 65 && password_Patient[i] <= 97)
				flags2 = true;
			// input validation
			if ((password_Patient[i] >= 32 && password_Patient[i] <= 47) || (password_Patient[i] >= 58 && password_Patient[i] <= 64) || (password_Patient[i] >= 91 && password_Patient[i] <= 96) || (password_Patient[i] >= 123 && password_Patient[i] <= 126))
				flags3 = true;
		}
		// input validation
		if ((flags1 == false) || (flags2 == false) || (flags3 == false)) {
			cout << "Invalid Password" << endl;
			cout << "Re-Enter the Password" << endl;
		}
		// input validation
	} while ((flags1 == false) || (flags2 == false) || (flags3 == false));

	string temp1;
	temp1 = name + "," + gender + "," + dob + "," + cNIC + "," + city + "," + username + "," + password_Patient + "," + phoneNumber + "," + email_Patient + "," + address + "," + to_string(initialpatientBalance);
	
	//Appending data in file 
	ofstream patientFile;
	patientFile.open("Patient.txt", ios_base::app);
	patientFile << endl << temp1;

	patientFile.close();

	//creating new patient as well
	person[this->counter] = new Patient;
	person[this->counter]->insertData(name,gender, dob, cNIC, city, username, password_Patient, phoneNumber, email_Patient, address, to_string(initialpatientBalance));
	this->counter++;

}

void Oladoc::registerDoctor() {

	string email_Doctor;
	string password_Doctor;
	string name;
	string gender;
	string dob;
	string cNIC;
	string city;
	string username;
	string phoneNumber;
	string address;
	string category;
	string ratings;
	string hourlyCharge;
	string availability;
	bool flags1 = false;
	bool flags2 = false;
	bool flags3 = false;
	bool flag1 = false;
	bool flag2 = false;
	int tempSize = 0;

	cout << "Enter Name" << endl;
	cin >> name;
	cout << "Enter Gender" << endl;
	cin >> gender;
	cout << "Enter Date Of Birth" << endl;
	cin >> dob;
	cout << "Enter city" << endl;
	cin >> city;
	availability = "yes";
	cout << "Enter Hourly Charge" << endl;
	cin >> hourlyCharge;
	cout << "Enter Ratings" << endl;
	cin >> ratings;
	int opt;
	do {
		cout << "Enter Category" << endl;
		cout << "Enter (1) For Gynecologist" << endl;
		cout << "Enter (2) For Dermatologist" << endl;
		cout << "Enter (3) For Oncologist" << endl;
		cout << "Enter (4) For Orthopedic" << endl;
		cin >> opt;

		if (opt == 1)
			category = "Gynecologist";
		else if (opt == 2)
			category = "Dermatologist";
		else if (opt == 3)
			category = "Oncologist";
		else if (opt == 4)
			category = "Orthopedic";
	} while ((opt != 1) && (opt != 2) && (opt != 3) && (opt != 4));

	
	cout << "Enter Adress" << endl;
	cin >> address;
	cout << "Enter PhoneNumber" << endl;
	cin >> phoneNumber;
	cout << "Enter UserName" << endl;
	cin >> username;

	do {
		cout << "Enter CNIC" << endl;
		cin >> cNIC;
		if (cNIC.length() < 13)
			cout << "In-valid CNIC" << endl;
		// input validation While Loop
	} while (cNIC.length() < 13||cNIC.length() > 13);


	do {
		cout << "Enter Email " << endl;
		cin >> email_Doctor;
		for (int i = 0; i < email_Doctor.length(); i++) {
			if (email_Doctor[i] == '@')
				flag1 = true;
		}
		tempSize = email_Doctor.size() - 4;
		// input validation
		if ((email_Doctor[tempSize] == '.') && (email_Doctor[tempSize + 1] == 'c') && (email_Doctor[tempSize + 2] == 'o') && (email_Doctor[tempSize + 3] == 'm'))
			flag2 = true;

		// input validation
		if ((flag1 == false) || (flag2 == false)) {
			cout << "Invalid Email" << endl;
			cout << "Re-Enter the Email" << endl;
		}
		// input validation While Loop
	} while ((flag1 == false) || (flag2 == false));

	do {
		cout << "Enter Password" << endl;
		cin >> password_Doctor;


		for (int i = 0; i < password_Doctor.length(); i++) {

			if (password_Doctor[i] >= 97 && password_Doctor[i] <= 122)
				flags1 = true;


			if (password_Doctor[i] >= 65 && password_Doctor[i] <= 97)
				flags2 = true;

			if ((password_Doctor[i] >= 32 && password_Doctor[i] <= 47) || (password_Doctor[i] >= 58 && password_Doctor[i] <= 64) || (password_Doctor[i] >= 91 && password_Doctor[i] <= 96) || (password_Doctor[i] >= 123 && password_Doctor[i] <= 126))
				flags3 = true;
		}

		if ((flags1 == false) || (flags2 == false) || (flags3 == false)) {
			cout << "Invalid Password" << endl;
			cout << "Re-Enter the Password" << endl;
		}
		//Validation For Checking Credentials 
	} while ((flags1 == false) || (flags2 == false) || (flags3 == false));

	string temp;

	temp = name + "," + gender + "," + dob + "," + cNIC + "," + city + "," + username + "," + password_Doctor + "," + phoneNumber + "," + email_Doctor + "," + address + "," + category + "," + ratings + "," + hourlyCharge + "," + availability;

	//Appending data in file 
	ofstream DoctorFile;
	DoctorFile.open("Doctor.txt", ios_base::app);
	DoctorFile << endl << temp;

	DoctorFile.close();

	//creating object for the newly registered doctor
	person[this->counter] = new Doctor;
	person[this->counter]->insertData(name, gender, dob, cNIC, city, username, password_Doctor, phoneNumber, email_Doctor, address, category, ratings, hourlyCharge, availability);
	this->counter++;

}

void Oladoc::loginAdmin() {

	string adminPassword;
	string adminUserName;
	

	do {
		cout << "Login System for Admin" << endl;
		cout << "Enter UserName" << endl;
		cin >> adminUserName;

		cout << "Enter Password" << endl;
		cin >> adminPassword;

		if (this->validateAdminCredentials(adminUserName, adminPassword)) {
			cout << "Succesfully Login" << endl;
			break;
		}
		else
			cout << "Invalid UserName or Password" << endl;
		//Validation For Checking Credentials 
	} while (true);

}

void Oladoc::loginPatient() {

	string patientUserName;
	string pateintPassword;
	do {
		cout << "Login System For Patient" << endl;
		cout << "Enter UserName" << endl;
		cin >> patientUserName;

		cout << "Enter Password" << endl;
		cin >> pateintPassword;

		if (this->validatePatientCredentials(patientUserName, pateintPassword)) {
			cout << "Succesfully Login" << endl;
			break;
		}
		else
			cout << "Invalid UserName or Password" << endl;
		//Validation For Checking Credentials 
	} while (true);

}

void Oladoc::loginDoctor() {
	
	string doctorUserName;
	string doctorPassword;
	do {
		cout << "Login System For Doctor" << endl;
		cout << "Enter UserName" << endl;
		cin >> doctorUserName;

		cout << "Enter Password" << endl;
		cin >> doctorPassword;

		if (this->validateDoctorCredentials(doctorUserName, doctorPassword)) {
			cout << "Succesfully Login" << endl;
			break;
		}
		else
			cout << "Invalid UserName or Password" << endl;
		//Validation For Checking Credentials 
	} while (true);

}


void Oladoc::Appointment_Data_File() {
	string arrays[15] = { "" };
	int tempCounter = 0;
	//reading from the file
	ifstream inputFile("Appointment.txt");
	while (!inputFile.eof()) {
		getline(inputFile, arrays[tempCounter]);
		arrays[tempCounter++] += ",";
		if (inputFile.eof())
			break;
	}
	inputFile.close();

	//storing the parsed data from the file of all the patients
	string parsedArrays[15][9] = { "" };
	for (int i = 0; i < tempCounter; i++) {
		int count = 0;
		for (int j = 0; j < arrays[i].length(); j++) {
			if (arrays[i][j] != ',') {
				parsedArrays[i][count] += arrays[i][j];
			}
			else {
				count++;
			}
		}
	}

	//creating the object and sotring the data into them
	for (int i = 0; i < tempCounter; i++) {
		Person* p1 = new Patient;
		Person* p2 = new Doctor;
		for (int j = 0; i < this->counter; j++) {
			if (parsedArrays[i][7] == person[j]->getCNIC()) {
				p1 = person[j];
				break;
			}
		}
		for (int j = 0; i < this->counter; j++) {
			if (parsedArrays[i][8] == person[j]->getCNIC()) {
				p2 = person[j];
				break;
			}
		}
		appointment[this->appointmentsCount].set_appointment(parsedArrays[i][0], parsedArrays[i][1], parsedArrays[i][2], parsedArrays[i][3], parsedArrays[i][4], parsedArrays[i][5], parsedArrays[i][6], p1, p2);
		this->appointmentsCount++;
	}
	
}

void Oladoc::bookAppointment() {
	//implement functionality here	
	string currentStatus;
	for (int i = 0; i < appointmentsCount; i++) {
		if (appointment[i].getPatient()->getCNIC() == this->currentPerson->getCNIC()) {
			currentStatus = appointment[i].get_Status();
		}
	}
	if (currentStatus == "Pending") {
		cout << "Cannot book another appointment!" << endl;
		return;
	}

}

void Oladoc::cancelAppointment() {
	bool temp = true;
	for (int i = 0; i < this->appointmentsCount; i++) {
		if (this->currentPerson->getCNIC() == this->appointment[i].getPatient()->getCNIC()) {
			if (appointment[i].get_Status() == "Pending" || appointment[i].get_Status() == "Accepted") {
				temp = false;
				cout << "Appointment Details: " << endl;
				cout << "Appointment_ID: " << appointment[i].get_ID() << endl;
				cout << "Appointment_Status: " << appointment[i].get_Status() << endl;
				cout << "Appointment_Charges: " << appointment[i].getDoctor()->get_hourly_charge() << endl;
				cout << "Appointment Cancelled!" << endl;
				cout << "Amount added to your account" << endl;
				this->currentPerson->updatePatientBalance(stoi(appointment[i].getDoctor()->get_hourly_charge()));
				appointment[i].set_Status("Cancelled");
				temp = false;
			}
		}
	}
	if (temp) {
		cout << "No appointment to cancel!" << endl;
	}
}

void Oladoc::viewAppointmentsHistory() {
	for (int i = 0; i < this->appointmentsCount; i++) {
		if (this->currentPerson->getobjType() == "Doctor") {
			if (this->currentPerson->getCNIC() == this->appointment[i].getDoctor()->getCNIC()) {
				this->appointment[i].displayAppointments();
			}
		}
		else if (this->currentPerson->getobjType() == "Patient") {
			if (this->currentPerson->getCNIC() == this->appointment[i].getPatient()->getCNIC()) {
				this->appointment[i].displayAppointments();
			}
		}
	}
}

void Oladoc::searchDoctors() {
	int op;
	do
	{
		cout << "Enter (1) for Category-wise searching" << endl
			<< "Enter (2) for Doctor wise searching" << endl
			<< "Enter (3) for all Doctors" << endl
			<< "Your option: ";
		cin >> op;
	} while (op != 1 && op != 2 && op != 3);
	if (op == 1) {
		int catop;
		do
		{
			cout << "Enter (1) for Gynecologist" << endl
				<< "Enter (2) for Dermatologist" << endl
				<< "Enter (3) for Oncologist" << endl
				<< "Enter (4) for Orthopedic" << endl
				<< "Your option: ";
			cin >> catop;
		} while (op != 1 && op != 2 && op != 3 && op != 4);
		if (catop == 1) {
			for (int i = 0; i < counter; i++) {
				if (person[i]->getobjType() == "Doctor") {
					if(person[i]->get_Category() == "Gynecologist"){
						cout << "Doctor Name: " << person[i]->getName() << endl;
						cout << "Category: " << person[i]->get_Category() << endl;
						cout << "Hourly charge: " << person[i]->get_hourly_charge() << endl;
					}
				}
			}
		}
		else if (catop == 2) {
			for (int i = 0; i < counter; i++) {
				if (person[i]->getobjType() == "Doctor") {
					if (person[i]->get_Category() == "Dermatologist") {
						cout << "Doctor Name: " << person[i]->getName() << endl;
						cout << "Category: " << person[i]->get_Category() << endl;
						cout << "Hourly charge: " << person[i]->get_hourly_charge() << endl;
					}
				}
			}
		}
		else if (catop == 3) {
			for (int i = 0; i < counter; i++) {
				if (person[i]->getobjType() == "Doctor") {
					if (person[i]->get_Category() == "Oncologist") {
						cout << "Doctor Name: " << person[i]->getName() << endl;
						cout << "Category: " << person[i]->get_Category() << endl;
						cout << "Hourly charge: " << person[i]->get_hourly_charge() << endl;
					}
				}
			}
		}
		else if (catop == 4) {
			for (int i = 0; i < counter; i++) {
				if (person[i]->getobjType() == "Doctor") {
					if (person[i]->get_Category() == "Orthopedic") {
						cout << "Doctor Name: " << person[i]->getName() << endl;
						cout << "Category: " << person[i]->get_Category() << endl;
						cout << "Hourly charge: " << person[i]->get_hourly_charge() << endl;
					}
				}
			}
		}
	}
	else if (op == 2) {
		int tempCounter = 0;
		for (int i = 0; i < this->counter; i++) {
			if (person[i]->getobjType() == "Doctor") {
				tempCounter++;
				cout << "(" << tempCounter << ") " << person[i]->getName() << " " << person[i]->get_Category() << endl;
			}
		}
	}
	else if (op == 3) {
		for (int i = 0; i < counter; i++) {
			if (person[i]->getobjType() == "Doctor") {
				cout << "Doctor Name: " << person[i]->getName() << endl;
				cout << "Category: " << person[i]->get_Category() << endl;
				cout << "Hourly charge: " << person[i]->get_hourly_charge() << endl;
			}
		}
	}
}

void Oladoc::giveFeedback() {
	string currentStatus;
	int index = 0;
	for (int i = 0; i < appointmentsCount; i++) {
		if (appointment[i].getPatient()->getCNIC() == this->currentPerson->getCNIC()) {
			currentStatus = appointment[i].get_Status();
			index = i;
		}
	}
	if (currentStatus == "Feedback") {
		while (true) {
			int rating;
			cout << "Enter rating(1 to 5): ";
			cin >> rating;
			if (rating >= 1 && rating <= 5) {
				appointment[index].getFeedback().setfeedBackRating(to_string(rating));
				break;
			}
		}
		string review;
		cout << "Enter Review: ";
		cin >> review;
		appointment[index].getFeedback().setfeedbackReview(review);
	}
	appointment[index].set_Status("Done");
}

void Oladoc::viewPatients() {
	for (int i = 0; i < this->counter; i++) {
		if (person[i]->getobjType() == "Patient") {
			person[i]->display();
			cout << endl;
		}
	}
}

void Oladoc::viewDoctors() {
	for (int i = 0; i < this->counter; i++) {
		if (person[i]->getobjType() == "Doctor") {
			person[i]->display();
			cout << endl;
		}
	}
}

void Oladoc::viewAppointments() {
	for (int i = 0; i < this->appointmentsCount; i++) {
		this->appointment[i].displayAppointments();
	}
}

void Oladoc::displayCurrentUser() {
	this->currentPerson->display();
}

void Oladoc::manageAppointments() {
	bool check = false;
	for (int i = 0; i < appointmentsCount; i++) {
		if (appointment[i].getDoctor()->getCNIC() == this->currentPerson->getCNIC()) {
			if (appointment[i].get_Status() == "Pending") {
				appointment[i].viewAppointment();
				check = true;
			}
		}
	}
	if (check) {
		string appID;
		cout << "Enter the Appointment ID: ";
		cin >> appID;
		string stat;
		cout << "Enter (Accepted) or (Cancelled) to accept or cancel: ";
		cin >> stat;
		for (int i = 0; i < appointmentsCount; i++) {
			if (appID == appointment[i].get_ID()) {
				appointment[i].set_Status(stat);
			}
		}
	}
}
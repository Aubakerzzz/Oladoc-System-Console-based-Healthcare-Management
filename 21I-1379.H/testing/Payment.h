#pragma once
#include<iostream>
using namespace std;

class Payment {
private:
	string paymentAmount;
	string paymentType;
	string Status;

public:
	void set_paymentAmount(string amount);
	void set_paymentType(string type);
	void set_status(string status);
	string get_paymentAmount()const;
	string get_paymentType()const;
	string get_status();
};






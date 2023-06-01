#pragma once
#include<iostream>
using namespace std;
#include<string>

class Credentials {
private:
	static int id;
	string userName;
	string password;
public:
	
	static int get_CredIds();
	static void set_CredIds();
	Credentials();
	void setUserName(string userName);
	void setPassword(string password);
	string getUserName()const;
	string getPassword()const;
	void populate(string username, string password);

};



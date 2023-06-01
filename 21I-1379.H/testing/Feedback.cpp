#include "Feedback.h"
#include "Appointment.h"
#include "Oladoc.h"
#include "Person.h"
#include "ContactInformation.h"
#include "Credentials.h"
#include<iostream>
using namespace std;


void Feedback::setfeedBackRating(string rating) {
	this->feedBack_Rating = rating;
}
void Feedback::setfeedbackReview(string review) {
	this->feedBack_Review = review;
}
string Feedback::getFeedBackRating()const {
	return feedBack_Rating;
}
string Feedback::getFeedBackReview()const {
	return feedBack_Review;
}

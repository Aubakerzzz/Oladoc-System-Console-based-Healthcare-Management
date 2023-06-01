#pragma once
#include<iostream>
using namespace std;

class Feedback {
private:
	string feedBack_Rating;
	string feedBack_Review;
public:
	void setfeedBackRating(string rating);
	void setfeedbackReview(string review);
	string getFeedBackRating()const;
	string getFeedBackReview()const;
};

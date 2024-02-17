#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ostream;
using std::istream;
using std::endl;
using std::cout;
using std::ifstream;
using std::ofstream;

class ExercisePlan {
private:
	//data members
	int stepGoal;
	string name;
	string date;

public:
	//constructor
	ExercisePlan() : stepGoal(0), name(""), date("") {}
	ExercisePlan(int nGoal, string nName, string nDate) : stepGoal(nGoal), name(nName), date(nDate) {}

	//copy constructor
	ExercisePlan(const ExercisePlan& pln) {
		stepGoal = pln.stepGoal;
		name = pln.name;
		date = pln.date;
	}

	//destructor

	//getters
	int gGoal() const;
	string gName() const;
	string gDate() const;

	//setters
	void setGoal(int);
	void setName(string);
	void setDate(string);

	//members misc.
};

//Overloads

//print a exercise plan to output stream
ostream& operator<< (ostream& lhs, const ExercisePlan& rhs);

//print a exercise plan to file output stream
ofstream& operator<< (ofstream& lhs, const ExercisePlan& rhs);

//read a exercise plan from input stream (returns stream for chaining)
//enter format "date,name,goal"
istream& operator>> (istream& lhs, ExercisePlan& rhs);

//read a plan from file stream (returns stream for chaining)
/*Plan name
Goal
Date in the form mm/dd/yyyy
(blank line)
Plan name
Goal
Date in the form mm/dd/yyyy*/
ifstream& operator>> (ifstream& lhs, ExercisePlan& rhs);

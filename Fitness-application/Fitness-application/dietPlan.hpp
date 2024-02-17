#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ostream;
using std::ofstream;
using std::istream;
using std::endl;
using std::cout;
using std::ifstream;

class DietPlan {
private:
	//data members
	int calGoal;
	string name;
	string date;
public:
	//constructor
	DietPlan()	: calGoal(0), name(""),date(""){}
	DietPlan(int nGoal, string nName, string nDate) : calGoal(nGoal), name(nName), date(nDate){}

	//copy constructor
	DietPlan(const DietPlan& pln) {
		calGoal = pln.calGoal;
		name = pln.name;
		date = pln.date;
	}

	//destructor

	//getters
	int gGoal() const;
	string gName() const;
	string gDate() const;

	//setter
	void setGoal(int);
	void setName(string);
	void setDate(string);

	//members misc.
};

//Overloads

//print a diet plan to output stream
ostream& operator<< (ostream& lhs, const DietPlan& rhs);

//print a diet plan to output file stream
ofstream& operator<< (ofstream& lhs, const DietPlan& rhs);

//read a diet plan from input stream (returns stream for chaining)
//enter format "date,name,goal"
istream& operator>> (istream& lhs, DietPlan& rhs);

//read a plan from file stream (returns stream for chaining)
/*Plan name
Goal
Date in the form mm/dd/yyyy
(blank line)
Plan name
Goal
Date in the form mm/dd/yyyy*/
ifstream& operator>> (ifstream& lhs, DietPlan& rhs);
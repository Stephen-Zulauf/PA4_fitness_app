#include "dietPlan.hpp"

//getters
int DietPlan::gGoal() const{
	return calGoal;
}

string DietPlan::gName() const{
	return name;
}
string DietPlan::gDate() const{
	return date;
}

//setter
void DietPlan::setGoal(int newGoal) {
	calGoal = newGoal;
}
void DietPlan::setName(string newName) {
	name = newName;
}
void DietPlan::setDate(string newDate) {
	date = newDate;
}

//Overloads
ostream& operator<< (ostream& lhs, const DietPlan& rhs) {

	//lhs is cout or output stream
	lhs << "Date: " << rhs.gDate() << endl;
	lhs << "Name: " << rhs.gName() << endl;
	lhs << "Calorie Goal: " << rhs.gGoal() << endl;
	lhs << "----------------" << endl;

	return lhs;
}

istream& operator>> (istream& lhs, DietPlan& rhs) {
	string input;
	lhs >> input;
	size_t pos = 0;
	size_t size = 0;

	pos = input.find(',');
	//set the date
	rhs.setDate(input.substr(0, pos));
	//increment past comma
	pos++;

	//need to set size of middle input
	size = input.find(',', pos) - pos;
	//set name
	rhs.setName(input.substr(pos, size));
	pos = input.find(',', pos);
	//increment past comma
	pos++;

	size = input.length() - pos;
	//set goal
	rhs.setGoal(stoi(input.substr(pos, size)));

	return lhs;

}

//TODO needs to take up trailing blank line
ifstream& operator>> (ifstream& lhs, DietPlan& rhs) {
	string input;

	//get name
	getline(lhs, input, '\n');
	rhs.setName(input);

	//get goal
	getline(lhs, input, '\n');
	rhs.setGoal(stoi(input));

	//get date
	getline(lhs, input, '\n');
	rhs.setDate(input);

	//take blank line
	getline(lhs, input, '\n');

	return lhs;
}
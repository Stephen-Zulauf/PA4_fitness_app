#pragma once

#include <iostream>
#include <vector>
#include <fstream>

#include "dietPlan.hpp"
#include "exercisePlan.hpp"

using std::vector;
using std::ofstream;
using std::cin;

class AppWrap {
private:
	/*data members*/

	//diet plan vector
	vector<DietPlan> vD;

	//exercise plan vector
	vector<ExercisePlan> vE;

	//plan filenames
	const string DPFILE = "dietPlans.txt";
	const string EPFILE = "exercisePlans.txt";

	//file streams
	ofstream outFileStream;
	ifstream inFileStream;

	//days array
	string Days[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

	/*private member functions*/

	//open file for write return 0 for success
	int openFileW(ofstream &stream, const string &file);

	//open file for read return 0 for success
	int openFileR(ifstream &stream, const string &file);

	//close file
	int closeFile(ofstream &stream);
	int closeFile(ifstream &stream);
	
	//loads single plan from file
	void loadDailyPlan(ifstream &fileStream, DietPlan &plan);
	void loadDailyPlan(ifstream &fileStream, ExercisePlan &plan);

	//loads entire file
	void loadWeeklyPlan(ifstream &fileStream, vector<DietPlan> &dV);
	void loadWeeklyPlan(ifstream &fileStream, vector<ExercisePlan> &eV);

	//displays single plan
	void displayDailyPlan(DietPlan &dp);
	void displayDailyPlan(ExercisePlan &ep);

	//displays week plan
	void displayWeeklyPlan(vector<DietPlan> &dV);
	void displayWeeklyPlan(vector<ExercisePlan> &eV);

	//stores single plan to file
	void storeDailyPlan(ofstream& outStream, DietPlan &dp);
	void storeDailyPlan(ofstream& outStream, ExercisePlan &ep);

	//stores all plans to file
	void storeWeeklyPlan(ofstream& outStream, vector<DietPlan> &dV);
	void storeWeeklyPlan(ofstream& outStream, vector<ExercisePlan> &eV);

	//edit daily plan
	void displayEditMenu();
	void displayDayEditMenu();
	void editMenu(vector<DietPlan>& dV);
	void editMenu(vector<ExercisePlan>& eV);
	void editDailyPlan(DietPlan& dP);
	void editDailyPlan(ExercisePlan& eP);

public:
	//constructors

	//copy

	//destructor

	/*setters*/

	/*getters*/

	//public function members
	void displayMenu();

	void runApp(void);
};
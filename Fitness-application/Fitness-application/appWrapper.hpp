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

public:
	//constructors

	//copy

	//destructor

	/*setters*/
	//push EP to front

	//push EP to back

	//push DP to front

	//push DP to back

	/*getters*/

	//get next EP

	//get number of EPs
	
	//get next DP

	//get number of DPs

	//public function members
	void displayMenu();

	void runApp(void);

	
};
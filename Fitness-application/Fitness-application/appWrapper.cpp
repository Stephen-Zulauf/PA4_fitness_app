#include "appWrapper.hpp"

/*private member functions*/

	//open file for write
ofstream& openFileW(const string& file) {
	ofstream outFile(file);

	return outFile;
}

//open file for read
ifstream& openFileR(const string& file) {
	ifstream inFile(file);

	return inFile;
}

//close file
void closeFile(ofstream& stream) {
	stream.close();
}
void closeFile(ifstream& stream) {
	stream.close();
}

//loads single plan from file
void loadDailyPlan(ifstream& fileStream, DietPlan& plan) {
	fileStream >> plan;
}

void loadDailyPlan(ifstream& fileStream, ExercisePlan& plan) {
	fileStream >> plan;
}
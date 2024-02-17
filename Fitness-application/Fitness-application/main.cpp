#include "dietPlan.hpp"
#include "exercisePlan.hpp"
#include "appWrapper.hpp"
#include <iostream>

using std::endl;
using std::cout;
using std::cin;

int main() {
	/*DietPlan testDiet(2000, "test", "12.24.24");
	DietPlan testDiet2(2000, "test", "12.24.24");
	DietPlan testDiet3(2000, "test", "12.24.24");
	ExercisePlan testEx(500, "testEx", "4.20.24");
	ExercisePlan testEx1(500, "testEx", "4.20.24");
	ExercisePlan testEx2(500, "testEx", "4.20.24");

	ifstream excFile("exercisePlans.txt");
	excFile >> testEx >> testEx1;
	cout << testEx << testEx1;*/

	AppWrap test;
	test.runApp();
	
	return 0;
}
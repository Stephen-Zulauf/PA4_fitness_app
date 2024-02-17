#include "appWrapper.hpp"

/*private member functions*/

//open file for write
int AppWrap::openFileW(ofstream &stream, const string& file) {
	stream.open(file);

	if (stream.is_open()) {
		return 0;
	}
	else {
		cout << "ERROR OPENFILEW: could not open file";
		return 1;
	}
}

//open file for read
int AppWrap::openFileR(ifstream &stream, const string& file) {
	stream.open(file);

	if (stream.is_open()) {
		return 0;
	}
	else {
		cout << "ERROR OPENFILER: could not open file";
		return 1;
	}
}

//close file
int AppWrap::closeFile(ofstream& stream) {
	stream.close();

	if (stream.is_open()) {
		cout << "ERROR CLOSEFILE: could not close file";
		return 1;
	}
	else {
		return 0;
	}
}
int AppWrap::closeFile(ifstream& stream) {
	stream.close();

	if (stream.is_open()) {
		cout << "ERROR CLOSEFILE: could not close file";
		return 1;
	}
	else {
		return 0;
	}
}

//loads single plan from file
void AppWrap::loadDailyPlan(ifstream& fileStream, DietPlan& plan) {
	fileStream >> plan;
}

void AppWrap::loadDailyPlan(ifstream& fileStream, ExercisePlan& plan) {
	fileStream >> plan;
}

//loads entire file
void AppWrap::loadWeeklyPlan(ifstream& fileStream, vector<DietPlan>& dV) {
	DietPlan temp;

	while (!fileStream.eof()) {
		fileStream >> temp;
		dV.push_back(temp);
	}
}

void AppWrap::loadWeeklyPlan(ifstream& fileStream, vector<ExercisePlan>& eV) {
	ExercisePlan temp;

	while (!fileStream.eof()) {
		fileStream >> temp;
		eV.push_back(temp);
	}
}

//displays single plan
void AppWrap::displayDailyPlan(DietPlan& dp) {
	cout << dp;
}
void AppWrap::displayDailyPlan(ExercisePlan& ep) {
	cout << ep;
}

//displays week plan
void AppWrap::displayWeeklyPlan(vector<DietPlan>& dV) {
	size_t size = dV.size();
	int i;
	for (i = 0; i < size; i++) {
		
		cout << Days[i] << endl;
		displayDailyPlan(dV[i]);
		
	}
}
void AppWrap::displayWeeklyPlan(vector<ExercisePlan>& eV) {
	size_t size = eV.size();
	int i;
	for (i = 0; i < size; i++) {

		cout << Days[i] << endl;
		displayDailyPlan(eV[i]);
		
	}
}

void AppWrap::displayEditMenu() {
	system("cls");
	cout << " (      (                  )         (      (     " << endl;
	cout << " )\\ )   )\\ )    *   )   ( /(         )\\ )   )\\ )  " << endl;
	cout << "(()/(  (()/(  ` )  /(   )\())  (    (()/(  (()/(  " << endl;
	cout << "(_))_| (_))   (_(_())   _((_) ((_)  (_))   (_))   " << endl;
	cout << "| |_   |_ _|  |_   _|  | \\| | | __| / __|  / __|" << endl;
	cout << "| __|   | |     | |    | .` | | _|  \\__ \\  \\__ \\ " << endl;
	cout << "|_|    |___|    |_|    |_|\\_| |___| |___/  |___/ " << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "| Choose a day of the week to edit:              |" << endl;
	cout << "| 1) Monday                                      |" << endl;
	cout << "| 2) Tuesday                                     |" << endl;
	cout << "| 3) Wednesday                                   |" << endl;
	cout << "| 4) Thursday                                    |" << endl;
	cout << "| 5) Friday                                      |" << endl;
	cout << "| 6) Saturday                                    |" << endl;
	cout << "| 7) Sunday                                      |" << endl;
	cout << "| 8) Exit                                        |" << endl;
	cout << "--------------------------------------------------" << endl;
}

void AppWrap::displayDayEditMenu() {
	system("cls");
	cout << " (      (                  )         (      (     " << endl;
	cout << " )\\ )   )\\ )    *   )   ( /(         )\\ )   )\\ )  " << endl;
	cout << "(()/(  (()/(  ` )  /(   )\())  (    (()/(  (()/(  " << endl;
	cout << "(_))_| (_))   (_(_())   _((_) ((_)  (_))   (_))   " << endl;
	cout << "| |_   |_ _|  |_   _|  | \\| | | __| / __|  / __|" << endl;
	cout << "| __|   | |     | |    | .` | | _|  \\__ \\  \\__ \\ " << endl;
	cout << "|_|    |___|    |_|    |_|\\_| |___| |___/  |___/ " << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "| What do you want to edit?:                     |" << endl;
	cout << "| 1) Name                                        |" << endl;
	cout << "| 2) Goal                                        |" << endl;
	cout << "| 3) Date                                        |" << endl;
	cout << "| 4) Exit                                        |" << endl;
	cout << "--------------------------------------------------" << endl;
}
void AppWrap::editMenu(vector<DietPlan>& dV) {

	//print menu
	displayEditMenu();

	//menu functionality
	string buff;
	int choice = 0;

	while (choice != 8) {
		cin >> buff;
		choice = stoi(buff);
		if (choice < 8) {
			editDailyPlan(dV[choice-1]);
		}
		displayEditMenu();
	}
}

void AppWrap::editMenu(vector<ExercisePlan>& eV) {

	//print menu
	displayEditMenu();

	//menu functionality
	string buff;
	int choice = 0;

	while (choice != 8) {
		cin >> buff;
		choice = stoi(buff);
		if (choice < 8) {
			editDailyPlan(eV[choice-1]);
		}
		displayEditMenu();
		
	}
}

void AppWrap::editDailyPlan(DietPlan& dP) {

	//print menu
	displayDayEditMenu();

	//menu functionality
	string buff;
	string entry;
	int choice = 0;

	while (choice != 4) {
		cin >> buff;
		choice = stoi(buff);
		switch (choice) {
		case 1:
			//edit name
			cout << "Enter new Name" << endl;
			cin >> entry;
			dP.setName(entry);
			displayDayEditMenu();
			break;
		case 2:
			//edit goal
			cout << "Enter new Goal" << endl;
			cin >> entry;
			dP.setGoal(stoi(entry));
			displayDayEditMenu();
			break;
		case 3:
			//edit date
			cout << "Enter new Date" << endl;
			cin >> entry;
			dP.setDate(entry);
			displayDayEditMenu();
			break;
		default:
			displayDayEditMenu();
		}
	}
	
}
void AppWrap::editDailyPlan(ExercisePlan& eP) {
	//print menu
	displayDayEditMenu();

	//menu functionality
	string buff;
	string entry;
	int choice = 0;

	while (choice != 4) {
		cin >> buff;
		choice = stoi(buff);
		switch (choice) {
		case 1:
			//edit name
			cout << "Enter new Name" << endl;
			cin >> entry;
			eP.setName(entry);
			displayDayEditMenu();
			break;
		case 2:
			//edit goal
			cout << "Enter new Goal" << endl;
			cin >> entry;
			eP.setGoal(stoi(entry));
			displayDayEditMenu();
			break;
		case 3:
			//edit date
			cout << "Enter new Date" << endl;
			cin >> entry;
			eP.setDate(entry);
			displayDayEditMenu();
			break;
		default:
			displayDayEditMenu();
		}
	}
}

/*public function members*/

void AppWrap::displayMenu() {
	//clear screen and print options
	system("cls");
	cout << " (      (                  )         (      (     " << endl;
	cout << " )\\ )   )\\ )    *   )   ( /(         )\\ )   )\\ )  " << endl;
	cout << "(()/(  (()/(  ` )  /(   )\())  (    (()/(  (()/(  " << endl;
	cout << "(_))_| (_))   (_(_())   _((_) ((_)  (_))   (_))   " << endl;
	cout << "| |_   |_ _|  |_   _|  | \\| | | __| / __|  / __|" << endl;
	cout << "| __|   | |     | |    | .` | | _|  \\__ \\  \\__ \\ " << endl;
	cout << "|_|    |___|    |_|    |_|\\_| |___| |___/  |___/ " << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "| 1) Load weekly diet plan from file             |" << endl;
	cout << "| 2) Load weekly exercise plan from file.        |"<< endl;
	cout << "| 3) Store weekly diet plan to file.             |"<< endl;
	cout << "| 4) Store weekly exercise plan to file.         |"<< endl;
	cout << "| 5) Display weekly diet plan to screen.         |"<< endl;
	cout << "| 6) Display weekly exercise plan to screen.     |"<< endl;
	cout << "| 7) Edit daily diet plan.                       |"<< endl;
	cout << "| 8) Edit daily exercise plan.                   |"<< endl;
	cout << "| 9) Exit write the most recent weekly plans     |"<< endl;
	cout << "--------------------------------------------------" << endl;
}

void AppWrap::runApp(void) {
	
	//display menu
	displayMenu();

	//menu functionality
	string buff;
	int choice = 0;

	while (choice != 9) {
		cin >> buff;
		choice = stoi(buff);

		switch (choice) {
		case 1:
			//1. Load weekly diet plan from file
			if (openFileR(inFileStream, DPFILE) == 0 && vD.size() < 7) {

				//load
				loadWeeklyPlan(inFileStream, vD);
				//close
				closeFile(inFileStream);
				//clear
				displayMenu();
				cout << "Loaded dietPlans.txt..." << endl;
			}
			else if (vD.size() >= 7) {
				//data already loaded
				displayMenu();
				cout << "Already loaded diet data" << endl;
			}
			else {
				//error
				displayMenu();
				cout << "Problem with dietPlans.txt" << endl;
			}
			break;
		case 2:
			//2. Load weekly exercise plan from file.
			if (openFileR(inFileStream, EPFILE) == 0 && vE.size() < 7) {

				//load
				loadWeeklyPlan(inFileStream, vE);
				//close
				closeFile(inFileStream);
				//clear
				displayMenu();
				cout << "Loaded exercisePlans.txt..." << endl;
			}
			else if (vE.size() >= 7) {
				//data already loaded
				displayMenu();
				cout << "Already loaded exercise data" << endl;
			}
			else {
				//error
				displayMenu();
				cout << "Problem with exercisePlans.txt" << endl;
			}
			break;
		case 3:
			//3. Store weekly diet plan to file.
			break;
		case 4:
			//4. Store weekly exercise plan to file.
			break;
		case 5:
			//5. Display weekly diet plan to screen.
			if (vD.size() != 0) {
				cout << vD.size() << endl;
				//data loaded
				//display
				system("cls");
				displayWeeklyPlan(vD);
				cout << "enter to exit" << endl;
				cin.ignore();
				cin.ignore();
				//clear
				displayMenu();
			}
			else {
				//no data
				displayMenu();
				cout << "No diet data loaded" << endl;
			}
			break;
		case 6:
			//6. Display weekly exercise plan to screen.
			if (vE.size() != 0) {
				cout << vE.size() << endl;
				//data loaded
				//display
				system("cls");
				displayWeeklyPlan(vE);
				cout << "enter to exit" << endl;
				cin.ignore();
				cin.ignore();
				//clear
				displayMenu();

			}
			else {
				//no data
				displayMenu();
				cout << "No diet data loaded" << endl;
			}
			break;
		case 7:
			//7. Edit daily diet plan
			editMenu(vD);
			displayMenu();
			break;
		case 8:
			//8. Edit daily exercise plan.
			editMenu(vE);
			displayMenu();
			break;
		case 9:
			//9. Exit write the most recent weekly plans
			break;
		}
	}
}


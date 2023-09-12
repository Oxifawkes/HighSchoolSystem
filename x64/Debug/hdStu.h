#pragma once
#include <iostream>
#include <fstream>

using namespace std;

//Student Sub-Menu to access or change student-based files.

void fStuSM() {

	//Declaring and initalizing variables.
	int StuSM, StuSM1;
	int linecounter = 0;
	int LocationofUserName;
	bool userfound = false;
	fstream StuDet;
	fstream StuGra;
	fstream StuExa;
	cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
	cout << "---------    UA HIGH SCHOOL     ---------" << endl;
	cout << "\n        ----- Student Menu -----" << endl << endl;
	cout << "You are signed in as " << userName << "." << endl;
	cout << "\nWelcome to the Student Menu.\n\n[1] My Details\n[2] My Grades\n[3] Exam Timetable\n[4] Sign out" << endl << endl;
	cout << "Please make a selection: ";
	cin >> StuSM;

	while (StuSM != 1 && StuSM != 2 && StuSM != 3 && StuSM != 4) {
		cin.clear(); //Clears cin.
		cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
		cout << "Invalid entry.\nPlease try again: ";
		cin >> StuSM;
	}

	cout << "\n";
	//Student Sub Menu.

	while (Stulogin == true) {
		system("CLS");

		switch (StuSM) {
		case 1:
			//View My Details
			cout << "-- My Details --" << endl << endl;
			StuDet.open("StuDet.txt", ios::in); // Open
			// While there are still lines in the txt file
			while (getline(StuDet, line))
			{

				// Count the lines:
				linecounter++;

				// Look for the username:
				if (line == userName)
				{
					LocationofUserName = linecounter;
					userfound = true;
					// Stores the location of the linecounter.

				}

				if (userfound == true) {
					if (linecounter == (LocationofUserName + 1)) {
						cout << "Name: " << line << endl;
					}

					if (linecounter == (LocationofUserName + 2)) {
						cout << "Age: " << line << endl;
					}

					if (linecounter == (LocationofUserName + 3)) {
						cout << "Year: " << line << endl;
					}

					if (linecounter == (LocationofUserName + 4)) {
						cout << "Profile Type: " << line << endl;
					}

					if (linecounter == (LocationofUserName + 5)) {
						cout << "First Parent/Guardian: " << line << endl;
					}

					if (linecounter == (LocationofUserName + 6)) {
						cout << "Second Parent/Guardian: " << line << endl;
					}
				}
			}

			userfound = false; //Resets the bool.

			//Reset the linecounter.
			linecounter = 0;

			StuDet.close();
			// Close the file:

			//Makes a new sub-menu for 
			cout << "\n[1] Return to Menu\n[2] Sign Out\n\nSelection: ";
			cin >> StuSM1;
			system("CLS");

			//Ensures the input is only one of the two valid options.
			while (StuSM1 != 1 && StuSM1 != 2) {
				cin.clear(); //Clears cin.
				cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
				cout << "Invalid entry.\nPlease try again: ";
				cin >> StuSM1;
			}

			//Provides the menu for the user again.
			if (StuSM1 == 1) {
				cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
				cout << "---------    UA HIGH SCHOOL     ---------" << endl;
				cout << "\n      ----- Student Menu -----" << endl;
				cout << "\nWelcome to the Student Menu.\n\n[1] My Details\n[2] My Grades\n[3] Exam Timetable\n[4] Sign out" << endl;
				cout << "\nPlease make a selection: ";
				cin >> StuSM;
				while (StuSM != 1 && StuSM != 2 && StuSM != 3 && StuSM != 4) {
					cin.clear(); //Clears cin.
					cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
					cout << "Invalid entry.\nPlease try again: ";
					cin >> StuSM;
				}
				cout << "\n";
			}

			//Otherwise breaks the entire menu and returns them to the main screen.
			else if (StuSM1 == 2) {
				CredFail = true;
				Stulogin = false;
			}
			break;
		case 2:
			//View My Grades.
			cout << "-- My Grades --" << endl << endl;
			StuGra.open("StuGra.txt", ios::in); // Open
			// While there are still lines in the txt file
			while (getline(StuGra, line))
			{

				// Count the lines:
				linecounter++;

				// Look for the username:
				if (line == userName)
				{
					LocationofUserName = linecounter;
					userfound = true; //Unlocks the below if statement to find the correct user.
					// Tell us what line the user name was found at

				}

				if (userfound == true) {
					if (linecounter == (LocationofUserName + 2)) {
						cout << "English: " << line << endl;
					}

					if (linecounter == (LocationofUserName + 4)) {
						cout << "Maths: " << line << endl;
					}

					if (linecounter == (LocationofUserName + 6)) {
						cout << "Science: " << line << endl;
					}

					if (linecounter == (LocationofUserName + 8)) {
						cout << "Social Studies: " << line << endl;
					}

					if (linecounter == (LocationofUserName + 10)) {
						cout << "Physical Education: " << line << endl;
					}
				}

			}

			userfound = false; //Resets the bool.

			//Reset the linecounter.
			linecounter = 0;

			StuGra.close();
			// Close the file:

			cout << "\n[1] Return to Menu\n[2] Sign Out\n\nSelection: ";
			cin >> StuSM1;
			system("CLS");

			while (StuSM1 != 1 && StuSM1 != 2) {
				cin.clear(); //Clears cin.
				cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
				cout << "Invalid entry.\nPlease try again: ";
				cin >> StuSM1;
			}

			if (StuSM1 == 1) {
				cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
				cout << "---------    UA HIGH SCHOOL     ---------" << endl;
				cout << "\n      ----- Student Menu -----" << endl;
				cout << "\nWelcome to the Student Menu.\n\n[1] My Details\n[2] My Grades\n[3] Exam Timetable\n[4] Sign out" << endl;
				cout << "\nPlease make a selection: ";
				cin >> StuSM;
				while (StuSM != 1 && StuSM != 2 && StuSM != 3 && StuSM != 4) {
					cin.clear(); //Clears cin.
					cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
					cout << "Invalid entry.\nPlease try again: ";
					cin >> StuSM;
				}
				cout << "\n";
			}
			else if (StuSM1 == 2) {
				CredFail = true;
				Stulogin = false;
			}
			break;
		case 3:
			//View Exam Timetable.
			cout << "-- Exam Timetable --" << endl << endl;
			StuExa.open("StuExa.txt", ios::in); // Open
			// While there are still lines in the txt file
			while (getline(StuExa, line))
			{
				linecounter++;
				int locationofExam = 0;
				if (line == "English" || line == "Maths" || line == "Science" || line == "Social Studies" || line == "Physical Education") {
					cout << line << " Exam: " << endl;
					linecounter = locationofExam;
				}

				if (linecounter == (locationofExam + 1)) {
					cout << "Date: " << line << endl;
				}

				if (linecounter == (locationofExam + 2)) {
					cout << "Time: " << line << endl << endl;
				}

			}
			StuExa.close();
			// Close the file:

			cout << "\n[1] Return to Menu\n[2] Sign Out\n\nSelection: ";
			cin >> StuSM1;
			system("CLS");

			while (StuSM1 != 1 && StuSM1 != 2) {
				cin.clear(); //Clears cin.
				cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
				cout << "Invalid entry.\nPlease try again: ";
				cin >> StuSM1;
			}

			if (StuSM1 == 1) {
				cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
				cout << "---------    UA HIGH SCHOOL     ---------" << endl;
				cout << "\n        ----- Student Menu -----" << endl;
				cout << "\nWelcome to the Student Menu.\n\n[1] My Details\n[2] My Grades\n[3] Exam Timetable\n[4] Sign out" << endl;
				cout << "\nPlease make a selection: ";
				cin >> StuSM;
				cout << "\n";
			}
			else if (StuSM1 == 2) {
				CredFail = true;
				Stulogin = false;
			}
			break;
		case 4:
			//Logout.
			CredFail = true;
			Stulogin = false;
			system("CLS");

		}

	}
}

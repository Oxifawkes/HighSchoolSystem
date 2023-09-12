#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

vector<string> TeaVec;

//Teacher Sub-Menu to access or change student-based files.

void fTeaSM() {

	//Declaring and initalizing variables.
	int TeaSM, TeaSM1, TeaSM2, TeaSM3;
	bool UserFound = false;
	bool firstline = true;
	int linecounter = 0;
	int LocationofStudent = 0;
	int LocationofExam = 0;
	int studentcounter = 0;
	bool ExaFound = false;
	string Exadate, Exatime, StuUser, grade, exam, Pretime, Predate;
	fstream StuDet;
	fstream StuGra;
	fstream StuExa;
	cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
	cout << "---------    UA HIGH SCHOOL     ---------" << endl;
	cout << "\n      ----- Teacher Menu -----" << endl << endl;
	cout << "You are signed in as " << userName << "." << endl;
	cout << "\nWelcome to the Teacher Menu.\n\n[1] Student Details\n[2] Student Grades\n[3] Exam Timetable\n[4] Sign out" << endl;
	cout << "\nPlease make a selection: ";
	cin >> TeaSM;

	while (TeaSM != 1 && TeaSM != 2 && TeaSM != 3 && TeaSM != 4) {
		cin.clear(); //Clears cin.
		cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
		cout << "Invalid entry.\nPlease try again: ";
		cin >> TeaSM;
	}

	system("CLS");

	while (Tealogin == true) {

		switch (TeaSM) {
			//View Student Details
		case 1:
			cout << "-- Student Details --" << endl << endl;

			cout << "\n";
			StuDet.open("StuDet.txt", ios::in); // Open
			// While there are still lines in the txt file
			while (getline(StuDet, line))
			{
				//Teacher can view all the student details in the file.
				linecounter++;
				if (line == "---*---") {
					LocationofStudent = linecounter;
					studentcounter++; //Counts each student section.
				}

				if (linecounter == (LocationofStudent + 2)) {
					cout << "Name: " << line << endl;
				}

				if (linecounter == (LocationofStudent + 3)) {
					cout << "Age: " << line << endl;
				}

				if (linecounter == (LocationofStudent + 4)) {
					cout << "Year: " << line << endl;
				}

				if (linecounter == (LocationofStudent + 5)) {
					cout << "Profile Type: " << line << endl;
				}

				if (linecounter == (LocationofStudent + 6)) {
					cout << "First Parent/Guardian: " << line << endl;
				}

				if (linecounter == (LocationofStudent + 7)) {
					cout << "Second Parent/Guardian: " << line << endl << endl;
				}

			}
			// Close the file:
			StuDet.close();

			//Informs the user the total number of students enrolled in the school.
			cout << "No. of Enrolled Students: " << studentcounter << endl;

			//Reset the counter:
			studentcounter = 0;

			//Makes a new sub-menu for returning to menu or exiting.
			cout << "\n[1] Return to Menu\n[2] Sign Out\n\nSelection: ";
			cin >> TeaSM1;
			system("CLS");

			//Ensures the input is only one of the two valid options.
			while (TeaSM1 != 1 && TeaSM1 != 2) {
				cin.clear(); //Clears cin.
				cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
				cout << "Invalid entry.\nPlease try again: ";
				cin >> TeaSM1;
			}

			if (TeaSM1 == 1) {
				cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
				cout << "---------    UA HIGH SCHOOL     ---------" << endl;
				cout << "\n      ----- Teacher Menu -----" << endl;
				cout << "\nWelcome to the Teacher Menu.\n\n[1] Student Details\n[2] Student Grades\n[3] Exam Timetable\n[4] Sign out" << endl;
				cout << "\nPlease make a selection: ";
				cin >> TeaSM;
				while (TeaSM != 1 && TeaSM != 2 && TeaSM != 3 && TeaSM != 4) {
					cin.clear(); //Clears cin.
					cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
					cout << "Invalid entry.\nPlease try again: ";
					cin >> TeaSM;
				}
				break;
			}
			else if (TeaSM1 == 2) {
				CredFail = true;
				Tealogin = false;
			}
			break;
		case 2:
			system("CLS");
			cout << "-- Grade Management --\n\n[1] View Student Grades\n[2] Change Student Grades\n[3] Return to Teacher Menu\n\nPlease make a selection: ";
			cin >> TeaSM1;
			while (TeaSM1 != 1 && TeaSM1 != 2 && TeaSM1 != 3) {
				cin.clear(); //Clears cin.
				cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
				cout << "Invalid entry.\nPlease try again: ";
				cin >> TeaSM1;
			}
			switch (TeaSM1) {
			case 1:
				//View Student Grades.

				cout << "-- Student Grades --" << endl << endl;
				StuGra.open("StuGra.txt", ios::in); // Open
				// While there are still lines in the txt file 
				while (getline(StuGra, line))
				{
					//Outputs the student information.
					if (line != "---*---") {
						cout << line << endl;
					}

					//Separates the students by a line for easier display.
					if (line == "---*---") {
						cout << endl;
					}
				}

				StuGra.close();
				// Close the file:

				//Makes a new sub-menu for 
				cout << "\n[1] Return to Menu\n[2] Sign Out\n\nSelection: ";
				cin >> TeaSM1;

				//Ensures the input is only one of the two valid options.
				while (TeaSM1 != 1 && TeaSM1 != 2) {
					cin.clear(); //Clears cin.
					cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
					cout << "Invalid entry.\nPlease try again: ";
					cin >> TeaSM1;
				}
				system("CLS");

				if (TeaSM1 == 1) {
					cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
					cout << "---------    UA HIGH SCHOOL     ---------" << endl;
					cout << "\n      ----- Teacher Menu -----" << endl;
					cout << "\nWelcome to the Teacher Menu.\n\n[1] Student Details\n[2] Student Grades\n[3] Exam Timetable\n[4] Sign out" << endl;
					cout << "\nPlease make a selection: ";
					cin >> TeaSM;
					while (TeaSM != 1 && TeaSM != 2 && TeaSM != 3 && TeaSM != 4) {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "Invalid entry.\nPlease try again: ";
						cin >> TeaSM;
					}
					break;
				}
				else if (TeaSM1 == 2) {
					CredFail = true;
					Tealogin = false;
				}

				break;
			case 2:
				//Change Grades Section.

				//Asks the user for a student's username.
				cout << "Please enter the student's username: ";
				cin >> StuUser;

				StuGra.open("StuGra.txt", ios::in);

				while (UserFound == false) {
					while (getline(StuGra, line)) {
						
						linecounter++;
						if (line == StuUser) {
							UserFound = true;
							break;
						}
					}
					if (UserFound == false) {
						cout << "Student username not found. Please enter again: ";
						cin >> StuUser;

						//Resets the file so that it can be read again.
						StuGra.clear();
						StuGra.seekg(0);
					}
				}

				StuGra.close();

				//Reset the line counter and LocationofStudent to prevent conflicts.
				linecounter = 0;
				LocationofStudent = -50; //Leaves buffer so that it doesn't trip up loops.

				//Asks the user for another sub-menu option.
				cout << "\n[1] English\n[2] Maths\n[3] Science\n[4] Social Studies\n[5] Physical Education\n";
				cout << "\nPlease select the subject grade you wish to change: ";
				cin >> TeaSM2;

				while (TeaSM2 < 1 || TeaSM2 > 6) {
					cin.clear(); //Clears cin.
					cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
					cout << "Invalid entry.\nPlease try again: ";
					cin >> TeaSM2;
				}

				cout << "\nEnter the student's new grade: ";
				cin >> grade;

				while (grade != "F" && grade != "D" && grade != "C-" && grade != "C" && grade != "C+" && grade != "B-" && grade != "B" && grade != "B+" && grade != "A-" && grade != "A" && grade != "A+") {
					cin.clear(); //Clears cin.
					cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
					cout << "Invalid grade type. Please try again: ";
					cin >> grade;
				}

				//Switch Menu for changing the grade of a specific subject.
				switch (TeaSM2) {
				case 1:
					//Change English Grade.
					StuGra.open("StuGra.txt");

					while (getline(StuGra, line)) {
						linecounter++;
						if (linecounter != (LocationofStudent + 2)) {
							TeaVec.push_back(line);
						}
						if (line == StuUser) {
							LocationofStudent = linecounter;
						}

						if (linecounter == (LocationofStudent + 2)) {
							TeaVec.push_back(grade);
						}
					}
					StuGra.close();

					//Open the file to clear contents and then write to it.
					StuGra.open("StuGra.txt", ios::out | ios::trunc);
					StuGra.close();
					StuGra.open("StuGra.txt");

					for (int i = 0; i < TeaVec.size(); ++i) {
						if (firstline == false) {
							StuGra << "\n";
						}
						StuGra << TeaVec[i];
						firstline = false;
					}

					firstline = true;
					UserFound = false;
					linecounter = 0;
					LocationofStudent = 0;
					TeaVec.clear();

					StuGra.close();

					cout << StuUser << "'s English grade has been changed to: " << grade << endl;

					//Makes a new sub-menu for returning to menu or exiting.
					cout << "\n[1] Return to Menu\n[2] Sign Out\n\nSelection: ";
					cin >> TeaSM1;
					system("CLS");

					//Ensures the input is only one of the two valid options.
					while (TeaSM1 != 1 && TeaSM1 != 2) {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "Invalid entry.\nPlease try again: ";
						cin >> TeaSM1;
					}

					if (TeaSM1 == 1) {
						break;
					}
					else if (TeaSM1 == 2) {
						system("CLS");
						CredFail = true;
						Tealogin = false;
						break;
					}
					break;
				case 2:
					//Change Maths Grade.
					StuGra.open("StuGra.txt");

					while (getline(StuGra, line)) {
						linecounter++;
						if (linecounter != (LocationofStudent + 4)) {
							TeaVec.push_back(line);
						}
						if (line == StuUser) {
							LocationofStudent = linecounter;
						}

						if (linecounter == (LocationofStudent + 4)) {
							TeaVec.push_back(grade);
						}
					}
					StuGra.close();

					//Open the file to refresh it.
					StuGra.open("StuGra.txt", ios::out | ios::trunc);
					StuGra.close();
					StuGra.open("StuGra.txt");

					for (int i = 0; i < TeaVec.size(); ++i) {
						if (firstline == false) {
							StuGra << "\n";
						}
						StuGra << TeaVec[i];
						firstline = false;
					}

					firstline = true;
					UserFound = false;
					linecounter = 0;
					LocationofStudent = 0;
					TeaVec.clear();

					StuGra.close();

					cout << StuUser << "'s Maths grade has been changed to: " << grade << endl;

					//Makes a new sub-menu for returning to menu or exiting.
					cout << "\n[1] Return to Menu\n[2] Sign Out\n\nSelection: ";
					cin >> TeaSM1;
					system("CLS");

					//Ensures the input is only one of the two valid options.
					while (TeaSM1 != 1 && TeaSM1 != 2) {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "Invalid entry.\nPlease try again: ";
						cin >> TeaSM1;
					}

					if (TeaSM1 == 1) {
						cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
						cout << "---------    UA HIGH SCHOOL     ---------" << endl;
						cout << "\n      ----- Teacher Menu -----" << endl;
						cout << "\nWelcome to the Teacher Menu.\n\n[1] Student Details\n[2] Student Grades\n[3] Exam Timetable\n[4] Sign out" << endl;
						cout << "\nPlease make a selection: ";
						cin >> TeaSM;
						while (TeaSM != 1 && TeaSM != 2 && TeaSM != 3 && TeaSM != 4) {
							cin.clear(); //Clears cin.
							cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
							cout << "Invalid entry.\nPlease try again: ";
							cin >> TeaSM;
						}
						break;
					}
					else if (TeaSM1 == 2) {
						CredFail = true;
						Tealogin = false;
					}
					break;
				case 3:
					//Change Science Grade.
					StuGra.open("StuGra.txt");

					while (getline(StuGra, line)) {
						linecounter++;
						if (linecounter != (LocationofStudent + 6)) {
							TeaVec.push_back(line);
						}
						if (line == StuUser) {
							LocationofStudent = linecounter;
						}

						if (linecounter == (LocationofStudent + 6)) {
							TeaVec.push_back(grade);
						}
					}
					StuGra.close();

					//Open the file to refresh it.
					StuGra.open("StuGra.txt", ios::out | ios::trunc);
					StuGra.close();
					StuGra.open("StuGra.txt");

					for (int i = 0; i < TeaVec.size(); ++i) {
						if (firstline == false) {
							StuGra << "\n";
						}
						StuGra << TeaVec[i];
						firstline = false;
					}

					firstline = true;
					UserFound = false;
					linecounter = 0;
					LocationofStudent = 0;
					TeaVec.clear();
					
					StuGra.close();

					cout << StuUser << "'s Science grade has been changed to: " << grade << endl;

					//Makes a new sub-menu for returning to menu or exiting.
					cout << "\n[1] Return to Menu\n[2] Sign Out\n\nSelection: ";
					cin >> TeaSM1;
					system("CLS");

					//Ensures the input is only one of the two valid options.
					while (TeaSM1 != 1 && TeaSM1 != 2) {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "Invalid entry.\nPlease try again: ";
						cin >> TeaSM1;
					}

					if (TeaSM1 == 1) {
						cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
						cout << "---------    UA HIGH SCHOOL     ---------" << endl;
						cout << "\n      ----- Teacher Menu -----" << endl;
						cout << "\nWelcome to the Teacher Menu.\n\n[1] Student Details\n[2] Student Grades\n[3] Exam Timetable\n[4] Sign out" << endl;
						cout << "\nPlease make a selection: ";
						cin >> TeaSM;
						while (TeaSM != 1 && TeaSM != 2 && TeaSM != 3 && TeaSM != 4) {
							cin.clear(); //Clears cin.
							cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
							cout << "Invalid entry.\nPlease try again: ";
							cin >> TeaSM;
						}
						break;
					}
					else if (TeaSM1 == 2) {
						CredFail = true;
						Tealogin = false;
					}
					break;
				case 4:
					//Change Social Studies Grade.
					StuGra.open("StuGra.txt");

					while (getline(StuGra, line)) {
						linecounter++;
						if (linecounter != (LocationofStudent + 8)) {
							TeaVec.push_back(line);
						}
						if (line == StuUser) {
							LocationofStudent = linecounter;
						}

						if (linecounter == (LocationofStudent + 8)) {
							TeaVec.push_back(grade);
						}
					}
					StuGra.close();

					//Open the file to refresh it.
					StuGra.open("StuGra.txt", ios::out | ios::trunc);
					StuGra.close();
					StuGra.open("StuGra.txt");

					for (int i = 0; i < TeaVec.size(); ++i) {
						if (firstline == false) {
							StuGra << "\n";
						}
						StuGra << TeaVec[i];
						firstline = false;
					}

					//Reset the variables.
					firstline = true;
					UserFound = false;
					linecounter = 0;
					LocationofStudent = 0;
					TeaVec.clear();

					StuGra.close();

					cout << StuUser << "'s Social Studies grade has been changed to: " << grade << endl;

					//Makes a new sub-menu for returning to menu or exiting.
					cout << "\n[1] Return to Menu\n[2] Sign Out\n\nSelection: ";
					cin >> TeaSM1;
					system("CLS");

					//Ensures the input is only one of the two valid options.
					while (TeaSM1 != 1 && TeaSM1 != 2) {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "Invalid entry.\nPlease try again: ";
						cin >> TeaSM1;
					}

					if (TeaSM1 == 1) {
						cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
						cout << "---------    UA HIGH SCHOOL     ---------" << endl;
						cout << "\n      ----- Teacher Menu -----" << endl;
						cout << "\nWelcome to the Teacher Menu.\n\n[1] Student Details\n[2] Student Grades\n[3] Exam Timetable\n[4] Sign out" << endl;
						cout << "\nPlease make a selection: ";
						cin >> TeaSM;
						while (TeaSM != 1 && TeaSM != 2 && TeaSM != 3 && TeaSM != 4) {
							cin.clear(); //Clears cin.
							cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
							cout << "Invalid entry.\nPlease try again: ";
							cin >> TeaSM;
						}
						break;
					}
					else if (TeaSM1 == 2) {
						CredFail = true;
						Tealogin = false;
					}
					break;
				case 5:
					//Change Physical Education Grade.
					StuGra.open("StuGra.txt");

					while (getline(StuGra, line)) {
						linecounter++;
						if (linecounter != (LocationofStudent + 10)) {
							TeaVec.push_back(line);
						}
						if (line == StuUser) {
							LocationofStudent = linecounter;
						}

						if (linecounter == (LocationofStudent + 10)) {
							TeaVec.push_back(grade);
						}
					}
					StuGra.close();

					//Open the file to refresh it.
					StuGra.open("StuGra.txt", ios::out | ios::trunc);
					StuGra.close();
					StuGra.open("StuGra.txt");

					for (int i = 0; i < TeaVec.size(); ++i) {
						if (firstline == false) {
							StuGra << "\n";
						}
						StuGra << TeaVec[i];
						firstline = false;
					}

					firstline = true;
					UserFound = false;
					linecounter = 0;
					LocationofStudent = 0;
					TeaVec.clear();

					StuGra.close();

					cout << StuUser << "'s Physical Education grade has been changed to: " << grade << endl;

					//Makes a new sub-menu for returning to menu or exiting.
					cout << "\n[1] Return to Menu\n[2] Sign Out\n\nSelection: ";
					cin >> TeaSM1;
					system("CLS");

					//Ensures the input is only one of the two valid options.
					while (TeaSM1 != 1 && TeaSM1 != 2) {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "Invalid entry.\nPlease try again: ";
						cin >> TeaSM1;
					}

					if (TeaSM1 == 1) {
						cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
						cout << "---------    UA HIGH SCHOOL     ---------" << endl;
						cout << "\n      ----- Teacher Menu -----" << endl;
						cout << "\nWelcome to the Teacher Menu.\n\n[1] Student Details\n[2] Student Grades\n[3] Exam Timetable\n[4] Sign out" << endl;
						cout << "\nPlease make a selection: ";
						cin >> TeaSM;
						while (TeaSM != 1 && TeaSM != 2 && TeaSM != 3 && TeaSM != 4) {
							cin.clear(); //Clears cin.
							cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
							cout << "Invalid entry.\nPlease try again: ";
							cin >> TeaSM;
						}
						break;
					}
					else if (TeaSM1 == 2) {
						CredFail = true;
						Tealogin = false;
					}
					break;
				}
				break;
			case 3:
				system("CLS");
					cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
					cout << "---------    UA HIGH SCHOOL     ---------" << endl;
					cout << "\n      ----- Teacher Menu -----" << endl;
					cout << "\nWelcome to the Teacher Menu.\n\n[1] Student Details\n[2] Student Grades\n[3] Exam Timetable\n[4] Sign out" << endl;
					cout << "\nPlease make a selection: ";
					cin >> TeaSM;
					while (TeaSM != 1 && TeaSM != 2 && TeaSM != 3 && TeaSM != 4) {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "Invalid entry.\nPlease try again: ";
						cin >> TeaSM;
					}
					break;
			}
			break;
		case 3:
			system("CLS");
			cout << "-- Exam Management --\n\n[1] View Exam Timetable\n[2] Change Exam Timetable\n[3] Return to Teacher Menu\n\nPlease make a selection: ";
			cin >> TeaSM3;
			while (TeaSM3 != 1 && TeaSM3 != 2 && TeaSM3 != 3) {
				cin.clear(); //Clears cin.
				cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
				cout << "Invalid entry.\nPlease try again: ";
				cin >> TeaSM3;
			}
			system("CLS");

			switch (TeaSM3) {
			case 1:
				//View Exam Timetable.
				cout << "--Exam Timetable --" << endl << endl;

				StuExa.open("StuExa.txt", ios::in); // Open
				// While there are still lines in the txt file
				while (getline(StuExa, line))
				{
					linecounter++;
					LocationofExam = 0;
					if (line == "English" || line == "Maths" || line == "Science" || line == "Social Studies" || line == "Physical Education") {
						cout << line << " Exam: " << endl;
						linecounter = LocationofExam;
					}

					if (linecounter == (LocationofExam + 1)) {
						cout << "Date: " << line << endl;
					}

					if (linecounter == (LocationofExam + 2)) {
						cout << "Time: " << line << endl << endl;
					}
				}

				LocationofExam = 0;
				linecounter = 0;

				StuExa.close();
				// Close the file:

								//Makes a new sub-menu for returning to menu or exiting.
				cout << "\n[1] Return to Menu\n[2] Sign Out\n\nSelection: ";
				cin >> TeaSM1;

				//Ensures the input is only one of the two valid options.
				while (TeaSM1 != 1 && TeaSM1 != 2) {
					cin.clear(); //Clears cin.
					cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
					cout << "Invalid entry.\nPlease try again: ";
					cin >> TeaSM1;
				}
				system("CLS");

				if (TeaSM1 == 1) {
					cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
					cout << "---------    UA HIGH SCHOOL     ---------" << endl;
					cout << "\n      ----- Teacher Menu -----" << endl;
					cout << "\nWelcome to the Teacher Menu.\n\n[1] Student Details\n[2] Student Grades\n[3] Exam Timetable\n[4] Sign out" << endl;
					cout << "\nPlease make a selection: ";
					cin >> TeaSM;
					while (TeaSM != 1 && TeaSM != 2 && TeaSM != 3 && TeaSM != 4) {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "Invalid entry.\nPlease try again: ";
						cin >> TeaSM;
					}
					break;
				}
				else if (TeaSM1 == 2) {
					CredFail = true;
					Tealogin = false;
				}

				break;
			case 2:
				//Change Exam Timetable.
				StuExa.open("StuExa.txt");

				cout << "Please type the subject of the exam you wish to change: ";
				cin.ignore();
				getline(cin, exam);

				LocationofExam = -10;
				linecounter = 0;

					while (ExaFound == false) {
						while (getline(StuExa, line)) {

							linecounter++;
							if (line == exam) {
								ExaFound = true;
								LocationofExam = linecounter;
							}

							if (linecounter == (LocationofExam + 1)) {
								Predate = line;
							}

							if (linecounter == (LocationofExam + 2)) {
								Pretime = line;
							}
						}
						if (ExaFound == false) {
							cout << "Exam subject not found. Please enter again: ";
							cin.ignore();
							getline(cin, exam);

							//Resets the file so that it can be read again.
							StuExa.clear();
							StuExa.seekg(0);
							LocationofExam = -10;
							linecounter = 0;
						}
					}

					StuExa.close();

					linecounter = 0;
					LocationofExam = -50;
					
					cout << "The current " << exam << " exam date is: " << Predate << endl;
					cout << "The current " << exam << " exam date is: " << Pretime << endl;
					cout << "Please enter a new date (format: XX.XX.XXXX): ";
					cin >> Exadate;
					cout << "Please enter a new time (format: XX:XXxm): ";
					cin >> Exatime;

					StuExa.open("StuExa.txt");

				while (getline(StuExa, line)) {
					linecounter++;
					if (linecounter != (LocationofExam + 1) && linecounter != (LocationofExam + 2)) {
						TeaVec.push_back(line);
					}
					if (line == exam) {
						LocationofExam = linecounter;
					}

					if (linecounter == (LocationofExam + 1)) {
						TeaVec.push_back(Exadate);
					}

					if (linecounter == (LocationofExam + 2)) {
						TeaVec.push_back(Exatime);
					}
				}
				StuExa.close();

				//Open the file to refresh it.
				StuExa.open("StuExa.txt", ios::out | ios::trunc);
				StuExa.close();
				StuExa.open("StuExa.txt");

				for (int i = 0; i < TeaVec.size(); ++i) {
					if (firstline == false) {
						StuExa << "\n";
					}
					StuExa << TeaVec[i];
					firstline = false;
				}

				//Reset everything so that the previous values are dismissed.
				firstline = true;
				ExaFound = false;
				linecounter = 0;
				LocationofExam = 0;
				TeaVec.clear();

				StuExa.close();

				//Makes a new sub-menu for returning to menu or exiting.
				cout << "\n[1] Return to Menu\n[2] Sign Out\n\nSelection: ";
				cin >> TeaSM1;

				//Ensures the input is only one of the two valid options.
				while (TeaSM1 != 1 && TeaSM1 != 2) {
					cin.clear(); //Clears cin.
					cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
					cout << "Invalid entry.\nPlease try again: ";
					cin >> TeaSM1;
				}
				system("CLS");

				if (TeaSM1 == 1) {
					cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
					cout << "---------    UA HIGH SCHOOL     ---------" << endl;
					cout << "\n      ----- Teacher Menu -----" << endl;
					cout << "\nWelcome to the Teacher Menu.\n\n[1] Student Details\n[2] Student Grades\n[3] Exam Timetable\n[4] Sign out" << endl;
					cout << "\nPlease make a selection: ";
					cin >> TeaSM;
					while (TeaSM != 1 && TeaSM != 2 && TeaSM != 3 && TeaSM != 4) {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "Invalid entry.\nPlease try again: ";
						cin >> TeaSM;
					}
					break;
				}
				else if (TeaSM1 == 2) {
					CredFail = true;
					Tealogin = false;
				}
				break;
			case 3:
				system("CLS");
					cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
					cout << "---------    UA HIGH SCHOOL     ---------" << endl;
					cout << "\n      ----- Teacher Menu -----" << endl;
					cout << "\nWelcome to the Teacher Menu.\n\n[1] Student Details\n[2] Student Grades\n[3] Exam Timetable\n[4] Sign out" << endl;
					cout << "\nPlease make a selection: ";
					cin >> TeaSM;
					while (TeaSM != 1 && TeaSM != 2 && TeaSM != 3 && TeaSM != 4) {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "Invalid entry.\nPlease try again: ";
						cin >> TeaSM;
					}
					break;
				}
			break;
		case 4:
			//Logout.
			CredFail = true;
			Tealogin = false;
			system("CLS");
			break;
		}
	}
}
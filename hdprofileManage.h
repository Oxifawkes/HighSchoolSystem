#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "hdAdm.h"

using namespace std;

//Adds a new student.
void addNewStu()
{
	//Initiallizing variables
	fstream teaFile;
	fstream stuDet;
	fstream stuGrade;
	fstream stuID;
	string user, pass;

	string fname, lname, eng, math, sci, soc, pe, position, parent1Fn, parent2Fn, parent1Ln, parent2Ln;
	int choice, age, year;

	cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
	cout << "---------    UA HIGH SCHOOL     ---------" << endl;
	cout << "           -- Add Student --" << endl << endl;

	cout << "\nEnter the user's first name (Example: Luke): ";
	cin >> fname;

	cout << "\nEnter the user's last name (Example: Johnson): ";
	cin >> lname;

	//Combines the first name and last name to create their username.
	user = fname + lname;

	cout << "\nEnter the user's password: ";
	cin >> pass;

	cout << "\nEnter the user's age (12-18): ";
	cin >> age;
	while (age < 12 || age > 18) {
		cin.clear(); //Clears cin.
		cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
		cout << "\nInvalid age for student.\nPlease try again: ";
		cin >> age;
	}

	cout << "\nEnter the user's year group (9-13): ";
	cin >> year;

	while (year < 9 || year > 13) {
		cin.clear(); //Clears cin.
		cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
		cout << "\nInvalid age for student.\nPlease try again: ";
		cin >> year;
	}

	cout << "\nEnter the user's grades: ";
	cout << "\nEnglish: ";
	cin >> eng;
	while (eng != "F" && eng != "D" && eng != "C-" && eng != "C" && eng != "C+" && eng != "B-" && eng != "B" && eng != "B+" && eng != "A-" && eng != "A" && eng != "A+") {
		cin.clear(); //Clears cin.
		cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
		cout << "\nInvalid grade (A, B-, C+, D, etc).\nPlease try again: ";
		cin >> eng;
	}

	cout << "\nMaths: ";
	cin >> math;
	while (math != "F" && math != "D" && math != "C-" && math != "C" && math != "C+" && math != "B-" && math != "B" && math != "B+" && math != "A-" && math != "A" && math != "A+") {
		cin.clear(); //Clears cin.
		cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
		cout << "\nInvalid grade (A, B-, C+, D, etc).\nPlease try again: ";
		cin >> math;
	}

	cout << "\nScience: ";
	cin >> sci;
	while (sci != "F" && sci != "D" && sci != "C-" && sci != "C" && sci != "C+" && sci != "B-" && sci != "B" && sci != "B+" && sci != "A-" && sci != "A" && sci != "A+") {
		cin.clear(); //Clears cin.
		cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
		cout << "\nInvalid grade (A, B-, C+, D, etc).\nPlease try again: ";
		cin >> sci;
	}

	cout << "\nSocial Studies: ";
	cin >> soc;
	while (soc != "F" && soc != "D" && soc != "C-" && soc != "C" && soc != "C+" && soc != "B-" && soc != "B" && soc != "B+" && soc != "A-" && soc != "A" && soc != "A+") {
		cin.clear(); //Clears cin.
		cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
		cout << "\nInvalid grade (A, B-, C+, D, etc).\nPlease try again: ";
		cin >> soc;
	}

	cout << "\nPhysical Education: ";
	cin >> pe;
	while (pe != "F" && pe != "D" && pe != "C-" && pe != "C" && pe != "C+" && pe != "B-" && pe != "B" && pe != "B+" && pe != "A-" && pe != "A" && pe != "A+") {
		cin.clear(); //Clears cin.
		cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
		cout << "\nInvalid grade (A, B-, C+, D, etc).\nPlease try again: ";
		cin >> pe;
	}

	position = "Student";

	cout << "\nEnter the user's first parent's first name: ";
	cin >> parent1Fn;
	cout << "\nEnter the user's first parent's last name: ";
	cin >> parent1Ln;

	cout << "\nEnter the user's second parent's first name (or type N/A): ";
	cin >> parent2Fn;

	if (parent2Fn != "N/A") {
		cout << "\nEnter the user's second parent's last name: ";
		cin >> parent2Ln;
	}

	if (parent2Fn == "N/A") {
		parent2Ln = "";
	}

	//Asks the user for confirmation of account creation.
	cout << "\nConfirm Account Creation for " << user << ".\n\n[1] Create Account\n[2] Back to User Management.\n\nSelection: ";
	cin >> choice;

	while (choice != 1 && choice != 2) {
		cin.clear(); //Clears cin.
		cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
		cout << "\nInvalid entry.\nPlease try again: ";
		cin >> choice;
	}

	//if choice is 1, then the account will be created. Otherwise it will not.
	if (choice == 1) {

		//Adding their user and pass to the system
		stuID.open("StuID.txt", ios::out | ios::app);
		stuID << endl << user << endl << pass;

		stuID.close();
		//Adding their intial grades in
		stuGrade.open("StuGra.txt", ios::out | ios::app);
		stuGrade << endl << "---*---" << endl;
		stuGrade << user << endl << "English" << endl << eng << endl << "Maths" << endl << math << endl << "Science" << endl << sci << endl << "Social Studies" << endl << soc << endl << "Physical Education" << endl << pe;

		stuGrade.close();
		//Adding them to the student details file for easy management
		stuDet.open("StuDet.txt", ios::out | ios::app);
		stuDet << endl << "---*---" << endl;
		stuDet << user << endl << fname << " " << lname << endl << age << endl << year << endl << position << endl << parent1Fn << " " << parent1Ln << endl << parent2Fn << " " << parent2Ln;

		stuDet.close();
	}

}
//Adding a new teacher to the system
void addNewTea()
{
	fstream teaID;
	fstream teaDet;
	string user, pass, fname, lname, edu, edu2, position, subject, qualchoice;
	int age, choice;

	cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
	cout << "---------    UA HIGH SCHOOL     ---------" << endl;
	cout << "           -- Add Teacher --" << endl << endl;

	//Adding their details to the teacher ID file

	cout << "\nEnter the user's First name (Example: Jane): ";
	cin >> fname;

	cout << "\nEnter the user's Last name (Example: Wilkins): ";
	cin >> lname;

	cout << "\nEnter the user's password: ";
	cin >> pass;

	//Combines the first name and last name to create their username.
	user = fname + lname;

	cout << "\nEnter the user's age: ";
	cin >> age;

	while (age < 19 || age > 125) {
		cin.clear(); //Clears cin.
		cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
		cout << "\nInvalid teacher age.\nPlease try again: ";
		cin >> age;
	}

	cout << "\nEnter the user's first qualification (Bed, MA, etc.): ";
	cin >> edu;

	cout << "\nAdd a secondary qualification? y/n? Selection: ";
	cin >> qualchoice;

	while (qualchoice != "y" && qualchoice != "Y" && qualchoice != "N" && qualchoice != "n") {
		cin.clear(); //Clears cin.
		cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
		cout << "\nInvalid entry.\nPlease try again: ";
		cin >> qualchoice;
	}

	if (qualchoice == "Y" || qualchoice == "y") {
		cout << "\nEnter the user's second qualification (BSc, Bed, etc.): ";
		cin >> edu2;
		edu = edu + " & " + edu2;
	}

	cout << "\nEnter the user's position (Teacher or Dean): ";
	cin >> position;

	while (position != "Teacher" && position != "Dean") {
		cin.clear(); //Clears cin.
		cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
		cout << "\nInvalid entry.\nPlease try again: ";
		cin >> position;
	}

	cout << "\nEnter the user's teaching class (or enter N/A): ";
	cin.ignore();
	getline(cin, subject);

	//Asks the user for confirmation of account creation.
	cout << "\nConfirm Account Creation for " << user << ".\n\n[1] Create Account\n[2] Back to User Management.\n\nSelection: ";
	cin >> choice;

	while (choice != 1 && choice != 2) {
		cin.clear(); //Clears cin.
		cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
		cout << "\nInvalid entry.\nPlease try again: ";
		cin >> choice;
	}

	//if choice is 1, then the account will be created. Otherwise it will not.
	if (choice == 1) {

		teaID.open("TeaID.txt", ios::out | ios::app);
		teaID << endl << user << endl << pass;
		//Closes the ID file
		teaID.close();

		teaDet.open("StaDet.txt", ios::out | ios::app);
		teaDet << endl << "---*---" << endl << user << endl << fname << " " << lname << endl << age << endl << edu << endl << position << endl << subject;
		//Closes the Details file.
		teaDet.close();
	}
}

//Allows the admin to manage a student or teacher account.
void manageExisting()
{
	//Declaring and initalizing variables.
	string StuUser, TeaUser, pass, line, grade, detail, detail2, qualchoice;
	fstream StuDet;
	fstream StuGra;
	fstream StuID;
	fstream StuExa;
	fstream StaDet;
	fstream TeaID;
	fstream Temp;
	vector<string> AdmVec;
	int linecounter = 0;
	int lines1, lines2, lines3;
	int LocationofStudent = 0;
	int LocationofStudent1 = 0;
	int LocationofStudent2 = 0;
	int LocationofStudent3 = 0;
	int LocationofTeacher = 0;
	int LocationofTeacher1 = 0;
	int LocationofTeacher2 = 0;
	int studentcounter = 0;
	int teachercounter = 0;
	int choice;
	int ManSM, ManSM1, ManSM2, ManSM3, ManSM4, ManSM5, ManSM6, ManSM7, SM;
	bool ManMenu = true;
	bool UserFound = false;
	bool firstline = true;
	bool stop = false;
	bool AdmCheck = false;
	cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
	cout << "---------    UA HIGH SCHOOL     ---------" << endl;
	cout << "         -- User Management --" << endl << endl;
	cout << "[1] View Student Files" << endl;
	cout << "[2] Edit/Delete Student Files" << endl;
	cout << "[3] View Teacher Files" << endl;
	cout << "[4] Edit/Delete Teacher Files" << endl;
	cout << "[5] Return to Admin Menu" << endl;
	cout << "\nPlease make a selection: ";
	cin >> ManSM;

	while (ManSM != 1 && ManSM != 2 && ManSM != 3 && ManSM != 4 && ManSM != 5) {
		cin.clear(); //Clears cin.
		cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
		cout << "\nInvalid entry.\nPlease try again: ";
		cin >> ManSM;
	}

	//initalize menu bool in case of repeat menu use by Admin.
	ManMenu = true;

	system("CLS");

	switch (ManSM) {
	case 1:

		cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
		cout << "---------    UA HIGH SCHOOL     ---------" << endl;
		cout << "        -- View Student Files --" << endl << endl;
		cout << "[1] View Student ID and Passwords" << endl;
		cout << "[2] View Student Details" << endl;
		cout << "[3] View Student Grades" << endl;
		cout << "\nPlease make a selection: ";
		cin >> ManSM1;

		while (ManSM1 != 1 && ManSM1 != 2 && ManSM1 != 3) {
			cin.clear(); //Clears cin.
			cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
			cout << "\nInvalid entry.\nPlease try again: ";
			cin >> ManSM1;
		}

		system("CLS");

		switch (ManSM1) {
			//View Student IDs and Passwords.
		case 1:
			cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
			cout << "---------    UA HIGH SCHOOL     ---------" << endl;
			cout << "   -- View Student ID and Passwords --" << endl << endl;

			StuID.open("StuID.txt", ios::out || ios::in);
			while (getline(StuID, line))
			{
				linecounter++;

				//Every even line should print this.
				if (linecounter % 2 == 0) {
					cout << "Password: " << line << endl << endl;
				}

				//Every other line should print this.
				else {
					cout << "Username: " << line << endl;
				}

			}

			//Reset linecounter.
			linecounter = 0;

			StuID.close();

			//Makes a new sub-menu for returning to the user management or admin menu.
			cout << "\n[1] Return to User Management Menu\n[2] Back to Admin Menu\n\nSelection: ";
			cin >> SM;

			//Ensures the input is only one of the two valid options.
			while (SM != 1 && SM != 2) {
				cin.clear(); //Clears cin.
				cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
				cout << "\nInvalid entry.\nPlease try again: ";
				cin >> SM;
			}
			system("CLS");

			if (SM == 1) {
				manageExisting();
				break;
			}
			else if (SM == 2) {
				system("CLS");
				fAdmSM();
				break;
			}
			break;

			//View Student Details.
		case 2:

			cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
			cout << "---------    UA HIGH SCHOOL     ---------" << endl;
			cout << "        -- View Student Details --" << endl << endl;
			StuDet.open("StuDet.txt", ios::in); // Open
			// While there are still lines in the txt file
			while (getline(StuDet, line))
			{
				//Admin can view all the student details in the file.
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

			//Makes a new sub-menu for returning to the user management or admin menu.
			cout << "\n[1] Return to User Management Menu\n[2] Back to Admin Menu\n\nSelection: ";
			cin >> SM;

			//Ensures the input is only one of the two valid options.
			while (SM != 1 && SM != 2) {
				cin.clear(); //Clears cin.
				cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
				cout << "\nInvalid entry.\nPlease try again: ";
				cin >> SM;
			}
			system("CLS");

			if (SM == 1) {
				manageExisting();
				break;
			}
			else if (SM == 2) {
				system("CLS");
				fAdmSM();
				break;
			}
			break;

			//View Student Grades.
		case 3:
			cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
			cout << "---------    UA HIGH SCHOOL     ---------" << endl;
			cout << "        -- View Student Grades --" << endl << endl;
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

			//Makes a new sub-menu for returning to the user management or admin menu.
			cout << "\n[1] Return to User Management Menu\n[2] Back to Admin Menu\n\nSelection: ";
			cin >> SM;

			//Ensures the input is only one of the two valid options.
			while (SM != 1 && SM != 2) {
				cin.clear(); //Clears cin.
				cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
				cout << "\nInvalid entry.\nPlease try again: ";
				cin >> SM;
			}
			system("CLS");

			if (SM == 1) {
				manageExisting();
				break;
			}
			else if (SM == 2) {
				system("CLS");
				fAdmSM();
				break;
			}
			break;
		}
		break;
	case 2:
		cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
		cout << "---------    UA HIGH SCHOOL     ---------" << endl;
		cout << "     -- Edit/Delete Student Files --" << endl << endl;
		cout << "[1] Edit Student Files" << endl;
		cout << "[2] Delete a Student Profile" << endl;
		cout << "[3] Return to User Management" << endl;
		cout << "\nPlease make a selection: ";
		cin >> ManSM2;

		while (ManSM2 != 1 && ManSM2 != 2 && ManSM2 != 3) {
			cin.clear(); //Clears cin.
			cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
			cout << "\nInvalid entry.\nPlease try again: ";
			cin >> ManSM2;
		}


		system("CLS");

		switch (ManSM2) {

			//Edit Student Files.
			//One more sub-menu to Edit Student Profile, Edit Student Grades and Edit Student Password.
		case 1:
			cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
			cout << "---------    UA HIGH SCHOOL     ---------" << endl;
			cout << "         -- Edit Student Files --" << endl << endl;
			cout << "[1] Edit Student Password" << endl;
			cout << "[2] Edit Student Details" << endl;
			cout << "[3] Edit Student Grades" << endl;
			cout << "[4] Return to User Management" << endl;
			cout << "\nPlease make a selection: ";
			cin >> ManSM5;

			while (ManSM5 != 1 && ManSM5 != 2 && ManSM5 != 3 && ManSM5 != 4) {
				cin.clear(); //Clears cin.
				cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
				cout << "\nInvalid entry.\nPlease try again: ";
				cin >> ManSM5;
			}

			system("CLS");

			switch (ManSM5) {
				//Edit Student Password.
			case 1:
				cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
				cout << "---------    UA HIGH SCHOOL     ---------" << endl;
				cout << "       -- Edit Student Password --" << endl << endl;
				cout << "Please enter a Student Username: ";
				cin >> StuUser;

				StuID.open("StuID.txt", ios::in);

				while (UserFound == false) {
					while (getline(StuID, line)) {

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
						StuID.clear();
						StuID.seekg(0);
					}
				}

				StuID.close();

				cout << "Please enter a new Student Password: ";
				cin >> pass;
				StuID.open("StuID.txt");

				LocationofStudent = -50;

				while (getline(StuID, line)) {
					linecounter++;
					if (linecounter != (LocationofStudent + 1)) {
						AdmVec.push_back(line);
					}
					if (line == StuUser) {
						LocationofStudent = linecounter;
					}

					if (linecounter == (LocationofStudent + 1)) {
						AdmVec.push_back(pass);
					}
				}
				StuID.close();

				//Open the file to refresh it.
				StuID.open("StuID.txt", ios::out | ios::trunc);
				StuID.close();
				StuID.open("StuID.txt");

				for (int i = 0; i < AdmVec.size(); ++i) {
					if (firstline == false) {
						StuID << "\n";
					}
					StuID << AdmVec[i];
					firstline = false;
				}

				firstline = true;
				UserFound = false;
				linecounter = 0;
				LocationofStudent = 0;
				AdmVec.clear();

				StuID.close();

				//Makes a new sub-menu for returning to the user management or admin menu.
				cout << "\n[1] Return to User Management Menu\n[2] Back to Admin Menu\n\nSelection: ";
				cin >> SM;

				//Ensures the input is only one of the two valid options.
				while (SM != 1 && SM != 2) {
					cin.clear(); //Clears cin.
					cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
					cout << "\nInvalid entry.\nPlease try again: ";
					cin >> SM;
				}
				system("CLS");

				if (SM == 1) {
					break;
				}
				else if (SM == 2) {
					system("CLS");
					fAdmSM();
					break;
				}
				break;

				//Edit Student Details.
			case 2:
				//Asks the user for a student's username.
				cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
				cout << "---------    UA HIGH SCHOOL     ---------" << endl;
				cout << "       -- Edit Student Details --" << endl << endl;
				cout << "Please enter the student's username: ";
				cin >> StuUser;

				StuDet.open("StuDet.txt", ios::in);

				while (UserFound == false) {
					while (getline(StuDet, line)) {

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
						StuDet.clear();
						StuDet.seekg(0);
					}
				}

				StuDet.close();

				//Reset the line counter and LocationofStudent to prevent conflicts.
				linecounter = 0;
				LocationofStudent = -50; //Leaves buffer so that it doesn't trip up loops.

				//Asks the user for another sub-menu option.
				cout << "\n[1] Age\n[2] Year Group\n[3] First Guardian\n[4] Second Guardian\n[5] Exit\n";
				cout << "\nPlease select the subject grade you wish to change: ";
				cin >> ManSM7;

				while (ManSM7 < 1 && ManSM7 > 5) {
					cin.clear(); //Clears cin.
					cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
					cout << "\nInvalid entry.\nPlease try again: ";
					cin >> ManSM7;
				}
				system("CLS");

				switch (ManSM7) {
				case 1:
					//Change Age

					cout << "Enter the student's new age (between 12 and 18): ";
					cin >> detail;

					StuDet.open("StuDet.txt");

					while (getline(StuDet, line)) {
						linecounter++;
						if (linecounter != (LocationofStudent + 2)) {
							AdmVec.push_back(line);
						}
						if (line == StuUser) {
							LocationofStudent = linecounter;
						}

						if (linecounter == (LocationofStudent + 2)) {
							AdmVec.push_back(detail);
						}
					}
					StuDet.close();

					//Open the file to refresh it.
					StuDet.open("StuDet.txt", ios::out | ios::trunc);
					StuDet.close();
					StuDet.open("StuDet.txt");

					for (int i = 0; i < AdmVec.size(); ++i) {
						if (firstline == false) {
							StuDet << "\n";
						}
						StuDet << AdmVec[i];
						firstline = false;
					}

					firstline = true;
					UserFound = false;
					linecounter = 0;
					LocationofStudent = 0;
					AdmVec.clear();

					StuDet.close();

					//Makes a new sub-menu for returning to the user management or admin menu.
					cout << "\n[1] Return to User Management Menu\n[2] Back to Admin Menu\n\nSelection: ";
					cin >> SM;

					//Ensures the input is only one of the two valid options.
					while (SM != 1 && SM != 2) {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "\nInvalid entry.\nPlease try again: ";
						cin >> SM;
					}
					system("CLS");

					if (SM == 1) {
						break;
					}
					else if (SM == 2) {
						system("CLS");
						fAdmSM();
						break;
					}
					break;
				case 2:
					//Change Year Group

					cout << "Enter the student's new year group (between 9 and 13): ";
					cin >> detail;

					StuDet.open("StuDet.txt");

					while (getline(StuDet, line)) {
						linecounter++;
						if (linecounter != (LocationofStudent + 3)) {
							AdmVec.push_back(line);
						}
						if (line == StuUser) {
							LocationofStudent = linecounter;
						}

						if (linecounter == (LocationofStudent + 3)) {
							AdmVec.push_back(detail);
						}
					}
					StuDet.close();

					//Open the file to refresh it.
					StuDet.open("StuDet.txt", ios::out | ios::trunc);
					StuDet.close();
					StuDet.open("StuDet.txt");

					for (int i = 0; i < AdmVec.size(); ++i) {
						if (firstline == false) {
							StuDet << "\n";
						}
						StuDet << AdmVec[i];
						firstline = false;
					}

					firstline = true;
					UserFound = false;
					linecounter = 0;
					LocationofStudent = 0;
					AdmVec.clear();

					StuDet.close();

					//Makes a new sub-menu for returning to the user management or admin menu.
					cout << "\n[1] Return to User Management Menu\n[2] Back to Admin Menu\n\nSelection: ";
					cin >> SM;

					//Ensures the input is only one of the two valid options.
					while (SM != 1 && SM != 2) {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "\nInvalid entry.\nPlease try again: ";
						cin >> SM;
					}
					system("CLS");

					if (SM == 1) {
						break;
					}
					else if (SM == 2) {
						system("CLS");
						fAdmSM();
						break;
					}
					break;
				case 3:
					//Change First Guardian
					cout << "Enter the student's new first parent/guardian's first name: ";
					cin >> detail;
					cout << "\nEnter the student's new first parent/guardian's second name: ";
					cin >> detail2;

					StuDet.open("StuDet.txt");

					while (getline(StuDet, line)) {
						linecounter++;
						if (linecounter != (LocationofStudent + 5)) {
							AdmVec.push_back(line);
						}
						if (line == StuUser) {
							LocationofStudent = linecounter;
						}

						if (linecounter == (LocationofStudent + 5)) {
							AdmVec.push_back(detail + " " + detail2);
						}
					}
					StuDet.close();

					//Open the file to refresh it.
					StuDet.open("StuDet.txt", ios::out | ios::trunc);
					StuDet.close();
					StuDet.open("StuDet.txt");

					for (int i = 0; i < AdmVec.size(); ++i) {
						if (firstline == false) {
							StuDet << "\n";
						}
						StuDet << AdmVec[i];
						firstline = false;
					}

					firstline = true;
					UserFound = false;
					linecounter = 0;
					LocationofStudent = 0;
					AdmVec.clear();

					StuDet.close();

					//Makes a new sub-menu for returning to the user management or admin menu.
					cout << "\n[1] Return to User Management Menu\n[2] Back to Admin Menu\n\nSelection: ";
					cin >> SM;

					//Ensures the input is only one of the two valid options.
					while (SM != 1 && SM != 2) {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "\nInvalid entry.\nPlease try again: ";
						cin >> SM;
					}
					system("CLS");

					if (SM == 1) {
						break;
					}
					else if (SM == 2) {
						system("CLS");
						fAdmSM();
						break;
					}
					break;
				case 4:
					//Change Second Guardian
					cout << "Enter the student's new second parent/guardian's first name (please type 'N/A' if none are applicable): ";
					cin >> detail;
					//Makes sure Detail2 is uninitalized in case the user enters N/A and has previously used this  or the above section.
					detail2 = "";
					if (detail != "N/A") {
						cout << "\nEnter the student's new second parent/guardian's second name: ";
						cin >> detail2;
					}

					StuDet.open("StuDet.txt");

					while (getline(StuDet, line)) {
						linecounter++;
						if (linecounter != (LocationofStudent + 5)) {
							AdmVec.push_back(line);
						}
						if (line == StuUser) {
							LocationofStudent = linecounter;
						}

						if (linecounter == (LocationofStudent + 5)) {
							AdmVec.push_back(detail + " " + detail2);
						}
					}
					StuDet.close();

					//Open the file to refresh it.
					StuDet.open("StuDet.txt", ios::out | ios::trunc);
					StuDet.close();
					StuDet.open("StuDet.txt");

					for (int i = 0; i < AdmVec.size(); ++i) {
						if (firstline == false) {
							StuDet << "\n";
						}
						StuDet << AdmVec[i];
						firstline = false;
					}

					firstline = true;
					UserFound = false;
					linecounter = 0;
					LocationofStudent = 0;
					AdmVec.clear();

					StuDet.close();

					//Makes a new sub-menu for returning to the user management or admin menu.
					cout << "\n[1] Return to User Management Menu\n[2] Back to Admin Menu\n\nSelection: ";
					cin >> SM;

					//Ensures the input is only one of the two valid options.
					while (SM != 1 && SM != 2) {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "\nInvalid entry.\nPlease try again: ";
						cin >> SM;
					}
					system("CLS");

					if (SM == 1) {
						break;
					}
					else if (SM == 2) {
						system("CLS");
						fAdmSM();
						break;
					}
					break;
				case 5:
					//Exit
					break;
				}
				break;
				//Edit Student Grades.
			case 3:
				//Asks the user for a student's username.
				cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
				cout << "---------    UA HIGH SCHOOL     ---------" << endl;
				cout << "       -- Edit Student Grades --" << endl << endl;
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
				cin >> ManSM7;

				while (ManSM7 < 1 && ManSM7 > 6) {
					cin.clear(); //Clears cin.
					cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
					cout << "\nInvalid entry.\nPlease try again: ";
					cin >> ManSM7;
				}

				cout << "\nEnter the student's new grade: ";
				cin >> grade;

				while (grade != "F" && grade != "D" && grade != "C-" && grade != "C" && grade != "C+" && grade != "B-" && grade != "B" && grade != "B+" && grade != "A-" && grade != "A" && grade != "A+") {
					cin.clear(); //Clears cin.
					cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
					cout << "\nInvalid entry.\nPlease try again: ";
					cin >> grade;
				}

				//Switch Menu for changing the grade of a specific subject.
				switch (ManSM7) {
				case 1:
					//Change English Grade.
					StuGra.open("StuGra.txt");

					while (getline(StuGra, line)) {
						linecounter++;
						if (linecounter != (LocationofStudent + 2)) {
							AdmVec.push_back(line);
						}
						if (line == StuUser) {
							LocationofStudent = linecounter;
						}

						if (linecounter == (LocationofStudent + 2)) {
							AdmVec.push_back(grade);
						}
					}
					StuGra.close();

					//Open the file to refresh it.
					StuGra.open("StuGra.txt", ios::out | ios::trunc);
					StuGra.close();
					StuGra.open("StuGra.txt");

					for (int i = 0; i < AdmVec.size(); ++i) {
						if (firstline == false) {
							StuGra << "\n";
						}
						StuGra << AdmVec[i];
						firstline = false;
					}

					firstline = true;
					UserFound = false;
					linecounter = 0;
					LocationofStudent = 0;
					AdmVec.clear();

					StuGra.close();

					cout << StuUser << "'s English grade has been changed to: " << grade << endl;

					//Makes a new sub-menu for returning to the user management or admin menu.
					cout << "\n[1] Return to User Management Menu\n[2] Back to Admin Menu\n\nSelection: ";
					cin >> SM;

					//Ensures the input is only one of the two valid options.
					while (SM != 1 && SM != 2) {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "\nInvalid entry.\nPlease try again: ";
						cin >> SM;
					}
					system("CLS");

					if (SM == 1) {
						system("CLS");
						manageExisting();
						break;
					}
					else if (SM == 2) {
						system("CLS");
						fAdmSM();
						break;
					}
					break;
				case 2:
					//Change Maths Grade.
					StuGra.open("StuGra.txt");

					while (getline(StuGra, line)) {
						linecounter++;
						if (linecounter != (LocationofStudent + 4)) {
							AdmVec.push_back(line);
						}
						if (line == StuUser) {
							LocationofStudent = linecounter;
						}

						if (linecounter == (LocationofStudent + 4)) {
							AdmVec.push_back(grade);
						}
					}
					StuGra.close();

					//Open the file to refresh it.
					StuGra.open("StuGra.txt", ios::out | ios::trunc);
					StuGra.close();
					StuGra.open("StuGra.txt");

					for (int i = 0; i < AdmVec.size(); ++i) {
						if (firstline == false) {
							StuGra << "\n";
						}
						StuGra << AdmVec[i];
						firstline = false;
					}

					firstline = true;
					UserFound = false;
					linecounter = 0;
					LocationofStudent = 0;
					AdmVec.clear();

					StuGra.close();

					cout << StuUser << "'s Maths grade has been changed to: " << grade << endl;

					//Makes a new sub-menu for returning to the user management or admin menu.
					cout << "\n[1] Return to User Management Menu\n[2] Back to Admin Menu\n\nSelection: ";
					cin >> SM;

					//Ensures the input is only one of the two valid options.
					while (SM != 1 && SM != 2) {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "\nInvalid entry.\nPlease try again: ";
						cin >> SM;
					}
					system("CLS");

					if (SM == 1) {
						system("CLS");
						manageExisting();
						break;
					}
					else if (SM == 2) {
						system("CLS");
						fAdmSM();
						break;
					}
					break;
				case 3:
					//Change Science Grade.
					StuGra.open("StuGra.txt");

					while (getline(StuGra, line)) {
						linecounter++;
						if (linecounter != (LocationofStudent + 6)) {
							AdmVec.push_back(line);
						}
						if (line == StuUser) {
							LocationofStudent = linecounter;
						}

						if (linecounter == (LocationofStudent + 6)) {
							AdmVec.push_back(grade);
						}
					}
					StuGra.close();

					//Open the file to refresh it.
					StuGra.open("StuGra.txt", ios::out | ios::trunc);
					StuGra.close();
					StuGra.open("StuGra.txt");

					for (int i = 0; i < AdmVec.size(); ++i) {
						if (firstline == false) {
							StuGra << "\n";
						}
						StuGra << AdmVec[i];
						firstline = false;
					}

					firstline = true;
					UserFound = false;
					linecounter = 0;
					LocationofStudent = 0;
					AdmVec.clear();

					StuGra.close();

					cout << StuUser << "'s Science grade has been changed to: " << grade << endl;

					//Makes a new sub-menu for returning to the user management or admin menu.
					cout << "\n[1] Return to User Management Menu\n[2] Back to Admin Menu\n\nSelection: ";
					cin >> SM;

					//Ensures the input is only one of the two valid options.
					while (SM != 1 && SM != 2) {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "\nInvalid entry.\nPlease try again: ";
						cin >> SM;
					}
					system("CLS");

					if (SM == 1) {
						system("CLS");
						manageExisting();
						break;
					}
					else if (SM == 2) {
						system("CLS");
						fAdmSM();
						break;
					}
					break;
				case 4:
					//Change Social Studies Grade.
					StuGra.open("StuGra.txt");

					while (getline(StuGra, line)) {
						linecounter++;
						if (linecounter != (LocationofStudent + 8)) {
							AdmVec.push_back(line);
						}
						if (line == StuUser) {
							LocationofStudent = linecounter;
						}

						if (linecounter == (LocationofStudent + 8)) {
							AdmVec.push_back(grade);
						}
					}
					StuGra.close();

					//Open the file to refresh it.
					StuGra.open("StuGra.txt", ios::out | ios::trunc);
					StuGra.close();
					StuGra.open("StuGra.txt");

					for (int i = 0; i < AdmVec.size(); ++i) {
						if (firstline == false) {
							StuGra << "\n";
						}
						StuGra << AdmVec[i];
						firstline = false;
					}

					firstline = true;
					UserFound = false;
					linecounter = 0;
					LocationofStudent = 0;
					AdmVec.clear();

					StuGra.close();

					cout << StuUser << "'s Social Studies grade has been changed to: " << grade << endl;

					//Makes a new sub-menu for returning to the user management or admin menu.
					cout << "\n[1] Return to User Management Menu\n[2] Back to Admin Menu\n\nSelection: ";
					cin >> SM;

					//Ensures the input is only one of the two valid options.
					while (SM != 1 && SM != 2) {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "\nInvalid entry.\nPlease try again: ";
						cin >> SM;
					}
					system("CLS");

					if (SM == 1) {
						system("CLS");
						manageExisting();
						break;
					}
					else if (SM == 2) {
						system("CLS");
						fAdmSM();
						break;
					}
					break;
				case 5:
					//Change Physical Education Grade.
					StuGra.open("StuGra.txt");

					while (getline(StuGra, line)) {
						linecounter++;
						if (linecounter != (LocationofStudent + 10)) {
							AdmVec.push_back(line);
						}
						if (line == StuUser) {
							LocationofStudent = linecounter;
						}

						if (linecounter == (LocationofStudent + 10)) {
							AdmVec.push_back(grade);
						}
					}
					StuGra.close();

					//Open the file to refresh it.
					StuGra.open("StuGra.txt", ios::out | ios::trunc);
					StuGra.close();
					StuGra.open("StuGra.txt");

					for (int i = 0; i < AdmVec.size(); ++i) {
						if (firstline == false) {
							StuGra << "\n";
						}
						StuGra << AdmVec[i];
						firstline = false;
					}

					firstline = true;
					UserFound = false;
					linecounter = 0;
					LocationofStudent = 0;
					AdmVec.clear();

					StuGra.close();

					cout << StuUser << "'s Physical Education grade has been changed to: " << grade << endl;

					//Makes a new sub-menu for returning to the user management or admin menu.
					cout << "\n[1] Return to User Management Menu\n[2] Back to Admin Menu\n\nSelection: ";
					cin >> SM;

					//Ensures the input is only one of the two valid options.
					while (SM != 1 && SM != 2) {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "\nInvalid entry.\nPlease try again: ";
						cin >> SM;
					}
					system("CLS");

					if (SM == 1) {
						system("CLS");
						manageExisting();
						break;
					}
					else if (SM == 2) {
						system("CLS");
						fAdmSM();
						break;
					}
					break;
				}

			case 4:
				system("CLS");
				manageExisting();
				break;
			}
			break;

			//Delete a Student Profile from StuDet, StuGra and StuID.
		case 2:
			cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
			cout << "---------    UA HIGH SCHOOL     ---------" << endl;
			cout << "     -- Delete Student Profile --" << endl << endl;
			cout << "Please enter a Student Username to Delete: ";
			cin >> StuUser;

			StuID.open("StuID.txt", ios::in);
			//Finds the User in StuID.
			while (UserFound == false) {
				while (getline(StuID, line)) {

					linecounter++;
					if (line == StuUser) {
						//Records the location of the student and flips the UserFound variable to end the while loop.
						UserFound = true;
						LocationofStudent = linecounter;
					}
				}
				//If Student is not found, asks to enter it again.
				if (UserFound == false) {
					cout << "Student username not found. Please enter again: ";
					cin >> StuUser;

					linecounter = 0;
					//Resets the file so that it can be read again.
					StuID.clear();
					StuID.seekg(0);
				}
			}
			lines1 = (linecounter - 2);
			linecounter = 0;

			StuID.close();

			//Finds the user in StuGra.
			StuGra.open("StuGra.txt", ios::in);

			while (getline(StuGra, line)) {

				linecounter++;
				if (line == StuUser) {
					LocationofStudent1 = linecounter;
				}
			}

			lines2 = (linecounter - 12);
			linecounter = 0;

			StuGra.close();

			//Finds the user in StuDet.
			StuDet.open("StuDet.txt", ios::in);


			while (getline(StuDet, line)) {

				linecounter++;
				if (line == StuUser) {
					LocationofStudent2 = linecounter;
				}
			}

			lines3 = (linecounter - 8);
			linecounter = 0;

			StuDet.close();


			//Asks the user for confirmation of account deletion since this is permanent.
			cout << "\nConfirm Account Deletion for " << StuUser << ".\n[1] Delete Account\n[2] Back to User Management.\n\nSelection: ";
			cin >> choice;

			while (choice != 1 && choice != 2) {
				cin.clear(); //Clears cin.
				cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
				cout << "\nInvalid entry.\nPlease try again: ";
				cin >> choice;
			}

			//if choice is 1, then the account will be deleted.
			if (choice == 1) {

				StuID.open("StuID.txt");

				while (getline(StuID, line)) {

					linecounter++;

					if (linecounter != LocationofStudent && linecounter != (LocationofStudent + 1)) {
						AdmVec.push_back(line);
					}

				}

				AdmVec.resize(lines1);

				StuID.close();

				//Open the file to delete all contents so that the new contents can be written to it (sans the deleted student).
				StuID.open("StuID.txt", ios::out | ios::trunc);
				StuID.close();

				StuID.open("StuID.txt");

				for (int i = 0; i < AdmVec.size(); ++i) {
					if (firstline == false) {
						StuID << "\n";
					}
					StuID << AdmVec[i];
					firstline = false;
				}

				AdmVec.clear();

				StuID.close();

				firstline = true;
				linecounter = 0;

				//Erasing student from StuGra.
				StuGra.open("StuGra.txt");

				while (getline(StuGra, line)) {
					linecounter++;

					if (linecounter != (LocationofStudent1 - 1) && linecounter != LocationofStudent1 && linecounter != (LocationofStudent1 + 1) && linecounter != (LocationofStudent1 + 2) && linecounter != (LocationofStudent1 + 3) && linecounter != (LocationofStudent1 + 4) && linecounter != (LocationofStudent1 + 5) && linecounter != (LocationofStudent1 + 6) && linecounter != (LocationofStudent1 + 7) && linecounter != (LocationofStudent1 + 8) && linecounter != (LocationofStudent1 + 9) && linecounter != (LocationofStudent1 + 10)) {
						AdmVec.push_back(line);
					}
				}
				StuGra.close();

				StuGra.open("StuGra.txt", ios::out | ios::trunc);
				StuGra.close();
				StuGra.open("StuGra.txt");

				for (int i = 0; i < AdmVec.size(); ++i) {
					if (firstline == false) {
						StuGra << "\n";
					}
					StuGra << AdmVec[i];
					firstline = false;
				}

				StuGra.close();
				AdmVec.clear();
				firstline = true;
				linecounter = 0;

				//Erasing student from StuDet.
				StuDet.open("StuDet.txt");

				while (getline(StuDet, line)) {
					linecounter++;

					if (linecounter != (LocationofStudent2 - 1) && linecounter != LocationofStudent2 && linecounter != (LocationofStudent2 + 1) && linecounter != (LocationofStudent2 + 2) && linecounter != (LocationofStudent2 + 3) && linecounter != (LocationofStudent2 + 4) && linecounter != (LocationofStudent2 + 5) && linecounter != (LocationofStudent2 + 6)) {
						AdmVec.push_back(line);
					}

				}
				StuDet.close();

				StuDet.open("StuDet.txt", ios::out | ios::trunc);
				StuDet.close();
				StuDet.open("StuDet.txt");

				for (int i = 0; i < AdmVec.size(); ++i) {
					if (firstline == false) {
						StuDet << "\n";
					}
					StuDet << AdmVec[i];
					firstline = false;
				}

				StuDet.close();

				firstline = true;
				UserFound = false;
				linecounter = 0;
				LocationofStudent = 0;
				LocationofStudent1 = 0;
				LocationofStudent2 = 0;
				AdmVec.clear();


				//Makes a new sub-menu for returning to the user management or admin menu.
				cout << "\n[1] Return to User Management Menu\n[2] Back to Admin Menu\n\nSelection: ";
				cin >> SM;

				//Ensures the input is only one of the two valid options.
				while (SM != 1 && SM != 2) {
					cin.clear(); //Clears cin.
					cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
					cout << "\nInvalid entry.\nPlease try again: ";
					cin >> SM;
				}
				system("CLS");

				if (SM == 1) {
					break;
				}
				else if (SM == 2) {
					system("CLS");
					fAdmSM();
					break;
				}
			} //End of if statement.

		case 3:
			system("CLS");
			manageExisting();
			break;
		}
		break;

	case 3:
		cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
		cout << "---------    UA HIGH SCHOOL     ---------" << endl;
		cout << "        -- View Teacher Files --" << endl << endl;
		cout << "[1] View Teacher IDs and Passwords" << endl;
		cout << "[2] View Teacher Details" << endl;
		cout << "[3] Return to User Management" << endl;
		cout << "\nPlease make a selection: ";
		cin >> ManSM3;

		while (ManSM3 != 1 && ManSM3 != 2 && ManSM3 != 3) {
			cin.clear(); //Clears cin.
			cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
			cout << "\nInvalid entry.\nPlease try again: ";
			cin >> ManSM3;
		}

		system("CLS");

		switch (ManSM3) {

			//View Teacher IDs and Passwords.
		case 1:
			cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
			cout << "---------    UA HIGH SCHOOL     ---------" << endl;
			cout << "  -- View Teacher IDs and Passwords --" << endl << endl;

			TeaID.open("TeaID.txt", ios::out || ios::in);
			while (getline(TeaID, line))
			{
				linecounter++;

				//Every even line should print this.
				if (linecounter % 2 == 0) {
					cout << "Password: " << line << endl << endl;
				}

				//Every other line should print this.
				else {
					cout << "Username: " << line << endl;
				}

			}

			linecounter = 0;

			TeaID.close();

			//Makes a new sub-menu for returning to the user management or admin menu.
			cout << "\n[1] Return to User Management Menu\n[2] Back to Admin Menu\n\nSelection: ";
			cin >> SM;

			//Ensures the input is only one of the two valid options.
			while (SM != 1 && SM != 2) {
				cin.clear(); //Clears cin.
				cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
				cout << "\nInvalid entry.\nPlease try again: ";
				cin >> SM;
			}
			system("CLS");

			if (SM == 1) {
				manageExisting();
				break;
			}
			else if (SM == 2) {
				system("CLS");
				fAdmSM();
				break;
			}
			break;

			//View Teacher Details.
		case 2:
			cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
			cout << "---------    UA HIGH SCHOOL     ---------" << endl;
			cout << "     -- View Teacher Details --" << endl << endl;

			cout << "\n";
			StaDet.open("StaDet.txt", ios::in); // Open
			// While there are still lines in the txt file
			while (getline(StaDet, line))
			{
				//Teacher can view all the staff details in the file.
				linecounter++;
				if (line == "---*---") {
					LocationofTeacher = linecounter;
					teachercounter++; //Counts each staff section.
				}

				if (linecounter == (LocationofTeacher + 2)) {
					cout << "Name: " << line << endl;
				}

				if (linecounter == (LocationofTeacher + 3)) {
					cout << "Age: " << line << endl;
				}

				if (linecounter == (LocationofTeacher + 4)) {
					cout << "Qualifications: " << line << endl;
				}

				if (linecounter == (LocationofTeacher + 5)) {
					cout << "Profile Type: " << line << endl;
				}

				if (linecounter == (LocationofTeacher + 6)) {
					cout << "Teaching Class: " << line << endl << endl;
				}

			}
			// Close the file:
			StaDet.close();

			//Informs the user the total number of students enrolled in the school.
			cout << "No. of Staff Members: " << teachercounter << endl;

			//Reset the counter:
			teachercounter = 0;

			//Makes a new sub-menu for returning to the user management or admin menu.
			cout << "\n[1] Return to User Management Menu\n[2] Back to Admin Menu\n\nSelection: ";
			cin >> SM;

			//Ensures the input is only one of the two valid options.
			while (SM != 1 && SM != 2) {
				cin.clear(); //Clears cin.
				cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
				cout << "\nInvalid entry.\nPlease try again: ";
				cin >> SM;
			}
			system("CLS");

			if (SM == 1) {
				manageExisting();
				break;
			}
			else if (SM == 2) {
				system("CLS");
				fAdmSM();
				break;
			}
			break;
		case 3:
			system("CLS");
			manageExisting();
			break;
		}
		break;
	case 4:
		cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
		cout << "---------    UA HIGH SCHOOL     ---------" << endl;
		cout << "     -- Edit/Delete Teacher Files --" << endl << endl;
		cout << "[1] Edit Teacher Files" << endl;
		cout << "[2] Delete a Teacher Profile" << endl;
		cout << "[3] Return to User Management" << endl;
		cout << "\nPlease make a selection: ";
		cin >> ManSM4;

		while (ManSM4 != 1 && ManSM4 != 2 && ManSM4 != 3) {
			cin.clear(); //Clears cin.
			cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
			cout << "\nInvalid entry.\nPlease try again: ";
			cin >> ManSM4;
		}

		system("CLS");
		switch (ManSM4) {

			//Edit Teacher Files.
		case 1:
			cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
			cout << "---------    UA HIGH SCHOOL     ---------" << endl;
			cout << "        -- Edit Teacher Files --" << endl << endl;
			cout << "[1] Edit Teacher Password" << endl;
			cout << "[2] Edit Teacher Details" << endl;
			cout << "[3] Return to User Management" << endl;
			cout << "\nPlease make a selection: ";
			cin >> ManSM6;
			switch (ManSM6) {
				//Edit Teacher Password.
			case 1:
				system("CLS");
				cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
				cout << "---------    UA HIGH SCHOOL     ---------" << endl;
				cout << "       -- Edit Teacher Password --" << endl << endl;
				cout << "Please enter a Teacher Username: ";
				cin >> TeaUser;

				TeaID.open("TeaID.txt", ios::in);

				while (UserFound == false) {
					while (getline(TeaID, line)) {

						if (line == TeaUser) {
							UserFound = true;
						}
					}
					if (UserFound == false) {
						cout << "Teacher username not found. Please enter again: ";
						cin >> TeaUser;

						//Resets the file so that it can be read again.
						TeaID.clear();
						TeaID.seekg(0);
					}
				}

				linecounter = 0;

				TeaID.close();

				cout << "Please enter a new Teacher Password: ";
				cin >> pass;
				TeaID.open("TeaID.txt");

				LocationofTeacher = -50;

				while (getline(TeaID, line)) {
					linecounter++;
					if (linecounter != (LocationofTeacher + 1)) {
						AdmVec.push_back(line);
					}
					if (line == TeaUser) {
						LocationofTeacher = linecounter;
					}

					if (linecounter == (LocationofTeacher + 1)) {
						AdmVec.push_back(pass);
					}
				}
				TeaID.close();

				//Open the file to refresh it.
				TeaID.open("TeaID.txt", ios::out | ios::trunc);
				TeaID.close();
				TeaID.open("TeaID.txt");

				for (int i = 0; i < AdmVec.size(); ++i) {
					if (firstline == false) {
						TeaID << "\n";
					}
					TeaID << AdmVec[i];
					firstline = false;
				}

				firstline = true;
				UserFound = false;
				linecounter = 0;
				LocationofTeacher = 0;
				AdmVec.clear();

				TeaID.close();

				//Makes a new sub-menu for returning to the user management or admin menu.
				cout << "\n[1] Return to User Management Menu\n[2] Back to Admin Menu\n\nSelection: ";
				cin >> SM;

				//Ensures the input is only one of the two valid options.
				while (SM != 1 && SM != 2) {
					cin.clear(); //Clears cin.
					cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
					cout << "\nInvalid entry.\nPlease try again: ";
					cin >> SM;
				}
				system("CLS");

				if (SM == 1) {
					manageExisting();
					break;
				}
				else if (SM == 2) {
					system("CLS");
					fAdmSM();
					break;
				}
				break;
				//Edit Teacher Details
			case 2:
				system("CLS");
				cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
				cout << "---------    UA HIGH SCHOOL     ---------" << endl;
				cout << "        -- Edit Teacher Details --" << endl << endl;
				cout << "Please enter the teacher's username: ";
				cin >> TeaUser;

				StaDet.open("StaDet.txt", ios::in);

				while (UserFound == false) {
					while (getline(StaDet, line)) {

						linecounter++;
						if (line == TeaUser) {
							UserFound = true;
							LocationofTeacher = linecounter;
						}
					}
					if (UserFound == false) {
						cout << "Teacher username not found. Please enter again: ";
						cin >> TeaUser;

						//Resets the file so that it can be read again.
						StaDet.clear();
						StaDet.seekg(0);
						linecounter = 0;
					}

					if (LocationofTeacher == (linecounter + 4)) {
						if (line != "Administrator") {
							break;
						}
						else if (line == "Administrator") {
							AdmCheck = true;
							break;
						}
					}
				}

				StaDet.close();

				//Reset the line counter and LocationofTeacher to prevent conflicts.
				linecounter = 0;
				LocationofTeacher = -50; //Leaves buffer so that it doesn't trip up loops.

				//Asks the user for another sub-menu option.
				cout << "\n[1] Age\n[2] Qualifications\n[3] Account Type\n[4] Class\n[5] Exit\n";
				cout << "\nPlease select the subject grade you wish to change: ";
				cin >> ManSM7;

				while (ManSM7 < 1 && ManSM7 > 5) {
					cin.clear(); //Clears cin.
					cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
					cout << "\nInvalid entry.\nPlease try again: ";
					cin >> ManSM7;
				}
				system("CLS");

				switch (ManSM7) {
				case 1:
					//Change Age

					cout << "\nEnter the teacher's new age (must be above 18): ";
					cin >> detail;

					StaDet.open("StaDet.txt");

					while (getline(StaDet, line)) {
						linecounter++;
						if (linecounter != (LocationofTeacher + 2)) {
							AdmVec.push_back(line);
						}
						if (line == TeaUser) {
							LocationofTeacher = linecounter;
						}

						if (linecounter == (LocationofTeacher + 2)) {
							AdmVec.push_back(detail);
						}
					}
					StaDet.close();

					//Open the file to refresh it.
					StaDet.open("StaDet.txt", ios::out | ios::trunc);
					StaDet.close();
					StaDet.open("StaDet.txt");

					for (int i = 0; i < AdmVec.size(); ++i) {
						if (firstline == false) {
							StaDet << "\n";
						}
						StaDet << AdmVec[i];
						firstline = false;
					}

					firstline = true;
					UserFound = false;
					linecounter = 0;
					LocationofTeacher = 0;
					AdmVec.clear();

					StaDet.close();

					//Makes a new sub-menu for returning to the user management or admin menu.
					cout << "\n[1] Return to User Management Menu\n[2] Back to Admin Menu\n\nSelection: ";
					cin >> SM;

					//Ensures the input is only one of the two valid options.
					while (SM != 1 && SM != 2) {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "\nInvalid entry.\nPlease try again: ";
						cin >> SM;
					}
					system("CLS");

					if (SM == 1) {
						break;
					}
					else if (SM == 2) {
						system("CLS");
						fAdmSM();
						break;
					}
					break;
				case 2:
					//Change Qualifications

					cout << "\nEnter the teacher's first qualification (BSc, Bed, etc.): ";
					cin >> detail;

					cout << "\nAdd a secondary qualification? y/n? Selection: ";
					cin >> qualchoice;

					while (qualchoice != "y" && qualchoice != "Y" && qualchoice != "N" && qualchoice != "n") {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "\nInvalid entry.\nPlease try again: ";
						cin >> qualchoice;
					}

					if (qualchoice == "Y" || qualchoice == "y") {
						cout << "\nEnter the teacher's second qualification (BSc, Bed, etc.): ";
						cin >> detail2;
						detail = detail + " & " + detail2;
					}

					StaDet.open("StaDet.txt");

					while (getline(StaDet, line)) {
						linecounter++;
						if (linecounter != (LocationofTeacher + 3)) {
							AdmVec.push_back(line);
						}
						if (line == TeaUser) {
							LocationofTeacher = linecounter;
						}

						if (linecounter == (LocationofTeacher + 3)) {
							AdmVec.push_back(detail);
						}
					}
					StaDet.close();

					//Open the file to refresh it.
					StaDet.open("StaDet.txt", ios::out | ios::trunc);
					StaDet.close();
					StaDet.open("StaDet.txt");

					for (int i = 0; i < AdmVec.size(); ++i) {
						if (firstline == false) {
							StaDet << "\n";
						}
						StaDet << AdmVec[i];
						firstline = false;
					}

					firstline = true;
					UserFound = false;
					linecounter = 0;
					LocationofTeacher = 0;
					AdmVec.clear();

					StaDet.close();

					//Makes a new sub-menu for returning to the user management or admin menu.
					cout << "\n[1] Return to User Management Menu\n[2] Back to Admin Menu\n\nSelection: ";
					cin >> SM;

					//Ensures the input is only one of the two valid options.
					while (SM != 1 && SM != 2) {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "\nInvalid entry.\nPlease try again: ";
						cin >> SM;
					}
					system("CLS");

					if (SM == 1) {
						break;
					}
					else if (SM == 2) {
						system("CLS");
						fAdmSM();
						break;
					}
					break;
				case 3:
					//Change Profile Type

					if (AdmCheck = true) {
						cout << "You cannot change the profile type of an Administrator." << endl;
						AdmCheck = false;
					}

					else {
						cout << "Enter a valid Profile Type (Teacher, Dean, Principal): ";
						cin >> detail;

						while (detail != "Teacher" && detail != "Dean" && detail != "Principal") {
							cin.clear(); //Clears cin.
							cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
							cout << "\nInvalid entry.\nPlease try again: ";
							cin >> detail;
						}

						StaDet.open("StaDet.txt");

						while (getline(StaDet, line)) {
							linecounter++;
							if (linecounter != (LocationofTeacher + 4)) {
								AdmVec.push_back(line);
							}
							if (line == TeaUser) {
								LocationofTeacher = linecounter;
							}

							if (linecounter == (LocationofTeacher + 4)) {
								AdmVec.push_back(detail);
							}
						}
						StaDet.close();

						//Open the file to refresh it.
						StaDet.open("StaDet.txt", ios::out | ios::trunc);
						StaDet.close();
						StaDet.open("StaDet.txt");

						for (int i = 0; i < AdmVec.size(); ++i) {
							if (firstline == false) {
								StaDet << "\n";
							}
							StaDet << AdmVec[i];
							firstline = false;
						}

						firstline = true;
						UserFound = false;
						linecounter = 0;
						LocationofTeacher = 0;
						AdmVec.clear();

						StaDet.close();

					}

					//Makes a new sub-menu for returning to the user management or admin menu.
					cout << "\n[1] Return to User Management Menu\n[2] Back to Admin Menu\n\nSelection: ";
					cin >> SM;

					//Ensures the input is only one of the two valid options.
					while (SM != 1 && SM != 2) {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "\nInvalid entry.\nPlease try again: ";
						cin >> SM;
					}
					system("CLS");

					if (SM == 1) {
						break;
					}
					else if (SM == 2) {
						system("CLS");
						fAdmSM();
						break;
					}
					break;
				case 4:
					//Change Class
					cout << "Enter the class this teacher takes (for Social Studies and Physical Education, simply type Social or Physical): ";
					cin >> detail;

					while (detail != "English" && detail != "Maths" && detail != "Science" && detail != "Social" && detail != "Physical" && detail != "N/A") {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "\nInvalid entry.\nPlease try again: ";
						cin >> detail;
					}

					if (detail == "Social") {
						detail = detail + " Studies";
					}

					if (detail == "Physical") {
						detail = detail + " Education";
					}

					StaDet.open("StaDet.txt");

					while (getline(StaDet, line)) {
						linecounter++;
						if (linecounter != (LocationofTeacher + 5)) {
							AdmVec.push_back(line);
						}
						if (line == TeaUser) {
							LocationofTeacher = linecounter;
						}

						if (linecounter == (LocationofTeacher + 5)) {
							AdmVec.push_back(detail);
						}
					}
					StaDet.close();

					//Open the file to refresh it.
					StaDet.open("StaDet.txt", ios::out | ios::trunc);
					StaDet.close();
					StaDet.open("StaDet.txt");

					for (int i = 0; i < AdmVec.size(); ++i) {
						if (firstline == false) {
							StaDet << "\n";
						}
						StaDet << AdmVec[i];
						firstline = false;
					}

					firstline = true;
					UserFound = false;
					linecounter = 0;
					LocationofTeacher = 0;
					AdmVec.clear();

					StaDet.close();

					//Makes a new sub-menu for returning to the user management or admin menu.
					cout << "\n[1] Return to User Management Menu\n[2] Back to Admin Menu\n\nSelection: ";
					cin >> SM;

					//Ensures the input is only one of the two valid options.
					while (SM != 1 && SM != 2) {
						cin.clear(); //Clears cin.
						cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
						cout << "\nInvalid entry.\nPlease try again: ";
						cin >> SM;
					}
					system("CLS");

					if (SM == 1) {
						break;
					}
					else if (SM == 2) {
						system("CLS");
						fAdmSM();
						break;
					}
					break;
				case 5:
					//Exit
					break;
				}
			case 3:
				system("CLS");
				manageExisting();
				break;
			}
			break;
			//Delete a Teacher Profile from StaDet and TeaID.
		case 2:
			cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
			cout << "---------    UA HIGH SCHOOL     ---------" << endl;
			cout << "      -- Delete Teacher Profile --" << endl << endl;
			cout << "Please enter a Teacher Username to Delete: ";
			cin >> TeaUser;

			TeaID.open("TeaID.txt", ios::in);
			//Finds the User in TeaID.
			while (UserFound == false) {
				while (getline(TeaID, line)) {

					linecounter++;
					if (line == TeaUser) {
						UserFound = true;
						LocationofTeacher = linecounter;
					}
				}
				if (UserFound == false) {
					cout << "Teacher username not found. Please enter again: ";
					cin >> TeaUser;

					linecounter = 0;
					//Resets the file so that it can be read again.
					TeaID.clear();
					TeaID.seekg(0);
				}
			}
			lines1 = (linecounter - 2);
			linecounter = 0;

			TeaID.close();

			//Finds the user in StaDet.
			StaDet.open("StaDet.txt", ios::in);

			while (getline(StaDet, line)) {

				linecounter++;
				if (line == TeaUser) {
					LocationofTeacher1 = linecounter;
				}
			}

			lines2 = (linecounter - 7);
			linecounter = 0;

			StaDet.close();

			//Reset the line counter and LocationofTeacher to prevent conflicts.

			cout << "\nConfirm Account Deletion for " << TeaUser << ".\n[1] Delete Account\n[2] Back to User Management.\n\nSelection: ";
			cin >> choice;

			while (choice != 1 && choice != 2) {
				cin.clear(); //Clears cin.
				cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
				cout << "\nInvalid entry.\nPlease try again: ";
				cin >> choice;
			}

			if (choice == 1) {

				TeaID.open("TeaID.txt");

				while (getline(TeaID, line)) {

					linecounter++;

					if (linecounter != LocationofTeacher && linecounter != (LocationofTeacher + 1)) {
						AdmVec.push_back(line);
					}
				}

				TeaID.close();

				//Open the file to delete all contents so that the new contents can be written to it (sans the deleted student).
				TeaID.open("TeaID.txt", ios::out | ios::trunc);
				TeaID.close();

				TeaID.open("TeaID.txt");

				for (int i = 0; i < AdmVec.size(); ++i) {
					if (firstline == false) {
						TeaID << "\n";
					}
					TeaID << AdmVec[i];
					firstline = false;
				}

				AdmVec.clear();

				TeaID.close();

				firstline = true;
				linecounter = 0;

				//Erasing Teacher from StaDet.
				StaDet.open("StaDet.txt");

				while (getline(StaDet, line)) {
					linecounter++;

					if (linecounter != (LocationofTeacher1 - 1) && linecounter != LocationofTeacher1 && linecounter != (LocationofTeacher1 + 1) && linecounter != (LocationofTeacher1 + 2) && linecounter != (LocationofTeacher1 + 3) && linecounter != (LocationofTeacher1 + 4) && linecounter != (LocationofTeacher1 + 5)) {
						AdmVec.push_back(line);
					}

				}
				StaDet.close();

				StaDet.open("StaDet.txt", ios::out | ios::trunc);
				StaDet.close();
				StaDet.open("StaDet.txt");

				for (int i = 0; i < AdmVec.size(); ++i) {
					if (firstline == false) {
						StaDet << "\n";
					}
					StaDet << AdmVec[i];
					firstline = false;
				}

				StaDet.close();

				firstline = true;
				UserFound = false;
				linecounter = 0;
				LocationofTeacher = 0;
				LocationofTeacher1 = 0;
				AdmVec.clear();


				//Makes a new sub-menu for returning to the user management or admin menu.
				cout << "\n[1] Return to User Management Menu\n[2] Back to Admin Menu\n\nSelection: ";
				cin >> SM;

				//Ensures the input is only one of the two valid options.
				while (SM != 1 && SM != 2) {
					cin.clear(); //Clears cin.
					cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
					cout << "\nInvalid entry.\nPlease try again: ";
					cin >> SM;
				}
				system("CLS");

				if (SM == 1) {
					system("CLS");
					manageExisting();
					break;
				}
				else if (SM == 2) {
					system("CLS");
					fAdmSM();
					break;
				}
				break;
			}
			else if (choice == 2) {
				system("CLS");
				fAdmSM();
				break;
			}
			break;
		case 3:
			system("CLS");
			manageExisting();
			break;
		}
		break;
	case 5:
		ManMenu = false;
		system("CLS");
		fAdmSM();
		break;
	}
}
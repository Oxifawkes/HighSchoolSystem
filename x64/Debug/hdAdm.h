#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "hdBudget.h"
#include "hdprofileManage.h"

using namespace std;
//Intializing functions
int main();
void fAdmSM();
void addFile();
void viewB();
void changeB();

//Admin Sub-Menu to access or change student-based files.
void fAdmSM() {

	int AdmSM;

	//Admin menu display, allows the user to choose what they want to do
	cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
	cout << "---------    UA HIGH SCHOOL     ---------" << endl;
	cout << "\n         ----- Admin Menu -----" << endl << endl;
	cout << "You are signed in as " << userName << "." << endl;
	cout << "\nWelcome to the Administrator Menu." << endl << endl;
	cout << "[1] Manage Existing Users" << endl;
	cout << "[2] Add New Users" << endl;
	cout << "[3] Sign out" << endl;
	cout << "\nPlease make a selection: ";

	cin >> AdmSM; //Takes the user input for the menu

	while (AdmSM != 1 && AdmSM != 2 && AdmSM != 3) {
		cin.clear(); //Clears cin.
		cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
		cout << "Invalid entry.\nPlease try again: ";
		cin >> AdmSM;
	}

	while (Admlogin == true) {

		switch (AdmSM) {

		case 1:
			//Change/Delete student/teacher files.
			system("CLS");
			manageExisting();
			break;
		case 2:
			//Add New student/teacher users.
			system("CLS");
			addFile();
			break;
		case 3:
			//Sign Out.
			CredFail = true;
			Admlogin = false;
			system("CLS");
			break;
		default:
			cout << "Invalid input";
			break;
		}
		CredFail = true;
		Admlogin = false;
		break;
	}
}

//Lets the admin add a new person to the system
void addFile()
{
	int choice;
	cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
	cout << "---------- UA HIGH SCHOOL ---------" << endl;
	cout << "\n ----- Add Users -----" << endl << endl;
	cout << "[1] Add a Student Profile" << endl;
	cout << "[2] Add a Teacher Profile" << endl;
	cout << "[3] Return to Previous Menu" << endl;
	cout << "\nPlease make a selection: ";
	
	cin >> choice;

	while (choice != 1 && choice != 2 && choice != 3) {
		cin.clear(); //Clears cin.
		cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
		cout << "\nInvalid entry.\nPlease try again: ";
		cin >> choice;
	}

	switch (choice)
	{
	case 1:
		//Goes to Add New Student.
		system("CLS");
		addNewStu();
		break;
	case 2:
		//Goes to Add New Student.
		system("CLS");
		addNewTea();
		break;
	case 3:
		//Goes to Add New Student.
		system("CLS");
		fAdmSM();
		break;
	default:
		cout << "Invalid input";
		break;
	}
}
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include "loginLoop.h"
#include "hdStu.h"
#include "hdTea.h"
#include "hdAdm.h"
#include "hdprofileManage.h"


using namespace std;

//Declaring Functions and intializing ones pulled in from other header files
void menu();
void login();
void fTeaSM();
void fAdmSM();



//Main function
int main()
{
	while (CredFail == true) {
		menu();
		//Takes you to the student menu
		if (Stulogin == true) {
			fStuSM();
		}
		//Takes you to the teacher menu
		else if (Tealogin == true) {
			fTeaSM();
		}
		//Takes you to the admin menu
		else if (Admlogin == true) {
			fAdmSM();
		}
		//Terminates the program
		else if (SISend == true) {
			system("CLS");
			cout << "\n    _-_-_-_-_-_-_-_            _-_-_-_" << endl;
			cout << "   [-_-_-_-_-_-_-_-]          |       |" << endl;
			cout << "    |             |          [-_-_-_-_-]" << endl;
			cout << "    [  0   0   0  ]           | o   o |" << endl;
			cout << "     |           |             |     |" << endl;
			cout << "      |         |-___-___-___-_|     |" << endl;
			cout << "      [    0    ]   UA High    [  o  ]" << endl;
			cout << "      [ _______ ]  o   o   o   [     ]" << endl;
			cout << "      [ |     | ]              [     ]" << endl;
			cout << "      [ |     | ]              [     ]" << endl;
			cout << "  _-_-[_|_____|_]--------------[_____]-_-_" << endl;
			cout << " ( (_____________--------------_________) )" << endl << endl;
			cout << "\n[Thank you for using the School Information System for U.A. High School]\n";
			return 0;
		}
	}

}

//Defining the functions declared above
void menu()
{
	//This function displays the menu and allows the user to make a choice 
	int choice;
	cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
	cout << "---------    UA HIGH SCHOOL     ---------" << endl << endl;
	cout << "    _-_-_-_-_-_-_-_            _-_-_-_" << endl;
	cout << "   [-_-_-_-_-_-_-_-]          |       |" << endl;
	cout << "    |             |          [-_-_-_-_-]" << endl;
	cout << "    [  0   0   0  ]           | o   o |" << endl;
	cout << "     |           |             |     |" << endl;
	cout << "      |         |-___-___-___-_|     |" << endl;
	cout << "      [    0    ]   UA High    [  o  ]" << endl;
	cout << "      [ _______ ]  o   o   o   [     ]" << endl;
	cout << "      [ |     | ]              [     ]" << endl;
	cout << "      [ |     | ]              [     ]" << endl;
	cout << "  _-_-[_|_____|_]--------------[_____]-_-_" << endl;
	cout << " ( (_____________--------------_________) )" << endl << endl;
	cout << "\n          ----- Main Menu -----" << endl;
	cout << "\n[1] Login" << endl;
	cout << "[2] Exit" << endl << endl;
	cout << "Please make a selection: ";

	cin >> choice;
	while (choice != 1 && choice != 2) {
		cin.clear(); //Clears cin.
		cin.ignore(100, '\n'); //Erases the previous 100 characters if the user tried to enter characters.
		cout << "Invalid entry.\nPlease try again: ";
		cin >> choice;
	} //While Loop prevents invalid choices.

	switch (choice)
	{
	case 1:
		login();
		system("CLS");
		break;
	case 2:
		SISend = true;
		break;
	default:
		cout << "Invalid Input";
		break;
	}
}
//Function to allow the user to log in
void login()
{
	getLogin();
}
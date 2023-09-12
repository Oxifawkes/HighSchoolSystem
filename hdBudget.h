#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include "hdAdm.h"

using namespace std;

//Intializing functions needed
void fAdmSM();
int main();

//This header file manages the functions that access and change the school's budgets
void viewB()
{
	fstream budgetDet;
	string line;
	int locationofBudget = 0;
	char back;
	budgetDet.open("budgetDet.txt", ios::in);//Opens the file for viewing
	//Counts lines
	int linecounter = 0;
	
	while (getline(budgetDet, line))
	{
		linecounter++;
		if (line == "---*---")
		{
			locationofBudget = linecounter;
		}
		if (linecounter == (locationofBudget + 2)) {
			cout << "Staff total: " << line << endl;
		}
		if (linecounter == (locationofBudget + 4)) 
		{
			cout << "Projected: " << line << endl;
		}
		if (linecounter == (locationofBudget + 6))
		{
			cout << "Actual: " << line << endl;
		}
	}
	budgetDet.close(); //closes the file
	cout << "Reutrn to admin menu?[Y/N]" << endl;
	cout << "If you select no, you will be redirected to the main menu" << endl;
	cin >> back;
	if (back == 'Y' || back == 'y') 
	{
		system("CLS");
		fAdmSM();
		
	}
	else if (back == 'N' || back == 'n')
	{

		system("CLS");
		main();
	}

}

void changeB()
{
	//Need to find a specific budget item the admin wishes to change and enter a new value in place of the number under 'Actual' in the budget text file
}
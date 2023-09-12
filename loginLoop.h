#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "string"
#include <vector>

using namespace std;

//Creating global variables to be used across the various Header Files and main cpp file.
string line;
string userName;
string password;
bool Stulogin = false;
bool Tealogin = false;
bool Admlogin = false;
bool SISend = false; //Bool that activates when a user enters 4 on the main menu to terminate the loop.
bool CredFail = true; //Bool for ensuring the menu while loop continues when credentials fail.
fstream StuID;
fstream TeaID;
fstream AdmID;

void getLogin()
{
    int attempts = 1;
    int locationOfUserName = 0;
    int linecounter = 0;
    int dud;

    system("CLS");
	cout << "------- SCHOOL INFORMATION SYSTEM -------" << endl;
	cout << "---------    UA HIGH SCHOOL     ---------" << endl;
	cout << "\n          ----- User Login -----" << endl;
    cout << "\nWelcome to User Login.\nPlease enter your credentials." << endl;
    cout << "\nUsername: ";
    cin >> userName;

    StuID.open("StuID.txt", ios::in); // Open

    // While there are still lines in the txt file
    while (getline(StuID, line))
    {
        // Count the lines:
        linecounter++;

        // Look for the username:
        if (line == userName)
        {
            Stulogin = true;
            // Tell us what line the user name was found at:
            locationOfUserName = linecounter;
            break;
        }
    }

    // Reset the counter:
    linecounter = 0;

    // Close the file:
    StuID.close();

    TeaID.open("TeaID.txt", ios::in); // Open

    while (getline(TeaID, line))
    {
        // Count the lines:
        linecounter++;

        // Look for the username:
        if (line == userName)
        {
            Tealogin = true;
            // Tell us what line the user name was found at:
            locationOfUserName = linecounter;
            break;
        }
    }

    // Reset the counter:
    linecounter = 0;

    // Close the file:
    TeaID.close();

    AdmID.open("AdmID.txt", ios::in); // Open

    while (getline(AdmID, line))
    {
        // Count the lines:
        linecounter++;

        // Look for the username:
        if (line == userName)
        {
            Admlogin = true;
            // Tell us what line the user name was found at:
            locationOfUserName = linecounter;
            break;
        }
    }

    // Reset the counter:
    linecounter = 0;

    // Close the file:
    AdmID.close();

    // IF THE USERNAME IS FOUND IN THIS FILE:
    if (Stulogin == true) {
        cout << "Password: ";
        //now user enters password to confirm username
        cin >> password;

        StuID.open("StuID.txt", ios::in); // Open again for password

        // While there are still lines in the txt file
        while (getline(StuID, line))
        {
            // Count the lines:
            linecounter++;

            // Look for the password, which is one line below the username:
            if (linecounter == (locationOfUserName + 1)) //This will be useful for data management.
            {
                while (line != password)
                {
                    // Then the password is incorrect
                    cout << "Incorrect password, please try again: ";
                    cin >> password;

                    if (attempts >= 2 && line != password) {
                        cout << "Your three attempts have been unsuccessful.\n\n";
                        cout << "Type a number to continue: ";
                        //Asks for input merely so that system("CLS") does not wipe away the message.
                        cin >> dud;
                        cout << "\nReturning to Menu.";
                        //Resets the login and attempts.
                        Stulogin = false;
                        attempts = 1;
                        break;
                    }
                    attempts++;
                }

                if (line == password) {
                    cout << "Login successful. Welcome back " << userName;
                    CredFail = false;
                }
            }
        }

        // close the file
        StuID.close();
    }

    else if (Tealogin == true) {
        cout << "Password: ";
        //now user enters password to confirm username
        cin >> password;

        TeaID.open("TeaID.txt", ios::in); // Open again for password

        // While there are still lines in the txt file
        while (getline(TeaID, line))
        {
            // Count the lines:
            linecounter++;

            // Look for the password, which is one line below the username:
            if (linecounter == (locationOfUserName + 1)) //This will be useful for data management.
            {
                while (line != password)
                {
                    // Then the password is incorrect
                    cout << "Incorrect password, please try again: ";
                    cin >> password;

                    if (attempts >= 2 && line != password) {
                        cout << "Your three attempts have been unsuccessful.\n\n";
                        cout << "Type a number to continue: ";
                        cin >> dud;
                        cout << "\nReturning to Menu.";
                        //Resets the login and attempts.
                        Tealogin = false;
                        attempts = 1;
                        break;
                    }
                    attempts++;
                }

                if (line == password) {
                    cout << "Login successful. Welcome back " << userName;
                    CredFail = false;
                }
            }
        }

        // close the file
        TeaID.close();
    }


    else if (Admlogin == true) {
        cout << "Password: ";
        //now user enters password to confirm username
        cin >> password;

        AdmID.open("AdmID.txt", ios::in); // Open again for password

        // While there are still lines in the txt file
        while (getline(AdmID, line))
        {
            // Count the lines:
            linecounter++;

            // Look for the password, which is one line below the username:
            if (linecounter == (locationOfUserName + 1)) //This will be useful for data management.
            {
                while (line != password)
                {
                    // Then the password is incorrect
                    cout << "Incorrect password, please try again: ";
                    cin >> password;

                    if (attempts >= 2 && line != password) {
                        cout << "Your three attempts have been unsuccessful.\n\n";
                        cout << "Type a number to continue: ";
                        cin >> dud;
                        cout << "\nReturning to Menu.";
                        //Resets the login and attempts.
                        Admlogin = false;
                        attempts = 1;
                        break;
                    }
                    attempts++;
                }

                if (line == password) {
                    cout << "Login successful. Welcome back " << userName;
                    CredFail = false;
                }
            }
        }

        // close the file
        AdmID.close();
    }
}
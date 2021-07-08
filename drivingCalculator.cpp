/*
Driving fuel economy calculator
Garrett Hurst
6/23/2021
This code will calculate both metric and us customary information about a user's driving fuel economey.
*/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>
#include <limits>

using namespace std;

void metricInput(string);
void coustomaryInput(string);

int main () {
    string firstName, lastName, fullName;
    char response, middleInitial;
    bool runProgram, acceptableInput;

    //asks the user if they would like to use the program
    cout << "Would you like to use the fuel economy calculator? [y/n]: ";
    cin >> response;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (response == 'y' || response == 'Y'){
        runProgram = true;
    }

    //main loop that runs the calculations as many times as the user desires
    while (runProgram){
        //gets user first name
        cout << setw(30) << left << "Enter your first name:";
        cin >> firstName;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //gets user middle initial
        cout << setw(30) << left << "Enter your middle initial:";
        cin.get(middleInitial);
        if(middleInitial == '\n'){
            middleInitial = '\0';
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //gets user last name
        cout << setw(30) << left << "Enter your last name:";
        cin >> lastName;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //combines full name
        fullName = firstName + " " + middleInitial + " " + lastName;

        //allows the user to choose if they would like to use either metric or customary input
        acceptableInput = false;
        while (!acceptableInput){
            //prompts if the user would like to calculate another driving fuel economy
            cout << "Would you like to enter data in metric or US customary [m/c]: ";
            cin >> response;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (response == 'M' || response == 'm'){
                metricInput(fullName);
                acceptableInput = true;
            }
            else if (response == 'C' || response == 'c'){
                coustomaryInput(fullName);
                acceptableInput = true;
            }
            else{
                cout << "Invalid response" << endl;
            }
        }

        //prompts if the user would like to calculate another driving fuel economy
        cout << "Would you like to use the fuel economy calculator again? [y/n]: ";
        cin >> response;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (response == 'y' || response == 'Y'){
            runProgram = true;
        }
        else{
            runProgram = false;
        }
    }

    return 0;
}


void coustomaryInput(string name){

    //declarations of statics
    const float mileToKiloConversion = 1.60934; //1 mile = 1.60934 kilometers
    const float galToLiterConversion = 3.78541; //1 us gal = 3.78541 liters

    //declaration of dynamic variables
    bool datatype;
    float milesDriven, kilometersDriven, gallonsUsed, litersUsed, mpg, kml;

        //prompts the user to enter miles driven and ensures correct datatype is entered
        cout << setw(30) << left << "Enter miles driven:" ;
        cin >> milesDriven;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        datatype = false;
        while(!datatype){
            if(!cin){
                cout << "Invalid input" << endl;
                cout << setw(30) << left << "Enter miles driven:" ;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> milesDriven;
            }
            else{
                datatype = true;
            }
        }
        //prompts the user to enter the gallons used and again ensures the correct datatype is entered
        cout << setw(30) << left << "Enter gallons of gas used:" ;
        cin >> gallonsUsed;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        datatype = false;
        while(!datatype){
            if(!cin){
                cout << "Invalid input" << endl;
                cout << setw(30) << left << "Enter gallons of gas used:" ;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> gallonsUsed;
            }
            else{
                datatype = true;
            }
        }

        //calculations
        kilometersDriven = milesDriven * mileToKiloConversion;
        litersUsed = gallonsUsed * galToLiterConversion;
        kml = (float)kilometersDriven / (float)litersUsed;
        mpg = (float)milesDriven / (float)gallonsUsed;

        //gets the length of each string an adds space in preparation for formatting
        int s1 = 6 + strlen("Miles Driven:");
        int s2 = 5 + strlen("Kilometers Driven:");
        int s3 = 6 + strlen("Gallons Used:");
        int s4 = 11 + strlen("Liters Used:");
        int s5 = 5 + strlen("Economy (mpg):");
        int s6 = 8 + strlen("Economy (km/L):");


        //prints neat columns with output
        cout << "\nYour name: " + name << endl;
        printf("%*s %010.3f %*s %010.3f \n", s1, "Miles Driven:", milesDriven, s2, "Kilometers Driven:", kilometersDriven);
        printf("%*s %010.3f %*s %010.3f \n", s3, "Gallons Used:", gallonsUsed, s4, "Liters Used:", litersUsed);
        printf("%*s %010.3f %*s %010.3f \n", s5, "Economy (mpg):", mpg , s6, "Economy (km/L):", kml);
}


void metricInput(string name){

    //declarations of statics
    const float mileToKiloConversion = 1.60934; //1 mile = 1.60934 kilometers
    const float galToLiterConversion = 3.78541; //1 us gal = 3.78541 liters

    //declaration of dynamic variables
    bool datatype;
    float milesDriven, kilometersDriven, gallonsUsed, litersUsed, mpg, kml;

        //prompts the user to enter kilometers driven and ensures correct datatype is entered
        cout << setw(30) << left << "Enter kilometers driven:" ;
        cin >> kilometersDriven;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        datatype = false;
        while(!datatype){
            if(!cin){
                cout << "Invalid input" << endl;
                cout << setw(30) << left << "Enter kilometers driven:" ;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> kilometersDriven;
            }
            else{
                datatype = true;
            }
        }
        //prompts the user to enter the liters used and again ensures the correct datatype is entered
        cout << setw(30) << left << "Enter liters of gas used:" ;
        cin >> litersUsed;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        datatype = false;
        while(!datatype){
            if(!cin){
                cout << "Invalid input" << endl;
                cout << setw(30) << left << "Enter liters of gas used:" ;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> litersUsed;
            }
            else{
                datatype = true;
            }
        }

        //calculations
        milesDriven = kilometersDriven / mileToKiloConversion;
        gallonsUsed = litersUsed / galToLiterConversion;
        kml = kilometersDriven / litersUsed;
        mpg = milesDriven / gallonsUsed;

        //gets the length of each string an adds space in preparation for formatting
        int s1 = 6 + strlen("Miles Driven:");
        int s2 = 5 + strlen("Kilometers Driven:");
        int s3 = 6 + strlen("Gallons Used:");
        int s4 = 11 + strlen("Liters Used:");
        int s5 = 5 + strlen("Economy (mpg):");
        int s6 = 8 + strlen("Economy (km/L):");


        //prints neat columns with output
        cout << "\nYour name: " + name << endl;
        printf("%*s %010.3f %*s %010.3f \n", s1, "Miles Driven:", milesDriven, s2, "Kilometers Driven:", kilometersDriven);
        printf("%*s %010.3f %*s %010.3f \n", s3, "Gallons Used:", gallonsUsed, s4, "Liters Used:", litersUsed);
        printf("%*s %010.3f %*s %010.3f \n", s5, "Economy (mpg):", mpg , s6, "Economy (km/L):", kml);
}



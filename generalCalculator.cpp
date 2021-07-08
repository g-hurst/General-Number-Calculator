/*
general calculator
Garrett Hurst
7/1/2021
This code allows the user to select their operation and then enter two numbers to calculate
*/
#include <iostream>
#include <limits>
#include <array>
#include <stdio.h>

using namespace std;

double validateInput();
char getValidChoice(array<char, 10>);

int main() {
    //declarations
    int num1, num2;
    float calculation;
    bool run;
    array <char, 10> validChoices = {'a', 'A', 's', 'S', 'm', 'M', 'd', 'D', 'q', 'Q'};
    char choice;
    string outputMessage;

    //output prompts and inputs
    cout << "Welcome to the calculator-o-nator! \nEnter 'y' to run the program: ";
    cin.get(choice);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (choice == 'y' || choice == 'Y'){
        run = true;
    }

    //main loop that executes the majority of the program
    while(run){

        //calls the getValidChoice function and sets the return equal to the choice of the user
        choice = getValidChoice(validChoices);

        //quit statement
        if (choice == validChoices[8] || choice == validChoices[9]){
            cout << "Thank you for using the calculator-o-nator.";
            return 1;
        }
        //add statement
        else if (choice == validChoices[0] || choice == validChoices[1]){
            cout << "Enter first number to add: ";      //outputs prompt
            cin >> num1;                                //recieves fist number
            if(!cin)                                    //runs code if failstate occurs
                num1 = validateInput();                 //num1 is set equal to the value returned by the function
            cout << "Enter second number to add: ";     //outputs prompt
            cin >> num2;                                //recieves second number
            if(!cin)                                    //runs code if failstate occurs
                num2 = validateInput();                 //num2 is set equal to the value returned by the function
            calculation = num1 + num2;                  //performs calculation
            outputMessage = to_string(num1) + " + " + to_string(num2) + " = " + to_string(calculation);     //custom output message
        }
        //subtract statement
        else if (choice == validChoices[2] || choice == validChoices[3]){
            cout << "Enter number to subtract from : ";
            cin >> num1;
            if(!cin)
                num1 = validateInput();
            cout << "Enter number to subtract: ";
            cin >> num2;
            if(!cin)
                num2 = validateInput();
            calculation = num1 - num2;
            outputMessage = to_string(num1) + " - " + to_string(num2) + " = " + to_string(calculation);
        }
        //multiply statement
        else if (choice == validChoices[4] || choice == validChoices[5]){
            cout << "Enter first number to multiply: ";
            cin >> num1;
            if(!cin)
                num1 = validateInput();
            cout << "Enter second number to multiply: ";
            cin >> num2;
            if(!cin)
                num2 = validateInput();
            calculation = num1 * num2;
            outputMessage = to_string(num1) + " x " + to_string(num2) + " = " + to_string(calculation);
        }
        //divide statement
        else if (choice == validChoices[6] || choice == validChoices[7]){
            cout << "Enter the dividend: ";
            cin >> num1;
            if(!cin)
                num1 = validateInput();
            cout << "Enter the divisor: ";
            cin >> num2;
            if(!cin)
                num2 = validateInput();
            calculation = (float)num1 / (float)num2;     //converts data to strings in order to maintain precision when performing calculations.
            outputMessage = to_string(num1) + " / " + to_string(num2) + " = " + to_string(calculation);
        }

        //Displays the selected message
        cout << outputMessage << endl;
    }

    return 0;
}

//this function ensures that a double input is valid. (must be set equal to a double to work)
double validateInput(){
    bool validData;
    double tryAgainInput;

    //loop that repeats if invalid data is entered
    while(!validData){
        if (!cin){
            cout << "Invalid input " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Please enter a number: ";
            cin >> tryAgainInput;
        }
        else{
            validData = true;
        }
    }

    return tryAgainInput;
}

//this function gets a valid choice from the user and returns the char
char getValidChoice(array <char, 10> validChoices){
    bool validChoice = false;
    char choice;

    cout << "Do you want to (a)dd, (s)ubtract, (m)ultiply, (d)ivide, or (q)uit: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //sets the valid choice bool to true if the array of valid choices contains the user's choice
        for (char option : validChoices){
            if (option == choice){
                validChoice = true;
                break;
            }
        }

    //loop that ensures that the user selects a valid choice
    while (!validChoice){
            cout << "Invalid Choice" << endl;
            cout << "Do you want to (a)dd, (s)ubtract, (m)ultiply, (d)ivide, or (q)uit: ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            for (char option : validChoices){
                if (option == choice){
                    validChoice = true;
                    break;
                }
            }

        }
    return choice;
}

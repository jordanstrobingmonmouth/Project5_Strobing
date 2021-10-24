/*
 * This project was created by Jordan Strobing
 * The program creates a menu for the user to either input weather data, get the results printed, or exit
 * This program takes in input and stores it in variables
 * This program will not output data until it has the necessary inputs
 * The difference between this program and the last one is that we use functions for the 3 (and invalid) inputs
 * The menu that is created will loop until the user tells the program to stop
 */

#include <iostream>
#include <string>
using namespace std;

void input(double& temp, int& speed, string& direction, double tempArr[], int speedArr[], string directionArr[], int& counter){
    counter++;
    cout << "What is the current temperature? " << endl;
    cin >> temp;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input, type in a valid temperature: ";
        cin >> temp;
    }

    cout << "What is the wind speed? " << endl;
    cin >> speed;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input, type in a valid speed: ";
        cin >> speed;
    }

    cin.ignore(1000, '\n');
    cout << "What is the wind direction? " << endl;
    getline(cin, direction);

    if (counter > 5) {
        for (int i = 0; i < 4; i++) {
            tempArr[i] = tempArr[i + 1];
            speedArr[i] = speedArr[i + 1];
            directionArr[i] = directionArr[i + 1];
        }

        tempArr[4] = temp;
        speedArr[4] = speed;
        directionArr[4] = direction;

    }
    else if (counter <= 5) {
        tempArr[counter-1] = temp;
        speedArr[counter-1] = speed;
        directionArr[counter-1] = direction;
    }
}

void printRecent(const string name, double temp, int speed, string direction) {
    cout << "The " << name << " Weather Station" << endl;
    cout << "Temperature: " << temp << endl;
    cout << "Wind speed: " << speed << "\tDirection: " << direction << endl;
}

void printAll(const string name, double tempArr[], int speedArr[], string directionArr[], int counter) {
    if (counter > 5) {

        for (int i = 4; i >= 0; i--) {
            cout << "The " << name << " Weather Station" << endl;
            cout << "Temperature: " << tempArr[i] << endl;
            cout << "Wind speed: " << speedArr[i] << "\tDirection: " << directionArr[i] << "\n" << endl;
        }
    }
    else if (counter <= 5) {

        for (int i = counter - 1; i >= 0; i--) {
            cout << "The " << name << " Weather Station" << endl;
            cout << "Temperature: " << tempArr[i] << endl;
            cout << "Wind speed: " << speedArr[i] << "\tDirection: " << directionArr[i] << "\n" << endl;
        }
    }
}

void exit(bool &inMenu) {
    inMenu = false;
}

void invalid() {
    cout << "Invalid input, try again." << endl;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }
}

void display(string name, double temp, int speed, string direction, double tempArr[], int speedArr[], string directionArr[], int counter) {
    bool canPrint = false;

    bool inMenu = true;
    while (inMenu) {
        cout << "\nChoose which option you'd like (1, 2, or 3):" << endl;
        cout << "OPTION 1: Input" << endl;
        cout << "OPTION 2: Print" << endl;
        cout << "OPTION 3: Exit" << endl;

        int menuInput;
        cin >> menuInput;
        if (menuInput == 1) {
            input(temp, speed, direction, tempArr, speedArr, directionArr, counter);
            canPrint = true;
        }
        else if (menuInput == 2) {
            if (!canPrint) {
                cout << "No data to print." << endl;
                continue;
            }
            cout << "Choose which option you'd like to print:" << endl;
            cout << "OPTION 1: Print most recent data" << endl;
            cout << "OPTION 2: Print up to the 5 most recent inputs" << endl;
            cin >> menuInput;
            if (menuInput == 1) {
                printRecent(name, temp, speed, direction);
            }
            else if (menuInput == 2) {
                printAll(name, tempArr, speedArr, directionArr, counter);
            } else {
                invalid();
            }
        } else if (menuInput == 3) {
            exit(inMenu);
        }
        else {
            invalid();
        }
    }
}

    int main() {
        string name = "";
        double temp = 0;
        int speed = 0;
        string direction = "";
        int counter = 0;

        double tempArr[5];
        int speedArr[5];
        string directionArr[5];


        cout << "What is the name of the weather station? ";
        getline(cin, name);

        display(name, temp, speed, direction, tempArr, speedArr, directionArr, counter);
        return 0;
    }

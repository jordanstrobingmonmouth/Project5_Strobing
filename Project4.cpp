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
#include <iomanip>
using namespace std;

void input(const string name, double& temp, int& speed, string& direction, string outputs[], int& counter){
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
            outputs[i] = outputs[i + 1];
        }
        outputs[4] = "The " + name + " Weather Station\n" +
                     "Temperature: " + to_string(temp) + "\n" +
                     "Wind speed: " + to_string(speed) + "\tDirection: " + direction + "\n";
    }
    else if (counter <= 5) {
        outputs[counter - 1] = "The " + name + " Weather Station\n" +
                               "Temperature: " + to_string(temp) + "\n" +
                               "Wind speed: " + to_string(speed) + "\tDirection: " + direction + "\n";
    }
}

void printRecent(const string name, double temp, int speed, string direction) {
    cout << "The " << name << " Weather Station" << endl;
    cout << "Temperature: " << temp << endl;
    cout << "Wind speed: " << speed << "\tDirection: " << direction << endl;
}

void printAll(string outputs[], int counter) {
    if (counter > 5) {

        for (int i = 4; i >= 0; i--) {
            cout << fixed << setprecision(1) << outputs[i] << endl;
        }
    }
    else if (counter <= 5) {

        for (int i = counter - 1; i >= 0; i--) {
            cout << fixed << setprecision(1) << outputs[i]  << endl;
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

void display(string name, double temp, int speed, string direction, string outputs[], int counter) {
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
            input(name, temp, speed, direction, outputs, counter);
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
                printAll(outputs, counter);
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
        string name;
        double temp;
        int speed;
        string direction;
        int counter = 0;

        string outputs[5];


        cout << "What is the name of the weather station? ";
        getline(cin, name);

        display(name, temp, speed, direction, outputs, counter);
        return 0;
    }

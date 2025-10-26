//Comsc-210|Ethan Aylard|Lab-23
//IDE Used: Visual Studio Code
//Program Description: This program is meant to keep track of goats by using a menu that allows the user to add, delete, or view all the goats.


#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();




    return 0;
}

//main_menu(): This will display and loop a menu until the user inputs a valid choice.
//requires: none.
//returns: an int variable of the user's choice.


int main_menu (){
    int choice;
    bool valid = false;

    //Display the menu with a while loop.
    while (!valid){
        cout << "\n*** GOAT MANAGER 3001 ***\n";
        cout << "[1] Add a goat" << 
        endl << "[2] Delete a goat" << 
        endl << "[3] List goats" <<
        endl << "[4] Quit" <<
        endl << "Choice --> ";

        cin >> choice;
        if (cin.fail)


    }


    return choice;
}

//Comsc-210|Ethan Aylard|Lab-24
//IDE Used: Visual Studio Code
//Program Description: This program is meant to keep track of goats by using a menu that allows the user to add, delete, or view all the goats.


#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

//Function Prototypes:
int select_goat(set<Goat> trip);
void delete_goat(set<Goat> &trip);
void add_goat(set<Goat> &trip, string [], string []);
void display_trip(set<Goat> trip);
int main_menu();



int main() {
    //making the program truly random:
    srand(time(0));
    //declaring a bool variable and the set of the goats:
    bool again = true;
    set<Goat> goats;

    //read & populate arrays for names and colors
    //Filling array names[] with all the names in names.txt
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();

    //Filling array colors[] with all the names in colors.txt
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    //The main brains of the program: depending on the choice of the user each case could be activated:
    while(again){
        switch(main_menu()){
            //Add a goat to the end of the train of goats
            case 1:
                add_goat(goats, names, colors);
                break;
            
            //Delete a goat from the user's specified position:
            case 2:
                delete_goat(goats);
                break;

            //Display all the goats:
            case 3:
                display_trip(goats);
                break;

            //Exit out of the program:
            case 4:
                again = false;
                cout << "Quiting Program." << endl;
                break;

            //In case of error:
            default:
                cout << "Error! Input does not match the width of the menu.";
        }

    }

    //clearing the set:
    goats.clear();


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

        //Checking if the choice is valid:
        cin >> choice;
        if (!cin.fail()){ // Making sure the user's input is an integer.
            
            if (choice < 1 || choice > 4){ //Making sure the user's input is between 1 and 4;
                cout << "Invalid choice. Please try again." << endl;
            }
            else //If the input is valid:
            valid = true;
        }
        else{ //If the input is not an integer:
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice. Please try again." << endl;
        }

    }


    return choice;
}

//select_goat(): Get the position of a user chosen goat
//requires: a set of Goat elements
//returns:an int variable that holds the position of the chosen goat
int select_goat(set<Goat> trip){
    int choice;
    bool valid = false;

    //Displaying all the goats on the trip:
    display_trip(trip);
    while(!valid){
    cout << "Which goat would you choose?" << endl;

    //Checking if the choice is valid:
    cin >> choice;
        if (!cin.fail()){// Making sure the user's input is an integer.

            if(choice > trip.size() || choice < 1){ //Making sure the user's input is between 1 and the size of the list;
            cout << "Invalid choice. Please try again." << endl;
            }

            else //If the input is valid:
            valid = true;
        
        }

        else{ //If the input is not an integer:
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice. Please try again." << endl;
        }

    }


    return choice;
}

//delete_goat(): removes a goat of the user's choice
//requires: a set of Goat elements
//returns: none
void delete_goat(set<Goat> &trip){
auto it = trip.begin();
int pos = select_goat(trip) - 1;

advance(it, pos);
trip.erase(it);

}

//add_goat(): adds a goat to set of Goat elements
//requires: a set of Goat elements and two arrays of strings
//returns: none
void add_goat(set<Goat> &trip, string names [], string colors []){

    int age = rand() % MAX_AGE;
    string name = names[rand() % SZ_NAMES];
    string color = colors[rand() % SZ_COLORS];

    cout << "\nAdding goat: " << name << ", color: "
    << color << ", age: " << age << endl;
    
    trip.insert(Goat(name, age, color));

}

//display_trip(): displays the set of Goat elements
//requires: a list of Goat elements
//returns: none
void display_trip(set<Goat> trip){
    int i = 1;
    for(Goat g : trip){ //displaying each goat for as long as the length of the list
        cout << "[" << i << "] " << g.get_name() << " (" << g.get_age() << ", " << g.get_color() << ")" << endl;
        i++;
    }

}

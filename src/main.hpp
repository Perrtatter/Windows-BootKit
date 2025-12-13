// Import library/module
#include <algorithm>
#include <iostream>
#include "module/termcolor.hpp"
#include <list>
// Set namespaces
using namespace std;
using namespace termcolor;


// Set variable 
string banner = "--------------------------------------\n\n  ____             _   _  ___ _   \n |  _ \\ ___   ___ | |_| |/ (_) |_ \n | |_) / _ \\ / _ \\| __| ' /| | __|\n |  _ < (_) | (_) | |_| . \\| | |_ \n |_| \\_\\___/ \\___/ \\__|_|\\_\\_|\\__| v1.7\n                                  \nBy Perrtatter\nhttps://github.com/Perrtatter/Windows-RootKit\n--------------------------------------";


// Clear screen fonction
int clear_screen(){
    // Run command
    system("cls");

    // Return 0 , cause is a int loop
    return 0;
};

// Show banner fonction
int show_banner(){
    // Print banner
    cout << red << banner << reset << endl;

    // Return 0 , cause is a int loop
    return 0;
};


// Print help menu fonction
int show_help_menu(){
    // Print help menu
    cout << "[" << red << "1" << reset << "] Replace sethc.exe to cmd.exe ( " << red << "setup only" << reset << " )" << endl;
    cout << "[" << red << "2" << reset << "] List user ( " << red << "machine only" << reset << " )" << endl;
    cout << "[" << red << "3" << reset << "] Change password ( " << red << "machine only" << reset << " )" << endl;
    cout << "[" << red << "4" << reset << "] Dump SAM base ( " << red << "machine only" << reset << " )" << endl;
    cout << "[" << red << "5" << reset << "] Run payload (payload/[payload-name].exe)  ( " << red << "machine only" << reset << " )" << endl; 
    cout << "[" << red << "6" << reset << "] Download data ( on youre drive ) ( " << red << "machine / setup" << reset << " )" << endl; 

    cout << "--------------------------------------" << endl;
    cout << "[" << red << "0" << reset << "] Save change ( exit with 'shutdown -h' )" << endl;
    cout << "[" << red << "99" << reset << "] Clear Screen" << endl;

    cout << endl;

    // Return 0 , cause is a int loop
    return 0;
};


int is_verbose_mode(list<string> args){

    for (auto arg : args){
        cout << arg << endl ;
    }

    return 0;
};
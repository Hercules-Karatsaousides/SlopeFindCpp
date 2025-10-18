#include <iostream>
#ifdef _WIN32
#include <windows.h>
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
#endif
#include <limits>
#include <iomanip>

using namespace std;

#ifdef _WIN32
    static void enable_vt_mode() {
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut == INVALID_HANDLE_VALUE) {
            return;
        }
        DWORD dword = 0;
        if (!GetConsoleMode(hOut, &dword)) {
            return;
        }
        dword |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dword);
    }
#endif

int main() {

#ifdef _WIN32
    // Enable ANSI escape sequences support on Windows 10+ consoles
    enable_vt_mode();
#endif

    // Create / initialize project variables & banner
    double point_a_x = 0.0;
    double point_a_y = 0.0;
    double point_b_x = 0.0;
    double point_b_y = 0.0;
    double slope = 0.0;
    string banner = R"(
                                 _____ _                    ______ _           _
                                / ____| |                  |  ____(_)         | |  _     _
                               | (___ | | ___  _ __   ___  | |__   _ _ __   __| |_| |_ _| |_
                                \___ \| |/ _ \| '_ \ / _ \ |  __| | | '_ \ / _` |_   _|_   _|
                                ____) | | (_) | |_) |  __/ | |    | | | | | (_| | |_|   |_|
                               |_____/|_|\___/| .__/ \___| |_|    |_|_| |_|\__,_|
                                              | |
                                              |_|
                                                                              by Eraklis Karatsaousides
                                                                                                                  )";



    // Welcome message / Main menu instructions / Format of input
    cout<<"\033[1;32m"<<banner<<"\n\n\n\033[0m"<<endl;
    cout<<"\033[1;97mThis is a program that helps you find the slope which connects two points which are given by the user.\n"<<endl;
    cout<<"Example Input Format:\n"<<endl;
    cout<<"Enter point A:\n\n"<<"> "<<"4.5 -5.5   -Example\n\n\033[0m"<<endl;

    // Wait for the user to press enter to continue
    cout<<"\033[1;96mPress [Enter] to continue.\033[0m"<<endl;
    cin.get();
    // Clear console and Re-Print Banner
    system("cls");
    cout<<"\033[1;32m"<<banner<<"\n\n\n\033[0m"<<endl;

    // Take user input for point A while catching any User error inputs
    cout<<"Enter point A:"<<endl<<"> ";
    while(!(cin>>point_a_x>>point_a_y)) {
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"\033[1;31mInvalid input! Please enter two numbers (e.g., 4.5 -5.5)\033[0m"<<endl;
        cout<<"> ";
    }

    // Clear console and Re-Print Banner
    system("cls");
    cout<<"\033[1;32m"<<banner<<"\n\n\n\033[0m"<<endl;

    // Take user input for point B while catching any User error inputs
    cout<<"\033[1;97mEnter point B:\033[0m"<<endl<<"> ";
    while(!(cin>>point_b_x>>point_b_y)) {
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"\033[1;31mInvalid input! Please enter two numbers (e.g., 4.5 -5.5)\033[0m"<<endl;
        cout<<"> ";
    }

    // Check for division by zero
    if (point_b_x - point_a_x == 0) {
        system("cls");
        cout<<"\033[1;32m"<<banner<<"\n\n\n\n\n\n\n\n\033[0m"<<endl;
        cout<<"\033[1;31m>> ERROR: The slope is undefined (vertical line - division by zero) <<\033[0m\n\n"<<endl;
        cout<<"\033[1;96mPress [Enter] to exit\033[0m";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return 1;
    }

    // Calculate Slope
    slope = (point_b_y - point_a_y) / (point_b_x - point_a_x);

    // Clear console and Re-Print Banner
    system("cls");
    cout<<"\033[1;32m"<<banner<<"\n\n\n\n\n\n\n\n\033[0m"<<endl;

    // Print out Final Result (Slope)
    cout<<setw(65)<<" \033[1;4;95m >> THE SLOPE CONNECTING "<<"("<<point_a_x<<" ,"<<point_a_y<<") AND ("<<point_b_x<<" ,"<<point_b_y<<") IS: "<<slope<<" <<\n\n\n\n\033[0m"<<endl;

    // Wait until the user presses [Enter] to exit (return 0;)
    cout<<"\033[1;97mPress [Enter] to exit\033[0m";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    
    return 0;
}
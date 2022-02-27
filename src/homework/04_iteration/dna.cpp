#include "dna.h"
#include<iostream>

using std::cout; using std::cin; using std::string;

void menu_options()
{
    cout<<"\n\nWhat would you like to do?";
    cout<<"\n1. Find factorials";
    cout<<"\n2. Find greatest common divisor";
    cout<<"\n3. Exit";
}

void menu()
{
    int menu_selection = 0;
	do
    {
        menu_options();
        cout<<"\n\nEnter number from menu: ";
        cin>> menu_selection;
        if (menu_selection > 0 && menu_selection < 3) {
            handle_menu(menu_selection);
        }
        else if (menu_selection == 3){
            string confirm = "n";
            cout << "Are you sure you would like to exit? (y/n): ";
            cin >> confirm;
            if (confirm == "y") {
                cout << "Thank you! Have a nice day!";
            }
            else {
                menu_selection = 0;
            }
        }
        else {
            cout << "Selection error: please enter valid selection from menu.";
        }
    }
    while(menu_selection != 3);
}

int handle_menu(int menu_selection)
{
    switch(menu_selection)
    {
        case 1: {
            int num = 0;
            cout << "Enter a number: ";
            cin >> num;
            cout << num << " factorial is : " << factorial(num);
            break;
        }
        case 2: {
            int num1 = 0;
            int num2 = 0;
            cout<< "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
            cout << "\nThe GCD of " << num1 << " & " << num2 << " is: " << gcd(num1, num2);
            break;
        }
    }
    return(menu_selection);
}

int factorial(int num)
{
    int fact_accumulator = 1;
    while (num > 0) {
        fact_accumulator = fact_accumulator * num;
        num--;
    }
    return fact_accumulator;
}

int gcd(int num1, int num2)
{
    while (num1 != num2) {
        if (num1 == 0 || num2 == 0) {
            num1 = 0;
        }
        else if (num1 < num2){
            num1 = num1 + num2;
            num2 = num1 - num2;
            num1 = num1 - num2;
        }
        else if (num1 > num2) {
            num1 = num1 - num2;
        }
    }
    return num1;
}
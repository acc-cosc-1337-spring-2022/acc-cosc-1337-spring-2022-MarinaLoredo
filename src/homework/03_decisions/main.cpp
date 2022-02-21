#include<iostream>
#include<string>
using std::cout; using std::cin; using std::string;
//write include statements
#include "decisions.h"

int main() 
{
	int choose;
	cout << "Enter number from menu to use:\n1. If\n2.Switch\n";
	cin >> choose;

	if (choose == 1)
	{
		int grade;
		cout << "\nEnter numerical grade: ";
		cin >> grade;

		if(grade < 101 && grade > 0)
		{
			string letter_if = get_letter_grade_using_if(grade);
			cout << "Letter grade based on 'if' function: " << letter_if;
		}
		else
		{
			cout << "That grade is not valid.";
		}
	}

	else if (choose == 2)	
	{
		int grade;
		cout << "\nEnter numerical grade: ";
		cin >> grade;
		
		if(!(grade < 0 || grade > 100))
		{
			string letter_switch = get_letter_grade_using_switch(grade);
			cout << "\nLetter grade based on 'switch' function: " << letter_switch;
		}
		else
		{
			cout << "That grade is not valid.";
		}	
	}
	else
	{
		cout << "Menu choice invalid.";
	}
	
	return 0;
}
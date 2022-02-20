#include<iostream>
#include<string>
using std::cout; using std::cin; using std::string;
//write include statements
#include "decisions.h"

int main() 
{
	int grade;
	cout << "\nEnter numerical grade: ";
	cin >> grade;

	string letter_if = get_letter_grade_using_if(grade);

	cout << "\nLetter grade based on 'if' function: " << letter_if;
	
	string letter_switch = get_letter_grade_using_switch(grade);
	cout << "\nLetter grade based on 'switch' function: " << letter_switch;

	return 0;
}
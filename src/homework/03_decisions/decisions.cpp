#include "decisions.h"
#include<string>
//write include statement for decisions header

//Write code for function get_grade_points that accepts a string letter_grade and returns 
//the grade_points for as follows:
//given grade "A" returns 4
//given grade "B" returns 3
//given grade "C" returns 2
//given grade "D" returns 1
//given grade "F" returns 0
//another other value return -1
std::string get_letter_grade_using_if(int grade)
{
	if(grade > 90) 
	{
		return "A";
	}
	else if (grade > 80)
	{
		return "B";
	}
	else if (grade > 70)
	{
		return "C";
	}
	else if (grade > 60)
	{
		return "D";
	}
	else
	{
		return "F";
	}

}


std::string get_letter_grade_using_switch(int grade)
{
	switch(grade)
	{
		case 90 ... 100:
			return "A";
			break; 
		case 80 ... 89:
			return "B";
			break;
		case 70 ... 79:
			return "C";
			break;
		case 60 ... 69:
			return "D";
			break;
		default:
			return "F";
			break;
	}
}
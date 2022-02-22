#include "decisions.h"
#include<string>

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
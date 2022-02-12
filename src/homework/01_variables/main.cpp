//write include statements
#include "variables.h"
#include <iostream>
//write namespace using statement for cout
// Necessary in any program you need these processes
using std::cout;
using std::cin; 

int main()
{
	// Declare variable with datatype
	int num; 
	cout <<"Enter number would you like to multiply: ";
	// Store the entry from user in the declared variable
	cin >> num; 
	//Declare new varible with datatype
	// Use the variable in a call to the function from header file
	int result = multiply_numbers(num); 
	// Simple print statement using variable
	// '\n' moves to next line or else it all squishes
	cout << num << " x 5 = " << result << "\n";
	
	// New varaible time
	int num1 = 4;
	// Result has been declared, no need to give datatype again
	result = multiply_numbers(num1);
	cout << num1 << " x 5 = " << result << "\n";

	return 0;
}

//write include statements
#include "../src/homework/02_expressions/expressions.h"
#include <iostream>
#include <iomanip>
//write namespace using statement for cout
using std::cout;
using std::cin;
using std::fixed;
using std::setprecision;


/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int main()
{
	double meal;
	cout << "\nWhat was the cost of today's meal: ";
	cin >> meal;

	double tax = get_sales_tax(meal);
	
	cout << "\nMeal cost: \t$" << fixed << setprecision(2) <<  meal;
	
	cout << "\nSales Tax: \t$" << fixed << setprecision(2) << tax;

	double tip_percent;
	cout << "\nEnter percentage for tip: ";
	cin >> tip_percent;

	double tip_decimal = tip_percent / 100;

	double tip = get_tip_amount(meal, tip_decimal);
	cout << "\nTip: \t\t$" << tip;

	double total = meal + tax + tip;

	cout << "\nTotal cost: \t$" << fixed << setprecision(2) << total;
	
	cout << "\n\nThank you for dining today!\n";

	return 0;
}

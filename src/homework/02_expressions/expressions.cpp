#include "../src/homework/02_expressions/expressions.h"

//example
int add_numbers(int num1, int num2)
{
	return num1 + num2;
}

//write code for get_sales_tax function here

double get_sales_tax(double meal_amount)
{
	return meal_amount * TAX_RATE;
}

//write code for get_tip_amount function here

double get_tip_amount(double meal_amount, double tip_rate)
{
	return meal_amount * tip_rate;
}

#include <iostream>
#include <cmath>


double monthly_payment(double amount, int length, double rate) {
	double monthly_rate = rate / 12; 
	int total_payments = length * 12;
	double monthly_payment = amount * monthly_rate * ((pow(1 + monthly_rate, total_payments)) / (pow(1 + monthly_rate, total_payments) - 1));
	return monthly_payment;
}

int main() {

	double amount, length, rate;

	std::cout << "What is the loan amount? "; std::cin >> amount;
	std::cout << "What is the length of the loan, in years? "; std::cin >> length;
	std::cout << "What is the annual interest rate? "; std::cin >> rate;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	rate = rate / 100;
	double payment = monthly_payment(amount, length, rate);
	
	std::cout << "Your monthly payment is $" << payment << ".";
	
	//test inputs 450326.28 , 30 , 3.6
	//result should be 2047.39
	//monthly_payment = amount *(rate/12)*pow((1+rate/12),12*length)/(pow((1+rate/12),12*length)-1); Formula given by the instructions.

}

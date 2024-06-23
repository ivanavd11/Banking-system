#include "Cheque.h"
#include <iostream>

Cheque::Cheque(const MyString& new_code, double new_sum)
	  :unique_code(new_code), sum(new_sum){}

Cheque::Cheque(MyString&& new_code, double new_sum)
	  :unique_code(std::move(new_code)), sum(new_sum) {}

bool Cheque::isValidCode(const MyString& other) const
{
	return unique_code == other;
}

bool Cheque::isRedeemed() const
{
	return redeemed;
}

double Cheque::withdrawCash()
{
	double toReturn = sum;
	sum = 0;
	redeemed = true;
	return toReturn;
}

void Cheque::display() const {
	std::cout << "Cheque Code: " << unique_code
		<< "\nAmount: " << sum
		<< "\nRedeemed: " << (redeemed ? "Yes" : "No") << std::endl;
}
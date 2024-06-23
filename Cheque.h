#pragma once
#include "MyString.h"

class Cheque
{
public:
	Cheque() = default;
	Cheque(const MyString& new_code, double new_sum);
	Cheque(MyString&& new_code, double new_sum);

	bool isValidCode(const MyString& other) const;

	bool isRedeemed() const;
	double withdrawCash();

	void display() const;
private:
	MyString unique_code= "Unknown";
	double sum = 0.0;
	bool redeemed = false;
};

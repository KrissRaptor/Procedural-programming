

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int age1;
	int age2;
	int age3;

	int min;
	int max;

	cout << "Enter customer 1 age: ";
	cin >> age1;
	cout << "Enter customer 2 age: ";
	cin >> age2;
	cout << "Enter customer 3 age: ";
	cin >> age3;

	//Max
	if (age1 > age2 && age1 > age3)
	{
	  max = age1; //1
	}
	else if (age2 > age1 && age2 > age3)
	{
	  max = age2; //2
	}
	else if (age3 > age2 && age3 > age1)
	{
	  max = age3; //3
	}

	//Min
	if (age1 < age2 && age1 < age3)
	{
		min = age1; //1
	}
	else if (age2 < age1 && age2 < age3)
	{
		min = age2; //2
	}
	else if (age3 < age2 && age3 < age1)
	{
		min = age3; //3
	}

	cout << "Max age: " << max << endl;
	cout << "Min age: " << min << endl;
	cout << "AVG age: " << (age1 + age2 + age3) / 3 << endl;

	system("pause");

}


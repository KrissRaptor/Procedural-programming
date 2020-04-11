

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int a;
	int b;
	int number;
	    //1    *
		cout << "Enter nubmer for a : ";
		cin >> a;
		cout << "Enter nubmer for b : ";
		cin >> b;
		cout << "Enter multiplication for a*b : ";
		cin >> number;

		if (a*b != number)
		{
			cout << "nope" << endl;
			cout << "it will be : " << a * b << endl;
		}
		else if (a*b == number)
		{
			cout << "yes" << endl;
		}
		//2      /
		cout << "Enter nubmer for a : ";
		cin >> a;
		cout << "Enter nubmer for b : ";
		cin >> b;
		cout << "Enter division for a/b : ";
		cin >> number;

		if (a/b != number)
		{
			cout << "nope" << endl;
			cout << "it will be : " << a / b << endl;
		}
		else if (a/b == number)
		{
			cout << "yes" << endl;
		}
		//3      +
		cout << "Enter nubmer for a : ";
		cin >> a;
		cout << "Enter nubmer for b : ";
		cin >> b;
		cout << "Enter sum for a+b : ";
		cin >> number;

		if (a+b != number)
		{
			cout << "nope" << endl;
			cout << "it will be : " << a + b << endl;
		}
		else if (a+b == number)
		{
			cout << "yes" << endl;
		}
		//4         -
		cout << "Enter nubmer for a : ";
		cin >> a;
		cout << "Enter nubmer for b : ";
		cin >> b;
		cout << "Enter subtraction for a-b : ";
		cin >> number;

		if (a-b != number)
		{
			cout << "nope" << endl;
			cout << "it will be : " << a - b << endl;
		}
		else if (a-b == number)
		{
			cout << "yes" << endl;
		}

	system("pause");
}

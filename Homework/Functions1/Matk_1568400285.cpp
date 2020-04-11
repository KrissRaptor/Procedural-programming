#include <iostream>

using std::cout;
using cin::cout;

void Summ()
{
	int counter,summ = 0;
	cin >> counter;
	for (int i = 1; i < counter; i++)
	{
		summ += i;
	}
	cout << summ << std::endl;
}

void Fibonacchi()
{
	long int number1, number2, counter;
	number1 = 0;
	number2 = 1;
	//cin >> counter;
	cout << number1 << " ";
	while(true)
	{
	cin >> counter;
	if(counter <= 0)
	{
		cout << "ERROR! Enter the number greater than zero: ";
	}
	else 
	{
		while (counter != 0)
		{
			number1 += number2;
			number2 = number1 - number2;
			counter--;
			cout << number1 << " ";
		}
		break;
	}
	}
	
	cout << std::endl;
}

void Rhombus()
{
	int i, j, N = 9;
	int center = N / 2;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (i <= center)
			{
				if (j >= center - i && j <= center + i)
					cout << "*";
				else
					cout << " ";
			}
			else
			{
				if (j >= center + i - N + 1 && j <= center - i + N - 1)
					cout << "*";
				else
					cout << " ";
			}
		}
		cout << std::endl;
	}
}

int main()
{
	Summ();
	Fibonacchi();
	Rhombus();
	system("pause");
}
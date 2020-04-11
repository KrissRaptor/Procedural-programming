#include<iostream>
#include<ctime>


using std::cout;

void arithmetic(int mass[], const int size);
void fill_array(int mass[], const int size);
void positive_el(int mass[], const int size);
void negative_el(int mass[], const int size);
void uneven(int mass[], const int size);
void multiple_3_5_7(int mass[], const int size);


void arithmetic(int mass[] ,const int size )
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		counter += mass[i];
	}
	cout <<"arithmetic : " << counter / size << std::endl;
}

void fill_array(int mass[], const int size)
{
	for (int i = 0; i < size; i++)
	{
	      mass[i] =   rand() % 80 - 40 ;
		  cout << mass[i] << " ";
	}
}

void positive_el(int mass[], const int size)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (mass[i] >= 0)
		{
			counter++;
		}
	}
	cout << std::endl;
	cout << "positive_el : " << counter << std::endl;
}

void negative_el(int mass[], const int size)
{
	int counter2 = 0;
	for (int i = 0; i < size; i++)
	{
		if (mass[i] < 0)
		{
			counter2++;
		}
	}
	cout << "negative_el : " << counter2 << std::endl;
}

void uneven(int mass[], const int size)
{
	int counter2 = 0;
	for (int i = 0; i < size; i++)
	{
		
		if (mass[i] % 2 != 0)
		{
			counter2++;
		}
	}
	cout << "uneven_el : " << counter2 << std::endl;
}

void multiple_3_5_7(int mass[], const int size)
{
	int counter2 = 0;
	for (int i = 0; i < size; i++)
	{
		if (mass[i] % 3 == 0 || mass[i] % 5 == 0 || mass[i] % 7 == 0)
		{
			counter2 += mass[i];
		}
	}
	cout << "summ_multiple_el_3_5_7 : " << counter2 << std::endl;
}

void numbers_fibonachi()
{

	int number_0 = 0;
	int number_1 = 1;
	int next_number= 0;
	int counter = 0;

	/*for (int i = 0; i < 100; i++)
	{
		next_number += number_0 + number_1;
		cout << next_number << " ";
	}
*/
	for (int i = 0; i < 100; i++)
	{
		counter += i;
		/*for (int j = 0; j < 100; j++)
		{
			counter += i + j;

		}*/
		cout << counter << " ";
	}
	//cout << counter << " ";
}

int main()
{
	srand(time(NULL));
	const int size = 10;
	int mass[size];

	//fill_array(mass, size);
	//positive_el(mass, size);
	//negative_el(mass, size);
	//arithmetic(mass, size);
	//uneven(mass, size);
	//multiple_3_5_7(mass, size);
	numbers_fibonachi();
	system("pause");
}
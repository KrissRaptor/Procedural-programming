
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void _1(int **arr ,int rows ,int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = 1 + rand() % 100;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void _2(int** arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

//int ** _3(/*int** arr,*/ int rows, int cols)
//{
//	int** arr = new int* [rows];
//
//	for (int i = 0; i < rows; i++)
//	{
//		arr[i] = new int[cols];
//	}
//	return arr;
//}

void search_min(int** arr, int rows, int cols)
{
	int min = 200;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] <= min)
			{
				min = arr[i][j];
			}
		}
		
	}
	cout << "min " << min << endl;
}

void search_max(int** arr, int rows, int cols)
{
	int max = -200;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] >= max)
			{
				max = arr[i][j];
			}
		}
	}
	cout <<"max " << max << endl;
}


int main()
{
	setlocale(LC_ALL, "rus");

	int rows = 0, cols =0;
	
	cin >> rows;
	cin >> cols;

	int  **arr = new int *[rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	_1(arr, rows, cols);
	cout << endl;
	search_min(arr, rows, cols);
	search_max(arr, rows, cols);
	_2(arr, rows);

	system("pause");
	return 0;
}


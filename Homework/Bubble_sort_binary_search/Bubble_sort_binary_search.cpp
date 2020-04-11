#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int search_binary(int *arr, int left, int right, int key) //2 задание
{
	int midd = 0;
	while (true)
	{
		midd = (left + right) / 2;

		if (key < arr[midd])       // если искомое меньше значения в ячейке
		{
			right = midd - 1;      // смещаем правую границу поиска
		}
		else if (key > arr[midd])  // если искомое больше значения в ячейке
		{
			left = midd + 1;    // смещаем левую границу поиска
		}
		else                       // иначе (значения равны)
		{
			return midd;           // функция возвращает индекс ячейки
		}
		if (left > right)          // если границы сомкнулись 
		{
			return -1;
		}
	}

}

int main()
{
	//1 задание
	setlocale(LC_ALL, "Russian");

	//int n; // Кол-во элементов
	//cout << "Количество элементов: ";
	//cin >> n;

	///* Заполним массив значениями */
	//int *mass = new int[n];
	//for (int i = 0; i < n; ++i)
	//{
	//	 mass[i] = (-10) + rand() % 150;
	//}

	///* Выведем исходный массив */
	//cout << "Исходный массив: ";
	//for (int i = 0; i < n; ++i)
	//{
	//	cout << mass[i] << " ";
	//}
	//cout << endl;

	///* Отсортируем массив по убыванию */
	//for (int i = 1; i < n; ++i)
	//{
	//	for (int r = 0; r < n - i; r++)
	//	{
	//		if (mass[r] < mass[r + 1])
	//		{
	//			// Обмен местами
	//			int temp = mass[r];
	//			mass[r] = mass[r + 1];
	//			mass[r + 1] = temp;
	//		}
	//	}
	//}

	///* Выведем отсортированный массив */
	//cout << "Отсортированный массив: ";
	//for (int i = 0; i < n; ++i)
	//{
	//	cout << mass[i] << " ";
	//}
	//cout << endl;
	///////////////////////////////////////////////////////////////
	//2 задание
	int SIZE;
	int key = 0;
	int index = 0; // индекс ячейки с искомым значением

	cout << "Введите размер массива :";
	cin >> SIZE;

	int* array = new int[SIZE];

	for (int i = 0; i < SIZE; i++) // заполняем и показываем массив
	{
		array[i] = i + 1;
		cout << array[i] << " | ";
	}

	cout << "\n\nВведите любое число: ";
	cin >> key;

	index = search_binary(array, 0, SIZE, key);

	if (index >= 0)
	{
		cout << "Указанное число находится в ячейке с индексом: " << index << "\n\n";
	}
	else
	{
		cout << "В массиве нет такого числа!\n\n";
	}
	system("pause");
}
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int search_binary(int *arr, int left, int right, int key) //2 �������
{
	int midd = 0;
	while (true)
	{
		midd = (left + right) / 2;

		if (key < arr[midd])       // ���� ������� ������ �������� � ������
		{
			right = midd - 1;      // ������� ������ ������� ������
		}
		else if (key > arr[midd])  // ���� ������� ������ �������� � ������
		{
			left = midd + 1;    // ������� ����� ������� ������
		}
		else                       // ����� (�������� �����)
		{
			return midd;           // ������� ���������� ������ ������
		}
		if (left > right)          // ���� ������� ���������� 
		{
			return -1;
		}
	}

}

int main()
{
	//1 �������
	setlocale(LC_ALL, "Russian");

	//int n; // ���-�� ���������
	//cout << "���������� ���������: ";
	//cin >> n;

	///* �������� ������ ���������� */
	//int *mass = new int[n];
	//for (int i = 0; i < n; ++i)
	//{
	//	 mass[i] = (-10) + rand() % 150;
	//}

	///* ������� �������� ������ */
	//cout << "�������� ������: ";
	//for (int i = 0; i < n; ++i)
	//{
	//	cout << mass[i] << " ";
	//}
	//cout << endl;

	///* ����������� ������ �� �������� */
	//for (int i = 1; i < n; ++i)
	//{
	//	for (int r = 0; r < n - i; r++)
	//	{
	//		if (mass[r] < mass[r + 1])
	//		{
	//			// ����� �������
	//			int temp = mass[r];
	//			mass[r] = mass[r + 1];
	//			mass[r + 1] = temp;
	//		}
	//	}
	//}

	///* ������� ��������������� ������ */
	//cout << "��������������� ������: ";
	//for (int i = 0; i < n; ++i)
	//{
	//	cout << mass[i] << " ";
	//}
	//cout << endl;
	///////////////////////////////////////////////////////////////
	//2 �������
	int SIZE;
	int key = 0;
	int index = 0; // ������ ������ � ������� ���������

	cout << "������� ������ ������� :";
	cin >> SIZE;

	int* array = new int[SIZE];

	for (int i = 0; i < SIZE; i++) // ��������� � ���������� ������
	{
		array[i] = i + 1;
		cout << array[i] << " | ";
	}

	cout << "\n\n������� ����� �����: ";
	cin >> key;

	index = search_binary(array, 0, SIZE, key);

	if (index >= 0)
	{
		cout << "��������� ����� ��������� � ������ � ��������: " << index << "\n\n";
	}
	else
	{
		cout << "� ������� ��� ������ �����!\n\n";
	}
	system("pause");
}
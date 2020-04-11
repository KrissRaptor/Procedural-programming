#include <iostream>

int main()
{
	int a, b ,number;

	for (;;)
	{
		std::cout << "Enter 2 numbers : ";
		std::cin >> a >> b;
		std::cout << " Enter a number of action : 1-umn 2-del 3-sloch 4-vishet : ";
		std::cin >> number;
		switch (number)
		{
		case 1:
			std::cout << a * b << endl;
			break;
		case 2:
			std::cout << a % b << endl;
			break;
		case 3:
			std::cout << a + b << endl;
			break;
		case 4:
			std::cout << a - b << endl;
			break;
		default :
			std::cout << "Error , please try again" << endl;
			break;
		}
	}
	system("pause");
}
#include <iostream>

int main()
{
	int range1, range2;
	int sum = 0;
	


	std::cout << "Enter range 1 : " << std::endl;
	std::cin >> range1;
	std::cout << "Enter range 2 : " << std::endl;
	std::cin >> range2;

	do
	{
		range1++;
		if (range1 % 2 == 1)
		{
			sum += range1;
			std::cout << sum << " ";
		}

	} while (range1 < range2);

	system("pause");
}
#include <iostream> 


int main()
{
	int number;
	for (;;)
	{
		std::cout << "Enter a number ";
		std::cin >> number;


		if (number % 2 == 0)
		{
			std::cout << "chetnoe" << std::endl;
		}
		else if (number % 2 == 1)
		{
			std::cout << "nechotnoe " << std::endl;
		}
		else 
		{
		     std::cout << "it isn't a number";	
		}	
	}

	system("pause");
}
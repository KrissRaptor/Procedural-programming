
#include <iostream>

int main()
{
	int apple_boxes;
	int apple_boxes_in_car;
	int cars;
	int count = 0;

	std::cout << "Enter number of apple boxes ";
	std::cin >> apple_boxes;

	std::cout << "Enter number of cars ";
	std::cin >> cars;

	for (int i = 0; i < cars; i++)
	{
		std::cout << "Enter number of apple boxes to " << i + 1 << " car ";
		std::cin >> apple_boxes_in_car;
		std::count += apple_boxes_in_car;
		if (count <= apple_boxes)
		{
				continue;
		}
		if (count >= apple_boxes)
		{
			std::cout << "you have exceeded the number of boxes" << std::endl;
			break;
		}
	}
	system("pause");
}

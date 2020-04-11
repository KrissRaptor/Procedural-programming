#include <iostream>
#include <ctime>//для rand()

using std::cin;
using std::cout;
using std::endl;

int main()
{
	/*int a , b;                // 2

	cin >> a;
	cin >> b;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			cout << "***___";
		}
		cout << endl;
	}*/

   /*	char a ;
	int b;                                                      //1
	cout << "Enter a symbol : ";
	cin >> a;
	cout << "enter location: horizontally - 1 or vertically - 2 : ";
	cin >> b;

	switch (b)
	{
	case 1 :
		for (int j = 0; j < 20; j++)
		{
			cout << a;
		}
		cout << endl;
		break;
	
	case 2 :
	    
		for (int i = 0; i < 20; i++)
		{
			cout << a << endl;
		}
		
		break;
	
	default:
		cout << "error" << endl;
		break;
	}
	*/
	srand(time(NULL));          //3
	int player1_cube1;
	int player1_cube2;
	int player2_cube1;
	int player2_cube2;
	int counter1 = 0, counter2 = 0;
	
	cout << "\t\t\t\t\t\tCubes" << endl;

	for (int i = 0; i < 3; i++)
	{
		player1_cube1 = 1 + rand() % 6;
		player1_cube2 = 1 + rand() % 6;
		counter1 += player1_cube1 + player1_cube2;
		cout << "The first player rolls dice and numbers on the first: " << player1_cube1 << " on the second: " << player1_cube2 << endl;
		cout << " counter 1 = " << counter1 << endl;

		player2_cube1 = 1 + rand() % 6;
		player2_cube2 = 1 + rand() % 6;
		counter2 += player2_cube1 + player2_cube2;
		cout << "The second player rolls dice and numbers on the first: " << player2_cube1 << " on the second: " << player2_cube2 << endl;
		cout << " counter 2 = " << counter2 << endl;

		cout << "_____________________________________________" << endl;
	}
		if (counter1 > counter2)
		{
			cout << "The winner is first player" << endl;
		}
		else if (counter1 < counter2)
		{
			cout << "The winner is second player" << endl;
		}

	system("pause");
}
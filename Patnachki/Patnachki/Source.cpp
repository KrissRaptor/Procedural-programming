#include"Prototypes_libraries.h"


void Delete_pfield(int** pfield)
{
	for (int i = 0; i < 4; i++)
	{
		delete[] pfield[i];
	}
	delete[] pfield;
}

void Fill_pfield(COORD position, int**& pfield, int* parray1)
{
	//2
	int index;// собственно индекс [I]к[/I]
	for (int g = 0; g < 26; g++)  // обнуляем массив
	{
		parray1[g] = 0;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//проверка на единственность
			while (1)
			{
				index = rand() % 16;
				if (parray1[index] == 0)
				{
					parray1[index] = 1;
					pfield[i][j] = index;
					break;
				}
			}
			//cout << pfield[i][j] << " ";
			if (pfield[i][j] == 0)//ищем нулевой элемент в массиве
			{
				position.X = j;
				position.Y = i;
			}
		}
		//cout << endl;
	}
	delete[]parray1;
}

void Game(COORD position, HANDLE hConsole) //растановка
{
	int** pfield = new int *[4];//создаём двумерное поле //основной массив
	int* parray1 = new int[26];// создаем массив, в котором по индексу [I]к[/I] будет храниться 0 или 1


	Create_array(pfield, 4, 4);//создать

	Fill_pfield(position, pfield, parray1);//заполнить
	
	Show_matrix(pfield, position, hConsole);//показать
	
//	position.X = 50;
	//position.Y = 20;

	Game_engine(position, pfield, hConsole);
}

void Create_array(int**& matrix, int x, int y)
{
		matrix = new int * [y];
		for (int i = 0; i < y; i++)
		{
			matrix[i] = new int[x];
		}
}

void Show_matrix(int** pfield , COORD position, HANDLE hConcole)
{
	position.X = 30;
	position.Y = 5;
	SetConsoleCursorPosition(hConcole, position);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (pfield[i][j] < 10)
			{
				//position.X++;
				SetConsoleCursorPosition(hConcole, position);
				cout << "|";
				position.X++;
				SetConsoleCursorPosition(hConcole, position);
				cout << pfield[i][j];
				position.X +=2;
				SetConsoleCursorPosition(hConcole, position);
				cout << " |";
			}
			else if(pfield[i][j] >= 10)
			{
				//position.X++;
				SetConsoleCursorPosition(hConcole, position);
				cout << "|";
				position.X++;
				SetConsoleCursorPosition(hConcole, position);
				cout << pfield[i][j];
				position.X += 2;
				SetConsoleCursorPosition(hConcole, position);
				cout << "|";
			}	
		}
		position.Y++;
		position.X = 30;
	}
}

void Win(COORD position, HANDLE hConsole)
{
	Set_position_color(position, hConsole, 50, 5, 12);
	cout << "YOU WIN!! " << std::endl;
	
	number_victories++;

	Sleep(5000);
	Saves(number_victories);
	return;
}

void Game_engine(COORD position, int** pfield, HANDLE hConsole)
{
	while (true)
	{
		Set_position_color(position, hConsole, 30, 15, 10);
		cout << "Enter a number of element , which you wish to shift :";
		int row1, colum1;
		std::cin >> row1 >> colum1;
		
		//читы
		if (row1 == 555 || colum1 == 666)
		{
			system("cls");
			Win(position, hConsole);
			Delete_pfield(pfield);
			return;
		}
		if (row1 >= 4 || colum1 >= 4)//проверка
		{
			Set_position_color(position, hConsole, 30, 16, 10);
			cout << "\nError select a value from 0 to 3";
			std::cin >> row1 >> colum1;
		}

		Set_position_color(position, hConsole, 30, 16, 10);
		cout << "\nSelect the place where you want to move the item :";
		int row2, colum2; ;
		std::cin >> row2 >> colum2;
		//	cout << " ";

		if (row2 >= 4 || colum2 >= 4)
		{
			Set_position_color(position, hConsole, 30, 17, 10);
			cout << "\nError select a value from 0 to 3";
			std::cin >> row2 >> colum2;
		}


		//меняем местами
		int temp = 0;
		temp = pfield[row1][colum1];
		pfield[row1][colum1] = pfield[row2][colum2];
		pfield[row2][colum2] = temp;

		//cout << endl;
		//условие победы
		if (pfield[0][0] == 0 && pfield[0][3] == 3 && pfield[1][0] == 4 && pfield[1][3] == 7 && pfield[2][0] == 8 && pfield[2][3] == 11 && pfield[3][0] == 12 && pfield[1][0] == 15)
		{
			system("cls");
			Win(position, hConsole);
			Delete_pfield(pfield);
			return;
		}

		system("cls");
		Show_matrix(pfield, position,  hConsole);
		cout << std::endl;
		//game_engine(position, pfield, hConsole);
	}
}

void Set_position_color(COORD position, HANDLE hConsole ,int X,int Y ,int color) // меньше строк кода ,для цвета и координат текста
{
	position.X = X;
	position.Y = Y;
	SetConsoleCursorPosition(hConsole, position);
	SetConsoleTextAttribute(hConsole, color);
}

void menu(COORD position, HANDLE hConsole)//
{
	Set_position_color(position, hConsole, 50, 9, 10);
	cout << "Menu " << std::endl;
	Set_position_color(position, hConsole, 40, 10, 10);
	cout << "1.Play game " << std::endl;
	Set_position_color(position, hConsole, 40, 11, 10);
	cout << "2.Exit " << std::endl;
	Set_position_color(position, hConsole, 40, 12, 10);
	cout << "Press key 1 or 2 to play the game " << std::endl;

	char key = _getch();

	while (true) 
	{
		switch (key)
		{
		case 49:
			system("cls");
			Game(position, hConsole);
			//break;
			return;
		case 50:
			return;
		default:
			//system("cls");
			cout << "Error ,press another key ! \n";
		}
	}
}

void Saves(int &number_of_victories)
{
	     //ЗАПИСЬ ИМЕНИ И КОЛ.ПОБЕД
	    std::ofstream save1;// создаём объект класса ofstream для записи

		std::string name;

		save1.open("saves.txt", std::ofstream::app); //открываем файл,для запаси //ofstream::app - для записи новых данных 

		cout << "Enter your name ";
		std::cin >> name;
		save1 << name << " " << number_of_victories << std::endl;

		save1.close(); // закрываем файл
}

void Start_game()
{
	srand(time(NULL));

	system("mode con cols=120 lines=30"); // фиксируем размер консоли

	COORD position;
	position.X = 0;
	position.Y = 0;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //извлекает Дескриптор устройства стандартного вывода

	menu(position, hConsole);//вызов меню
	
	system("pause");
}

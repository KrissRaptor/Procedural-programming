#include "Names.h"

//HANDLE - дескриптор объекта
//COORD - встроенная структура Coord , которая также тип данных

DWORD WINAPI MusicThread1(void* p )  //функция для музыки
{
		PlaySound("D:\\New\\Sound.WAV", NULL, SND_NODEFAULT | SND_LOOP);// нужно прописать путь
		return 0;
}

DWORD WINAPI MusicThread2(void* p )  //функция для музыки
{
		PlaySound("D:\\New\\Are you ready.WAV", NULL, SND_NODEFAULT | SND_LOOP);
		return 0;
}

struct Object
{
	int life = 1;
	struct //счёт  //вместо того чтобы в структуре obj создавать поля с таким же названием
	{
		COORD position; 
		int number = 0; // номер
	}score;//имя структуры
	struct 
	{
		COORD position; // позиция яблока
		bool check = 0; // проверка 
	}apple;//имя структуры
	struct
	{
		COORD position; //позиция змейки
		int size = 3; //размер змейки
		bool point_check = 1; //  точечная проверка
		COORD *move = new COORD[size]; // массив с координатами для змейки
	}snake;//имя структуры
};

void AddRecord(COORD position, HANDLE hConsole, Object &zone) //запись
{
	ofstream save1;// создаём объект класса ofstream для записи

	string name;
	int number_of_victories = 255;

	save1.open("saves.txt", ofstream::app); //открываем файл,для запаси //ofstream::app - для записи новых данных 

	Set_color_position_text(position, hConsole, 40, 10, 9);
	cout << "Enter your name :";
	Set_color_position_text(position, hConsole, 58, 10, 9);
	cin >> name;
	save1 << name << " " << zone.score.number << endl;

	save1.close(); // закрываем файл
}

void Spawn(COORD position, HANDLE hConsole, Object &zone) //установка позиции спавна
{
	Set_color_position_text(position, hConsole, zone.snake.position.X = 10, zone.snake.position.Y = 5, 10);
	cout << char(219);//вывод символа
}

void Score(COORD position, HANDLE hConsole, Object &zone) // счетчик 
{
	position.X = 40;//координаты надписи"score"  
	position.Y = 8;
	SetConsoleTextAttribute(hConsole, 14); //Задает атрибуты символов
	SetConsoleCursorPosition(hConsole, position); // Задает положение курсора

	char scoreshow[] = "Your score: ";
	puts(scoreshow); //выводит строку
	zone.score.position.X = position.X + strlen/*длина строки*/(scoreshow); 
	zone.score.position.Y = position.Y;
	SetConsoleCursorPosition(hConsole, zone.score.position); // Задает положение курсора
	cout << zone.score.number; //показать счёт
}

void Add_score(COORD position, HANDLE hConsole, Object &zone) // довабление счета
{
	zone.score.number += 100; //увеличиваем на 100
	SetConsoleTextAttribute(hConsole, 14); // Задает атрибуты символов
	SetConsoleCursorPosition(hConsole, zone.score.position); // Задает положение курсора
	cout << zone.score.number; // выводим
}

void Start(COORD position, HANDLE hConsole)
{
	Set_color_position_text(position, hConsole, position.X = 40, position.Y = 8, 14);

	char ready[] = "Get ready!";
	puts(ready);// выводит строку
	Sleep(2000);// приостанавливает выполнение программы на сек.
	SetConsoleCursorPosition(hConsole, position); // Задает положение курсора
	for (int i = 0; i < strlen/*длина строки*/(ready); i++) 
	{
		cout << " ";  //пространство для текста 
	}
}

void Game_over(COORD position, HANDLE hConsole, Object &zone)
{
    Set_color_position_text(position, hConsole, position.X = 15, position.Y = 7, 12);
	cout << "Game Over!";

	AddRecord(position, hConsole, zone);
	zone.life--; // уменьшаем хп
	delete[] zone.snake.move; 
}

void Random_apple(COORD position, HANDLE hConsole, bool mas[20][36], Object &zone)
{
	SetConsoleTextAttribute(hConsole, 12); // Задает атрибуты символов
	zone.apple.position.X = rand() % 33 + 1; //координаты для случайного расположения яблока
	zone.apple.position.Y = rand() % 18 + 1;
	if (mas[zone.apple.position.Y][zone.apple.position.X] == 1) // если элемент  массива ==1 , то 
	{
		Random_apple(position, hConsole, mas, zone);// вызываем функцию случайное яблоко
	}
	else if (zone.apple.check != 1) 
	{
		SetConsoleCursorPosition(hConsole, zone.apple.position); // Задает положение курсора
		cout << "o";
		mas[zone.apple.position.Y][zone.apple.position.X] = 1; // массив
		zone.apple.check = 1;
	}
}

COORD *Add_size(Object &zone) // увеличение размера змейки
{
	zone.snake.size++;
	COORD *newmove/*новое движение змейки*/ = new COORD[zone.snake.size]; //  динам. массив с координатами
	if (newmove == 0) 
	{
		exit(1);
	}
	for (int i = 0; i < zone.snake.size; i++) 
	{
		newmove[i].X = zone.snake.move[i].X; 
		newmove[i].Y = zone.snake.move[i].Y;
	}
	delete[]zone.snake.move; // удаляем массив
	return newmove;//возвращает структуру
}

void First_move(COORD position, HANDLE hConsole, bool mas[20][36], Object &zone, int index)
{
	zone.snake.move[index].X = zone.snake.position.X;
	zone.snake.move[index].Y = zone.snake.position.Y;
	zone.snake.position.X++;
	SetConsoleTextAttribute(hConsole, 10); // Задает атрибуты символов
	SetConsoleCursorPosition(hConsole, zone.snake.position);// Задает положение курсора
	cout << char(219);
	mas[zone.snake.position.Y][zone.snake.position.X] = 1; //координата в массиве 
	Sleep(180); //приостанавливает выполнение программы на сек.
}

void Game(COORD position, HANDLE hConsole, bool mas[20][36])
{
	Object zone;   // зона
	Start(position, hConsole); // старт
	Spawn(position, hConsole, zone); // спавн
	Score(position, hConsole, zone); // счёт
	for (int i = 0; i < zone.snake.size - 1; i++) //пока змейка стокового значения
	{
		First_move(position, hConsole, mas, zone, i);
	}
	while (zone.life == 1)  // пока жизнь = 1
	{
		if (zone.apple.check == 0) // спавн яблока
		{
			Random_apple(position, hConsole, mas, zone);
		}
		Move(position, hConsole, mas, zone); //будет выполнятся фунция движения
	}
}

void Field(COORD position, HANDLE hConsole) // поле
{
	while (true)
	{
		Set_color_position_text(position, hConsole, position.X = 0, position.Y = 0, 10);	
		bool mas[20][36] = { 0 };
		for (int i = 0; i < 20; i++)
		{
			position.X = 0;
			SetConsoleCursorPosition(hConsole, position); // Задает положение курсора
			for (int j = 0; j < 36; j++) //заполнение массива ,рисуем поле
			{
				if (i == 0 || i == 19)
				{
					mas[i][j] = 1;
					cout << char(178); // правый край
				}
				else if (j == 0)
				{
					mas[i][j] = 1;
					cout << char(178); // левый край
				}
				else if (j == 35)
				{
					mas[i][j] = 1;
					position.X = 35;
					SetConsoleCursorPosition(hConsole, position); // // задает положение курсора
					cout << char(178); //верх ,низ
				}
			}
			position.Y++;
		}
		Game(position, hConsole, mas);

		Set_color_position_text(position, hConsole, position.X = 40, position.Y = 12, 13);
		cout << "Play again? Y/N ";

		char key = _getch();
		if (!(key == 'Y' || key == 'y'))
			return;
		system("cls");
	}
}

void Menu(COORD position, HANDLE hConsole)
{
	while (true)
	{
		Set_color_position_text(position, hConsole, 55, 8, 12);
		cout << "SNAKE";
		Set_color_position_text(position, hConsole, 50, 9, 10);
		cout << "1. Play the game";
		Set_color_position_text(position, hConsole, 50, 10, 10);
		cout << "2. Select music";
		Set_color_position_text(position, hConsole, 50, 11, 10);
		cout << "3. Rules";
		Set_color_position_text(position, hConsole, 50, 12, 10);
		cout << "4. Exit";
		Set_color_position_text(position, hConsole, 50, 13, 12);
		cout << "5. Press keys : 1 - 4 to control";

		char key = _getch(); // управление

		if (key == '1')
		{
			system("cls");// очистка экрана
			Field(position, hConsole);//поле
		}
		if (key == '2')
		{
			system("cls");
			Menu_music(position, hConsole);
		}
		if (key == '3')
		{
			system("cls");
			Rules(position, hConsole);
		}
		if (key == '4')
		{
			exit(1);//выход
		}
	    system("cls");
	}
}

void Menu_music(COORD position, HANDLE hConsole)
{
	Set_color_position_text(position, hConsole, 55, 8, 12);
	cout << "Select music";
	Set_color_position_text(position, hConsole, 50, 9, 10);
	cout << "1. We own iT";
	Set_color_position_text(position, hConsole, 50, 10, 10);
	cout << "2. Are you ready?";
	Set_color_position_text(position, hConsole, 50, 11, 11);
	cout << "3. Back to menu";
	char key;
	key = _getch(); // управление
	if (key == '1') 
	{
		CreateThread(0, 0, MusicThread1, 0, 0, 0);
		system("cls");
		Menu(position, hConsole);
	}
	else if (key == '2')
	{
		CreateThread(0, 0, MusicThread2, 0, 0, 0);
		system("cls");
		Menu(position, hConsole);
	}
	else if (key == '3')
	{
		system("cls");
		Menu(position, hConsole);
	}
}

void Move(COORD position, HANDLE hConsole, bool mas[20][36], Object &zone)
{
	SetConsoleTextAttribute(hConsole, 10);// Задает атрибуты символов
	int key = _getch(); //управление
	if (key == 75) //Стрелка влево
	{
		while (!_kbhit()) //ожидание нажатия клавиши
		{
			for (int i = zone.snake.size - 1; i >= 0; i--) // очистка после хода змейки
			{
				if (i == 0)
				{
					zone.snake.move[i].X = zone.snake.position.X;
					zone.snake.move[i].Y = zone.snake.position.Y;
				}
				else
				{
					zone.snake.move[i].X = zone.snake.move[i - 1].X;
					zone.snake.move[i].Y = zone.snake.move[i - 1].Y;
				}
				if (i == zone.snake.size - 1)//если змейка поворачивает ,то отображается пробел
				{

					SetConsoleCursorPosition(hConsole, zone.snake.move[i]); // Задает положение курсора
					cout << " ";
					mas[zone.snake.move[i].Y][zone.snake.move[i].X] = 0; //массив
				}
			}
			zone.snake.position.X--;
			if (zone.snake.position.X == zone.apple.position.X && zone.snake.position.Y == zone.apple.position.Y && mas[zone.snake.position.Y][zone.snake.position.X] == zone.snake.point_check)//если сьели яблоко
			{
				mas[zone.snake.position.Y][zone.snake.position.X] = 0; //массив
				zone.snake.move = Add_size(zone);
				zone.apple.check = 0;
				Add_score(position, hConsole, zone); //добавить счёт (100)
				Random_apple(position, hConsole, mas, zone); //яблочко рандомное
			}
			if (mas[zone.snake.position.Y][zone.snake.position.X] == zone.snake.point_check)//если столкновение
			{
				Game_over(position, hConsole, zone);// конец игры
				return;
			}
			SetConsoleTextAttribute(hConsole, 10); // Задает атрибуты символов
			SetConsoleCursorPosition(hConsole, zone.snake.position); // Задает положение курсора
			mas[zone.snake.position.Y][zone.snake.position.X] = 1;//заполнение координат массива еденицей при движении
			cout << char(219);
			Sleep(180);// приостанавливает выполнение программы на сек.
		}
	}
	if (key == 77)//Стрелка вправо
	{
		while (!_kbhit())//ожидание нажатия клавиши
		{
			for (int i = zone.snake.size - 1; i >= 0; i--) // очистка после хода змейки
			{
				if (i == 0)
				{
					zone.snake.move[i].X = zone.snake.position.X;
					zone.snake.move[i].Y = zone.snake.position.Y;
				}
				else
				{
					zone.snake.move[i].X = zone.snake.move[i - 1].X;
					zone.snake.move[i].Y = zone.snake.move[i - 1].Y;
				}
				if (i == zone.snake.size - 1) //если змейка поворачивает ,то отображается пробел
				{

					SetConsoleCursorPosition(hConsole, zone.snake.move[i]);// Задает положение курсора
					cout << " ";
					mas[zone.snake.move[i].Y][zone.snake.move[i].X] = 0;
				}
			}
			zone.snake.position.X++;
			if (zone.snake.position.X == zone.apple.position.X && zone.snake.position.Y == zone.apple.position.Y && mas[zone.snake.position.Y][zone.snake.position.X] == zone.snake.point_check)//если сьели яблоко
			{
				mas[zone.snake.position.Y][zone.snake.position.X] = 0;
				zone.snake.move = Add_size(zone);
				zone.apple.check = 0;
				Add_score(position, hConsole, zone);
				Random_apple(position, hConsole, mas, zone);
			}
			if (mas[zone.snake.position.Y][zone.snake.position.X] == zone.snake.point_check)//если столкновение
			{
				Game_over(position, hConsole, zone);
				return;
			}
			SetConsoleTextAttribute(hConsole, 10);// Задает атрибуты символов
			SetConsoleCursorPosition(hConsole, zone.snake.position);// Задает положение курсора
			cout << char(219);
			mas[zone.snake.position.Y][zone.snake.position.X] = 1;
			Sleep(180);// приостанавливает выполнение программы на сек.
		}
	}
	if (key == 72)//Стрелка вверх
	{
		while (!_kbhit())//ожидание нажатия клавиши
		{
			for (int i = zone.snake.size - 1; i >= 0; i--) // очистка после хода змейки
			{
				if (i == 0)
				{
					zone.snake.move[i].X = zone.snake.position.X;
					zone.snake.move[i].Y = zone.snake.position.Y;
				}
				else
				{
					zone.snake.move[i].X = zone.snake.move[i - 1].X;
					zone.snake.move[i].Y = zone.snake.move[i - 1].Y;
				}
				if (i == zone.snake.size - 1)//если змейка поворачивает ,то отображается пробел
				{

					SetConsoleCursorPosition(hConsole, zone.snake.move[i]);
					cout << " ";
					mas[zone.snake.move[i].Y][zone.snake.move[i].X] = 0;
				}
			}
			zone.snake.position.Y--;
			if (zone.snake.position.X == zone.apple.position.X && zone.snake.position.Y == zone.apple.position.Y && mas[zone.snake.position.Y][zone.snake.position.X] == zone.snake.point_check)//если сьели яблоко
			{
				mas[zone.snake.position.Y][zone.snake.position.X] = 0;
				zone.snake.move = Add_size(zone);
				zone.apple.check = 0;
				Add_score(position, hConsole, zone);
				Random_apple(position, hConsole, mas, zone);
			}
			if (mas[zone.snake.position.Y][zone.snake.position.X] == zone.snake.point_check)//если столкновение
			{
				Game_over(position, hConsole, zone);
				return;
			}
			SetConsoleTextAttribute(hConsole, 10);// Задает атрибуты символов
			SetConsoleCursorPosition(hConsole, zone.snake.position);
			mas[zone.snake.position.Y][zone.snake.position.X] = 1;
			cout << char(219);
			Sleep(180);// приостанавливает выполнение программы на сек.
		}
	}
	if (key == 80) //Стрелка вниз
	{
		while (!_kbhit())//ожидание нажатия клавиши
		{
			for (int i = zone.snake.size - 1; i >= 0; i--) // очистка после хода змейки
			{
				if (i == 0)
				{
					zone.snake.move[i].X = zone.snake.position.X;
					zone.snake.move[i].Y = zone.snake.position.Y;
				}
				else
				{
					zone.snake.move[i].X = zone.snake.move[i - 1].X;
					zone.snake.move[i].Y = zone.snake.move[i - 1].Y;
				}
				if (i == zone.snake.size - 1)//если змейка поворачивает ,то отображается пробел
				{

					SetConsoleCursorPosition(hConsole, zone.snake.move[i]);// Задает положение курсора
					cout << " ";
					mas[zone.snake.move[i].Y][zone.snake.move[i].X] = 0;
				}
			}
			zone.snake.position.Y++;
			if (zone.snake.position.X == zone.apple.position.X && zone.snake.position.Y == zone.apple.position.Y && mas[zone.snake.position.Y][zone.snake.position.X] == zone.snake.point_check)//если сьели яблоко
			{
				mas[zone.snake.position.Y][zone.snake.position.X] = 0;
				zone.snake.move = Add_size(zone);
				zone.apple.check = 0;
				Add_score(position, hConsole, zone);
				Random_apple(position, hConsole, mas, zone);
			}
			if (mas[zone.snake.position.Y][zone.snake.position.X] == zone.snake.point_check)//если столкновение
			{
				Game_over(position, hConsole, zone);
				break;
			}
			SetConsoleTextAttribute(hConsole, 10);// Задает атрибуты символов
			SetConsoleCursorPosition(hConsole, zone.snake.position);// Задает положение курсора
			mas[zone.snake.position.Y][zone.snake.position.X] = 1;
			cout << char(219);
			Sleep(180);// приостанавливает выполнение программы на сек.
		}
	}
}

void Rules(COORD position, HANDLE hConsole)
{
	Set_color_position_text(position, hConsole, 55, 8, 12);
	cout << "The main rule :";
	Set_color_position_text(position, hConsole, 40, 9, 10);
	cout << "1)Don't eat yourself and don't break the wall";
	Set_color_position_text(position, hConsole, 40, 10, 10);
	cout << "2)The more you eat apples , the more you become";
	Set_color_position_text(position, hConsole, 40, 11, 10);
	cout << "3)Press  the button to move right " << char(24) << " " << "left " << char(23);
	Set_color_position_text(position, hConsole, 40, 12, 10);
	cout << "4)Press  the button to move up down " << char(22) << " " << "down " << char(21);
	Set_color_position_text(position, hConsole, 40, 13, 11);
	cout << "5)Press 5 to return to the menu";
	char key;
	key = _getch(); // управление
	if (key == '5') 
	{
		system("cls");
		Menu(position, hConsole);
	}
}

void Set_color_position_text(COORD position, HANDLE hConsole, short int X, short int Y, short int color)
{
	position.X = X;
	position.Y = Y;
	SetConsoleCursorPosition(hConsole, position); //Задает положение курсора
	SetConsoleTextAttribute(hConsole, color); // Задает атрибуты символов
}

void Start_game()
{
	srand(time(0));
	system("mode con cols=120 lines=30"); // фиксируем размер консоли
	system("title Snake"); // название
	//Отключение курсора
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //извлекает Дескриптор устройства стандартного вывода
	CONSOLE_CURSOR_INFO cci; // для удаления курсора в консоли
	GetConsoleCursorInfo(h, &cci); //Извлекает информацию о размере и видимости курсора
	cci.bVisible = FALSE;// для удаления курсора в консоли
	SetConsoleCursorInfo(h, &cci); //Задает размер и видимость курсора

	COORD position;
	position.X = 0;
	position.Y = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //извлекает Дескриптор устройства стандартного вывода

	Menu(position, hConsole);//Запуск меню
}




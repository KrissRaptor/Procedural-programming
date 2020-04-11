#include "Names.h"

//HANDLE - ���������� �������
//COORD - ���������� ��������� Coord , ������� ����� ��� ������

DWORD WINAPI MusicThread1(void* p )  //������� ��� ������
{
		PlaySound("D:\\New\\Sound.WAV", NULL, SND_NODEFAULT | SND_LOOP);// ����� ��������� ����
		return 0;
}

DWORD WINAPI MusicThread2(void* p )  //������� ��� ������
{
		PlaySound("D:\\New\\Are you ready.WAV", NULL, SND_NODEFAULT | SND_LOOP);
		return 0;
}

struct Object
{
	int life = 1;
	struct //����  //������ ���� ����� � ��������� obj ��������� ���� � ����� �� ���������
	{
		COORD position; 
		int number = 0; // �����
	}score;//��� ���������
	struct 
	{
		COORD position; // ������� ������
		bool check = 0; // �������� 
	}apple;//��� ���������
	struct
	{
		COORD position; //������� ������
		int size = 3; //������ ������
		bool point_check = 1; //  �������� ��������
		COORD *move = new COORD[size]; // ������ � ������������ ��� ������
	}snake;//��� ���������
};

void AddRecord(COORD position, HANDLE hConsole, Object &zone) //������
{
	ofstream save1;// ������ ������ ������ ofstream ��� ������

	string name;
	int number_of_victories = 255;

	save1.open("saves.txt", ofstream::app); //��������� ����,��� ������ //ofstream::app - ��� ������ ����� ������ 

	Set_color_position_text(position, hConsole, 40, 10, 9);
	cout << "Enter your name :";
	Set_color_position_text(position, hConsole, 58, 10, 9);
	cin >> name;
	save1 << name << " " << zone.score.number << endl;

	save1.close(); // ��������� ����
}

void Spawn(COORD position, HANDLE hConsole, Object &zone) //��������� ������� ������
{
	Set_color_position_text(position, hConsole, zone.snake.position.X = 10, zone.snake.position.Y = 5, 10);
	cout << char(219);//����� �������
}

void Score(COORD position, HANDLE hConsole, Object &zone) // ������� 
{
	position.X = 40;//���������� �������"score"  
	position.Y = 8;
	SetConsoleTextAttribute(hConsole, 14); //������ �������� ��������
	SetConsoleCursorPosition(hConsole, position); // ������ ��������� �������

	char scoreshow[] = "Your score: ";
	puts(scoreshow); //������� ������
	zone.score.position.X = position.X + strlen/*����� ������*/(scoreshow); 
	zone.score.position.Y = position.Y;
	SetConsoleCursorPosition(hConsole, zone.score.position); // ������ ��������� �������
	cout << zone.score.number; //�������� ����
}

void Add_score(COORD position, HANDLE hConsole, Object &zone) // ���������� �����
{
	zone.score.number += 100; //����������� �� 100
	SetConsoleTextAttribute(hConsole, 14); // ������ �������� ��������
	SetConsoleCursorPosition(hConsole, zone.score.position); // ������ ��������� �������
	cout << zone.score.number; // �������
}

void Start(COORD position, HANDLE hConsole)
{
	Set_color_position_text(position, hConsole, position.X = 40, position.Y = 8, 14);

	char ready[] = "Get ready!";
	puts(ready);// ������� ������
	Sleep(2000);// ���������������� ���������� ��������� �� ���.
	SetConsoleCursorPosition(hConsole, position); // ������ ��������� �������
	for (int i = 0; i < strlen/*����� ������*/(ready); i++) 
	{
		cout << " ";  //������������ ��� ������ 
	}
}

void Game_over(COORD position, HANDLE hConsole, Object &zone)
{
    Set_color_position_text(position, hConsole, position.X = 15, position.Y = 7, 12);
	cout << "Game Over!";

	AddRecord(position, hConsole, zone);
	zone.life--; // ��������� ��
	delete[] zone.snake.move; 
}

void Random_apple(COORD position, HANDLE hConsole, bool mas[20][36], Object &zone)
{
	SetConsoleTextAttribute(hConsole, 12); // ������ �������� ��������
	zone.apple.position.X = rand() % 33 + 1; //���������� ��� ���������� ������������ ������
	zone.apple.position.Y = rand() % 18 + 1;
	if (mas[zone.apple.position.Y][zone.apple.position.X] == 1) // ���� �������  ������� ==1 , �� 
	{
		Random_apple(position, hConsole, mas, zone);// �������� ������� ��������� ������
	}
	else if (zone.apple.check != 1) 
	{
		SetConsoleCursorPosition(hConsole, zone.apple.position); // ������ ��������� �������
		cout << "o";
		mas[zone.apple.position.Y][zone.apple.position.X] = 1; // ������
		zone.apple.check = 1;
	}
}

COORD *Add_size(Object &zone) // ���������� ������� ������
{
	zone.snake.size++;
	COORD *newmove/*����� �������� ������*/ = new COORD[zone.snake.size]; //  �����. ������ � ������������
	if (newmove == 0) 
	{
		exit(1);
	}
	for (int i = 0; i < zone.snake.size; i++) 
	{
		newmove[i].X = zone.snake.move[i].X; 
		newmove[i].Y = zone.snake.move[i].Y;
	}
	delete[]zone.snake.move; // ������� ������
	return newmove;//���������� ���������
}

void First_move(COORD position, HANDLE hConsole, bool mas[20][36], Object &zone, int index)
{
	zone.snake.move[index].X = zone.snake.position.X;
	zone.snake.move[index].Y = zone.snake.position.Y;
	zone.snake.position.X++;
	SetConsoleTextAttribute(hConsole, 10); // ������ �������� ��������
	SetConsoleCursorPosition(hConsole, zone.snake.position);// ������ ��������� �������
	cout << char(219);
	mas[zone.snake.position.Y][zone.snake.position.X] = 1; //���������� � ������� 
	Sleep(180); //���������������� ���������� ��������� �� ���.
}

void Game(COORD position, HANDLE hConsole, bool mas[20][36])
{
	Object zone;   // ����
	Start(position, hConsole); // �����
	Spawn(position, hConsole, zone); // �����
	Score(position, hConsole, zone); // ����
	for (int i = 0; i < zone.snake.size - 1; i++) //���� ������ ��������� ��������
	{
		First_move(position, hConsole, mas, zone, i);
	}
	while (zone.life == 1)  // ���� ����� = 1
	{
		if (zone.apple.check == 0) // ����� ������
		{
			Random_apple(position, hConsole, mas, zone);
		}
		Move(position, hConsole, mas, zone); //����� ���������� ������ ��������
	}
}

void Field(COORD position, HANDLE hConsole) // ����
{
	while (true)
	{
		Set_color_position_text(position, hConsole, position.X = 0, position.Y = 0, 10);	
		bool mas[20][36] = { 0 };
		for (int i = 0; i < 20; i++)
		{
			position.X = 0;
			SetConsoleCursorPosition(hConsole, position); // ������ ��������� �������
			for (int j = 0; j < 36; j++) //���������� ������� ,������ ����
			{
				if (i == 0 || i == 19)
				{
					mas[i][j] = 1;
					cout << char(178); // ������ ����
				}
				else if (j == 0)
				{
					mas[i][j] = 1;
					cout << char(178); // ����� ����
				}
				else if (j == 35)
				{
					mas[i][j] = 1;
					position.X = 35;
					SetConsoleCursorPosition(hConsole, position); // // ������ ��������� �������
					cout << char(178); //���� ,���
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

		char key = _getch(); // ����������

		if (key == '1')
		{
			system("cls");// ������� ������
			Field(position, hConsole);//����
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
			exit(1);//�����
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
	key = _getch(); // ����������
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
	SetConsoleTextAttribute(hConsole, 10);// ������ �������� ��������
	int key = _getch(); //����������
	if (key == 75) //������� �����
	{
		while (!_kbhit()) //�������� ������� �������
		{
			for (int i = zone.snake.size - 1; i >= 0; i--) // ������� ����� ���� ������
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
				if (i == zone.snake.size - 1)//���� ������ ������������ ,�� ������������ ������
				{

					SetConsoleCursorPosition(hConsole, zone.snake.move[i]); // ������ ��������� �������
					cout << " ";
					mas[zone.snake.move[i].Y][zone.snake.move[i].X] = 0; //������
				}
			}
			zone.snake.position.X--;
			if (zone.snake.position.X == zone.apple.position.X && zone.snake.position.Y == zone.apple.position.Y && mas[zone.snake.position.Y][zone.snake.position.X] == zone.snake.point_check)//���� ����� ������
			{
				mas[zone.snake.position.Y][zone.snake.position.X] = 0; //������
				zone.snake.move = Add_size(zone);
				zone.apple.check = 0;
				Add_score(position, hConsole, zone); //�������� ���� (100)
				Random_apple(position, hConsole, mas, zone); //������� ���������
			}
			if (mas[zone.snake.position.Y][zone.snake.position.X] == zone.snake.point_check)//���� ������������
			{
				Game_over(position, hConsole, zone);// ����� ����
				return;
			}
			SetConsoleTextAttribute(hConsole, 10); // ������ �������� ��������
			SetConsoleCursorPosition(hConsole, zone.snake.position); // ������ ��������� �������
			mas[zone.snake.position.Y][zone.snake.position.X] = 1;//���������� ��������� ������� �������� ��� ��������
			cout << char(219);
			Sleep(180);// ���������������� ���������� ��������� �� ���.
		}
	}
	if (key == 77)//������� ������
	{
		while (!_kbhit())//�������� ������� �������
		{
			for (int i = zone.snake.size - 1; i >= 0; i--) // ������� ����� ���� ������
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
				if (i == zone.snake.size - 1) //���� ������ ������������ ,�� ������������ ������
				{

					SetConsoleCursorPosition(hConsole, zone.snake.move[i]);// ������ ��������� �������
					cout << " ";
					mas[zone.snake.move[i].Y][zone.snake.move[i].X] = 0;
				}
			}
			zone.snake.position.X++;
			if (zone.snake.position.X == zone.apple.position.X && zone.snake.position.Y == zone.apple.position.Y && mas[zone.snake.position.Y][zone.snake.position.X] == zone.snake.point_check)//���� ����� ������
			{
				mas[zone.snake.position.Y][zone.snake.position.X] = 0;
				zone.snake.move = Add_size(zone);
				zone.apple.check = 0;
				Add_score(position, hConsole, zone);
				Random_apple(position, hConsole, mas, zone);
			}
			if (mas[zone.snake.position.Y][zone.snake.position.X] == zone.snake.point_check)//���� ������������
			{
				Game_over(position, hConsole, zone);
				return;
			}
			SetConsoleTextAttribute(hConsole, 10);// ������ �������� ��������
			SetConsoleCursorPosition(hConsole, zone.snake.position);// ������ ��������� �������
			cout << char(219);
			mas[zone.snake.position.Y][zone.snake.position.X] = 1;
			Sleep(180);// ���������������� ���������� ��������� �� ���.
		}
	}
	if (key == 72)//������� �����
	{
		while (!_kbhit())//�������� ������� �������
		{
			for (int i = zone.snake.size - 1; i >= 0; i--) // ������� ����� ���� ������
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
				if (i == zone.snake.size - 1)//���� ������ ������������ ,�� ������������ ������
				{

					SetConsoleCursorPosition(hConsole, zone.snake.move[i]);
					cout << " ";
					mas[zone.snake.move[i].Y][zone.snake.move[i].X] = 0;
				}
			}
			zone.snake.position.Y--;
			if (zone.snake.position.X == zone.apple.position.X && zone.snake.position.Y == zone.apple.position.Y && mas[zone.snake.position.Y][zone.snake.position.X] == zone.snake.point_check)//���� ����� ������
			{
				mas[zone.snake.position.Y][zone.snake.position.X] = 0;
				zone.snake.move = Add_size(zone);
				zone.apple.check = 0;
				Add_score(position, hConsole, zone);
				Random_apple(position, hConsole, mas, zone);
			}
			if (mas[zone.snake.position.Y][zone.snake.position.X] == zone.snake.point_check)//���� ������������
			{
				Game_over(position, hConsole, zone);
				return;
			}
			SetConsoleTextAttribute(hConsole, 10);// ������ �������� ��������
			SetConsoleCursorPosition(hConsole, zone.snake.position);
			mas[zone.snake.position.Y][zone.snake.position.X] = 1;
			cout << char(219);
			Sleep(180);// ���������������� ���������� ��������� �� ���.
		}
	}
	if (key == 80) //������� ����
	{
		while (!_kbhit())//�������� ������� �������
		{
			for (int i = zone.snake.size - 1; i >= 0; i--) // ������� ����� ���� ������
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
				if (i == zone.snake.size - 1)//���� ������ ������������ ,�� ������������ ������
				{

					SetConsoleCursorPosition(hConsole, zone.snake.move[i]);// ������ ��������� �������
					cout << " ";
					mas[zone.snake.move[i].Y][zone.snake.move[i].X] = 0;
				}
			}
			zone.snake.position.Y++;
			if (zone.snake.position.X == zone.apple.position.X && zone.snake.position.Y == zone.apple.position.Y && mas[zone.snake.position.Y][zone.snake.position.X] == zone.snake.point_check)//���� ����� ������
			{
				mas[zone.snake.position.Y][zone.snake.position.X] = 0;
				zone.snake.move = Add_size(zone);
				zone.apple.check = 0;
				Add_score(position, hConsole, zone);
				Random_apple(position, hConsole, mas, zone);
			}
			if (mas[zone.snake.position.Y][zone.snake.position.X] == zone.snake.point_check)//���� ������������
			{
				Game_over(position, hConsole, zone);
				break;
			}
			SetConsoleTextAttribute(hConsole, 10);// ������ �������� ��������
			SetConsoleCursorPosition(hConsole, zone.snake.position);// ������ ��������� �������
			mas[zone.snake.position.Y][zone.snake.position.X] = 1;
			cout << char(219);
			Sleep(180);// ���������������� ���������� ��������� �� ���.
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
	key = _getch(); // ����������
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
	SetConsoleCursorPosition(hConsole, position); //������ ��������� �������
	SetConsoleTextAttribute(hConsole, color); // ������ �������� ��������
}

void Start_game()
{
	srand(time(0));
	system("mode con cols=120 lines=30"); // ��������� ������ �������
	system("title Snake"); // ��������
	//���������� �������
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //��������� ���������� ���������� ������������ ������
	CONSOLE_CURSOR_INFO cci; // ��� �������� ������� � �������
	GetConsoleCursorInfo(h, &cci); //��������� ���������� � ������� � ��������� �������
	cci.bVisible = FALSE;// ��� �������� ������� � �������
	SetConsoleCursorInfo(h, &cci); //������ ������ � ��������� �������

	COORD position;
	position.X = 0;
	position.Y = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //��������� ���������� ���������� ������������ ������

	Menu(position, hConsole);//������ ����
}




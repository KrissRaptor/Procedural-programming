#pragma once
#define _CRT_SECURE_NO_WARNINGS //удаление безопасных предупреждений
#pragma comment(lib, "winmm.lib") // для музыки


#include <iostream> //базовая библиотека
#include <string> //для работы со строками
#include <fstream>//для работы с файлами
#include <Windows.h>//для работы со COORD ,HANDLE
#include <time.h>//для работы с rand() - полный рандом
#include <conio.h>//для работы со _getch() , khbit()

using namespace std;

DWORD WINAPI MusicThread1(void* p);
DWORD WINAPI MusicThread2(void* p);
struct Object;
void AddRecord(COORD position, HANDLE hConsole, Object &zone);
void Spawn(COORD position, HANDLE hConsole, Object &zone);
void Score(COORD position, HANDLE hConsole, Object &zone);
void Add_score(COORD position, HANDLE hConsole, Object &zone);
void Start(COORD position, HANDLE hConsole);
void Game_over(COORD position, HANDLE hConsole, Object &zone);
void Random_apple(COORD position, HANDLE hConsole, bool mas[20][36], Object &zone);
COORD *Add_size(Object &zone);
void First_move(COORD position, HANDLE hConsole, bool mas[20][36], Object &zone, int index);
void Move(COORD position, HANDLE hConsole, bool mas[20][36], Object &zone);
void Game(COORD position, HANDLE hConsole, bool mas[20][36]);
void Field(COORD position, HANDLE hConsole);
void Rules(COORD position, HANDLE hConsole);
void Menu(COORD position, HANDLE hConsole);
void Menu_music(COORD position, HANDLE hConsole);
void Start_game();
void Set_color_position_text(COORD position, HANDLE hConsole, short int X, short int Y, short int color);
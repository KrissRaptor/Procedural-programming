#pragma once

#include <iostream>
#include <ctime>//для rand
#include<conio.h>// для getch()
#include <windows.h>// для  SetConsoleCursorPosition,SetConsoleTextAttribute
#include <fstream> //для работы с файлами
#include <string> // для работы со строками(фукнционал)

using std::cout;


void Fill_pfield(COORD position, int**& pfield, int* parray1);

void Game_engine(COORD position, int** pfield, HANDLE hConsole);

void Game(COORD position, HANDLE hConsole);

void Create_array(int**& matrix, int x, int y);

void Show_matrix(int** matrix, COORD position, HANDLE hConsole);

void Win(COORD position, HANDLE hConsole);

void Delete_pfield(int** pfield);

void Set_position_color(COORD position, HANDLE hConsole, int X, int Y, int color);

void Saves(int& number_of_victories);

void Start_game();

static int number_victories = 0;
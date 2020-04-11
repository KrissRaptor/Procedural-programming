#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Group;
void fill_out_student_list(Group* pname_of_student, const int size);
void add_new_student(Group* pname_of_student, const int sizes);
void remove_students(Group* pname_of_student, const int size);
void end(Group* pname_of_student, const int size);
void journal_of_students(Group* pname_of_student, const int size);
void look_student_list(Group* pname_of_student, const int size);

struct Student //1 задание
{
	char* pfirst_name = new char[15];
	char* psecond_name = new char[25];
	unsigned short int age;
	unsigned short int number_of_group;
	char* ptelephone_number = new char[20];
	unsigned short int* pmark_item1 = new unsigned short int[15];//предмет номер 1 
	unsigned short int* pmark_item2 = new unsigned short int[15];//предмет номер 2 
	unsigned short int* pmark_item3 = new unsigned short int[15];//предмет номер 3 
	unsigned short int* pmark_item4 = new unsigned short int[15];//предмет номер 4 
	unsigned short int* pmark_item5 = new unsigned short int[15];//предмет номер 5 
};

struct Holidays// 2 задание
{
	char* Thanksgiving_Day = new char[410]{ "9 ноября 1620 года корабль Мэйфлауер высадил пилигримов на мысе Кейд-Код, что тянется вдоль побережья Массачусетского залива. Ранней осенью колонисты собрали свой первый урожай. Они устроили праздник, на который пригласили своих друзей-индейцев, и назвали его Благодарение. Первое Благодарение затянулось на целых три дня, в течение которых пилигримы и их гости угощались жареной индейкой, тыквой и кукурузой." };
	char* New_Year = new char[410]{ "Для любого народа Новый год - это пора, когда, оглядываясь на прожитые 365 дней, люди оценивают свою жизнь, строят планы на будущее. Верит человек в судьбу или нет, но каждый, тем не менее, надеется, что наступающий год принесет ему и его близким что-то новое, хорошее и доброе. Каждому хочется оставить неприятности и невзгоды позади и с надёждой заглянуть в будущее. " };
	char* Valentines_Day = new char[530]{ "Что же происходит 14 февраля? Это и к нам в Россию наконец-то пришёл из-за границы праздник, - день святого Валентина. Кто же такой этот святой Валентин и почему его имя связано с праздником влюблённых? В III веке нашей эры правил в Риме суровый и решительный император Клавдий. Больше всего он любил войну и хотел, чтобы его воины никогда не отвлекались от великого ратного дела. Но, увы! Стрелы Амура, любовные стрелы, поражали доблестное войско Клавдия. Солдаты и их начальники влюблялись, женились и оставляли военную службу " };
	char* St_Nicolas_day = new char[500]{ " Каждый год 5 декабря к праздничной набережной Амстердама подходит большой пароход, который встречает огромная толпа. Когда он причаливает к пристани, во всем городе начинается перезвон колоколов. Ружейные выстрелы и торжествующие крики встречающих извещают город о прибытии парохода. Долгожданный гость - это святой Николай, день которого празднуют 6 декабря. Его уже давно ждут все, но с особенным нетерпением дети. Ещё задолго до праздника малыши пишут ему письма с подробным описанием подарков." };
	char* Feast_of_St_Patrick = new char[460]{ "Ни один святой не пользуется в Ирландии таким почитанием, как святой Патрик. Он - национальный святой этой страны, креститель Ирландии. Но родился святой Патрик не в Ирландии, а в Британии. Когда ему исполнилось шестнадцать лет, его похитили морские разбойники. Они увезли юношу в Ирландию и там продали его в рабство. Шесть лет Патрик пас овец. В Ирландии он уверовал в Иисуса Христа, которого горячо просил о своём освобождении и возвращении на родину. " };
	char* Nativity = new char[410]{ " День рождения Иисуса Христа вот уже почти 2000 лет отмечают миллионы людей с разным цветом кожи и различных политических убеждений. Объединяет их одно - вера в Господа Иисуса Христа. В России в канун Рождества, как правило, наступает тихий морозный вечер, ярко светит луна, звучно поскрипывает снег под ногами запоздалых прохожих. Этот вечер ещё называют Сочельник" };
};

struct Group //задание 3
{
	char* pname = new char[15];//имя
	char* psecond_name = new char[25];
	unsigned short age;
	char* number_of_group = new char[10];
	char* ptelephone_number = new char[15];
	int number_of_estimates;/*для понимания сколько оценок нам нужно в месяц*/
	unsigned int* pmark_physics = new unsigned int[15];//предмет номер 1 
	unsigned int* pmark_psychology = new unsigned int[15];//предмет номер 2 
	unsigned int* pmark_mathematics = new unsigned int[15];//предмет номер 3 
	unsigned int* pmark_geography = new unsigned int[15];//предмет номер 4 
	unsigned int* pmark_english = new unsigned int[15];//предмет номер 5 
	unsigned int* pmark_history = new unsigned int[15];//предмет номер 6 
};

void fill_out_student_list(Group* pname_of_student, const int size) //заполняем
{
	for (int i = 0; i < size; i++)
	{
		cout << "\t\t\tStudent number: " << i + 1 << endl;

		cout << "Enter a name of student :" << endl;
		cin >> pname_of_student[i].pname;

		cout << "Enter a second name of student :" << endl;
		cin >> pname_of_student[i].psecond_name;

		cout << "Enter age of student :" << endl; //возраст
		cin >> pname_of_student[i].age;

		cout << "Enter group of student :" << endl; //группа
		cin >> pname_of_student[i].number_of_group;

		cout << "Enter a telephone number of student :" << endl;
		cin >> pname_of_student[i].ptelephone_number;// заполняем

		cout << "Enter the number of estimates per month :";
		cin >> pname_of_student[i].number_of_estimates; cout << endl;

		cout << "Enter grades for the subject Physics :" << endl; //оценки по предмету
		for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//заполняем оценки 
		{
			cin >> pname_of_student[i].pmark_physics[j];
		}

		cout << "Enter grades for the subject Phychology :" << endl;
		for (int j = 0; j < pname_of_student[i].number_of_estimates/*меньше чем указаное количество оценок в месяц*/; j++)//заполняем оценки по предмету
		{
			cin >> pname_of_student[i].pmark_psychology[j];
		}

		cout << "Enter grades for the subject Mathematics" << endl;
		for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//заполняем оценки по предмету
		{
			cin >> pname_of_student[i].pmark_mathematics[j];
		}

		cout << "Enter grades for the subject Geography :" << endl;
		for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//заполняем оценки по предмету
		{
			cin >> pname_of_student[i].pmark_geography[j];
		}

		cout << "Enter grades for the subject English :" << endl;
		for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//заполняем оценки по предмету
		{
			cin >> pname_of_student[i].pmark_english[j];
		}

		cout << "Enter grades for the subject History :" << endl;
		for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//заполняем оценки по предмету
		{
			cin >> pname_of_student[i].pmark_history[j];
		} 

	}
	end(pname_of_student, size); //выход
}

void look_student_list(Group* pname_of_student, const int size)
{
	int index/*индекс*/;
	float counter1 = 0;

	cout << "Enter the student number you want to see : ";
	cin >> index;
	cout << endl;

	cout << pname_of_student[index - 1].pname << " "; //смотрим
	cout << pname_of_student[index - 1].psecond_name << endl;
	cout << "age :" << " ";
	cout << pname_of_student[index - 1].age << endl;
	cout << "number of group :" << " ";
	cout << pname_of_student[index - 1].number_of_group << endl;
	cout << "telephone number :" << " ";
	cout << pname_of_student[index - 1].ptelephone_number << endl;// заполняем

	cout << "Physics grades :" << " "; //оценки по предмету
	for (int j = 0; j < pname_of_student[index - 1].number_of_estimates; j++)//заполняем оценки 
	{
		cout << pname_of_student[index - 1].pmark_physics[j] << " ";
		counter1 += pname_of_student[index - 1].pmark_physics[j]; //сумируем счетчик
	}
	cout << " Average :" << (counter1 / pname_of_student[index - 1].number_of_estimates) << endl;
	counter1 = 0;//обнуляем

	cout << "Phychology grades :" << " ";
	for (int j = 0; j < pname_of_student[index - 1].number_of_estimates; j++)//заполняем оценки по предмету
	{
		cout << pname_of_student[index - 1].pmark_psychology[j] << " ";
		counter1 += pname_of_student[index - 1].pmark_psychology[j]; //сумируем счетчик
	}
	cout << " Average :" << counter1 / pname_of_student[index - 1].number_of_estimates << endl;
	counter1 = 0;//обнуляем

	cout << "Mathematics grades :" << " ";
	for (int j = 0; j < pname_of_student[index - 1].number_of_estimates; j++)//заполняем оценки по предмету
	{
		cout << pname_of_student[index - 1].pmark_mathematics[j] << " ";
		counter1 += pname_of_student[index - 1].pmark_mathematics[j]; //сумируем счетчик
	}
	cout << " Average :" << counter1 / pname_of_student[index - 1].number_of_estimates << endl;
	counter1 = 0;//обнуляем

	cout << "Geography grades :" << " ";
	for (int j = 0; j < pname_of_student[index - 1].number_of_estimates; j++)//заполняем оценки по предмету
	{
		cout << pname_of_student[index - 1].pmark_geography[j] << " ";
		counter1 += pname_of_student[index - 1].pmark_geography[j]; //сумируем счетчик
	}
	cout << " Average :" << counter1 / pname_of_student[index - 1].number_of_estimates << endl;
	counter1 = 0;//обнуляем

	cout << "English grades :" << " ";
	for (int j = 0; j < pname_of_student[index - 1].number_of_estimates; j++)//заполняем оценки по предмету
	{
		cout << pname_of_student[index - 1].pmark_english[j] << " ";
		counter1 += pname_of_student[index - 1].pmark_english[j]; //сумируем счетчик
	}
	cout << " Average :" << counter1 / pname_of_student[index - 1].number_of_estimates << endl;
	counter1 = 0;//обнуляем

	cout << "History grades :" << " ";
	for (int j = 0; j < pname_of_student[index - 1].number_of_estimates; j++)//заполняем оценки по предмету
	{
		cout << pname_of_student[index - 1].pmark_history[j] << " ";
		counter1 += pname_of_student[index - 1].pmark_history[j]; //сумируем счетчик
	}
	cout << " Average :" << counter1 / pname_of_student[index - 1].number_of_estimates << endl;
	counter1 = 0;//обнуляем

	end(pname_of_student, size); //конец
}

void add_new_student(Group* pname_of_student, const int size) //изменяем 
{
	int answer2;

	cout << " Enter the number of students you want to add : ";
	cin >> answer2;//количество студентов ,которые хотим добавить

	Group* pname_of_student_new = new  Group[size + answer2];// создаём новый массив для элементов

	for (int i = 0; i < size; i++) // заполняем новый массив старыми эллементами
	{
		pname_of_student_new[i].pname = pname_of_student[i].pname;
	}

	for (int i = size; i < size + answer2; i++) //заполняем поля для новых студентов
	{
		cout << "Enter a name of student : " << endl;
		cin >> pname_of_student_new[i].pname;

		cout << "Enter a second of student :" << endl;
		cin >> pname_of_student_new[i].psecond_name;

		cout << "Enter age of student :" << endl; //возраст
		cin >> pname_of_student_new[i].age;

		cout << "Enter group of student :" << endl; //группа
		cin >> pname_of_student_new[i].number_of_group;

		cout << "Enter a telephone number of student :" << endl;
		cin >> pname_of_student_new[i].ptelephone_number;// заполняем

		cout << "Enter grades for the subject Physics :" << endl; //оценки по предмету
		for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//заполняем оценки 
		{
			cin >> pname_of_student_new[i].pmark_physics[j];
		}

		cout << "Enter grades for the subject Phychology :" << endl;
		for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//заполняем оценки по предмету
		{
			cin >> pname_of_student_new[i].pmark_psychology[j];
		}

		cout << "Enter grades for the subject Mathematics" << endl;
		for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//заполняем оценки по предмету
		{
			cin >> pname_of_student_new[i].pmark_mathematics[j];
		}

		cout << "Enter grades for the subject Geography :" << endl;
		for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//заполняем оценки по предмету
		{
			cin >> pname_of_student_new[i].pmark_geography[j];
		}

		cout << "Enter grades for the subject English :" << endl;
		for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//заполняем оценки по предмету
		{
			cin >> pname_of_student_new[i].pmark_english[j];
		}

		cout << "Enter grades for the subject History :" << endl;
		for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//заполняем оценки по предмету
		{
			cin >> pname_of_student_new[i].pmark_history[j];
		}
	}

	cout << "New student list :" << endl;
	for (int i = 0; i < (size + answer2); i++) //вывод новых учеников
	{
		cout << pname_of_student_new[i].pname << endl;
	}

	//delete[]pname_of_student;

	end(pname_of_student, size);
}

void remove_students(Group* pname_of_student, const int size) //удаление
{
	for (int i = 0; i < size; i++) //показать количество учеников
	{
		cout << pname_of_student[i].pname << endl;
	}

	while (true)
	{
		int answer;
		cout << "Enter a student's name which you want to delete : ";
		cin >> answer;

		if (answer > size || answer < 1) //проверка на отриц./большее число
		{
			cout << "Error ,try again " << endl;
			//remove_students(pname_of_student, size);
		}
		else //если всё ок
		{
			for (int i = answer - 1; i < size - 1; i++)
			{
				pname_of_student[i].pname = pname_of_student[i + 1].pname;

				pname_of_student[i].psecond_name = pname_of_student[i + 1].psecond_name;

				pname_of_student[i].age = pname_of_student[i + 1].age;

				pname_of_student[i].number_of_group = pname_of_student[i + 1].number_of_group;

				pname_of_student[i].ptelephone_number = pname_of_student[i + 1].ptelephone_number;

				for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//заполняем оценки 
				{
					pname_of_student[i].pmark_physics[j] = pname_of_student[i + 1].pmark_physics[j];
				}

				for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//заполняем оценки по предмету
				{
					pname_of_student[i].pmark_psychology[j] = pname_of_student[i + 1].pmark_psychology[j];
				}

				for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//заполняем оценки по предмету
				{
					pname_of_student[i].pmark_mathematics[j] = pname_of_student[i + 1].pmark_mathematics[j];
				}

				for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//заполняем оценки по предмету
				{
					pname_of_student[i].pmark_geography[j] = pname_of_student[i + 1].pmark_geography[j];
				}

				for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//заполняем оценки по предмету
				{
					pname_of_student[i].pmark_english[j] = pname_of_student[i + 1].pmark_english[j];
				}

				for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//заполняем оценки по предмету
				{
					pname_of_student[i].pmark_history[j] = pname_of_student[i + 1].pmark_history[j];
				}
			}
			end(pname_of_student, size);
			break;
		}
	}
}

void end(Group* pname_of_student, const int size)
{
	while (true)
	{
		int answer3;
		cout << endl;
		cout << "would you like to exit ?Press 1 - no , 2 - yes :";

		cin >> answer3;
		switch (answer3)
		{
		case 1:
			system("cls");
			journal_of_students(pname_of_student, size);
			break;
		case 2:
			return;
			break;
		default:
			cout << endl;
			cout << "Error ,please press another key" << endl;
			//end(pname_of_student, size);
			//break;
		}
	}
}

void journal_of_students(Group* pname_of_student, const int size)
{
	while (true)
	{
		cout << "\t\t\tWhat you would like to do?" << endl;
		cout << "1-fill out student's list" << endl;
		cout << "2-change the list's of students " << endl;
		cout << "3-remove student from list" << endl;
		cout << "4-look student's list" << endl;
		int answer1;
		cin >> answer1;

		switch (answer1)
		{
		case 1: // записываем
		{
			fill_out_student_list(pname_of_student, size);
			break;
		}
		case 2: // добавляем 
		{
			add_new_student(pname_of_student, size);
			break;
		}
		case 3: // удаляем
		{
			remove_students(pname_of_student, size);
			break;
		}
		case 4://смотрим
		{
			look_student_list(pname_of_student, size);
			break;
		}
		default:
		{
			system("cls");
			//journal_of_students(pname_of_student, size);
			//break;
			//cout << "Error ,please press another key : " << endl;
			//cin >> answer1;
		}
		}
	}
}

int main()
{
	/////////////////////////////////////////////////////////////////////////////
	//Задание 1
	//Student student;
	//cin >> student.pfirst_name;
	//cin >> student.psecond_name;
	//cin >> student.age;
	//cin >> student.number_of_group;
	//
	//for (int i = 0; i < 15; i++)//заполняем оценки 
	//{
	//	cin >> student.pmark_item1[i];
	//}	
	//
	//for (int i = 0; i < 15; i++)//заполняем оценки 
	//{
	//	cin >> student.pmark_item2[i];
	//}
	//
	//for (int i = 0; i < 15; i++)//заполняем оценки 
	//{
	//	cin >> student.pmark_item3[i];
	//}

	//for (int i = 0; i < 15; i++)//заполняем оценки 
	//{
	//	cin >> student.pmark_item3[i];
	//}
	/////////////////////////////////////////////////////////////////////////////
	//Задание 2

	//setlocale(LC_ALL, "Russian");// для 2-го задания
	//
	//Holidays day;

	//cout << day.Feast_of_St_Patrick << endl;
	//cout << day.Nativity << endl;
	//cout << day.New_Year << endl;
	//cout << day.St_Nicolas_day << endl;
	//cout << day.Thanksgiving_Day << endl;
	//cout << day.Valentines_Day << endl;

	/////////////////////////////////////////////////////////////////////////////
	//Задание 3

	unsigned size;
	cout << "Enter the size of the student journal :";
	cin >> size;
	Group* pname_of_student = new  Group[size];
	journal_of_students(pname_of_student, size);
	system("pause");
	return 0;
}












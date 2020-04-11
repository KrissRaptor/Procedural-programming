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

struct Student //1 �������
{
	char* pfirst_name = new char[15];
	char* psecond_name = new char[25];
	unsigned short int age;
	unsigned short int number_of_group;
	char* ptelephone_number = new char[20];
	unsigned short int* pmark_item1 = new unsigned short int[15];//������� ����� 1 
	unsigned short int* pmark_item2 = new unsigned short int[15];//������� ����� 2 
	unsigned short int* pmark_item3 = new unsigned short int[15];//������� ����� 3 
	unsigned short int* pmark_item4 = new unsigned short int[15];//������� ����� 4 
	unsigned short int* pmark_item5 = new unsigned short int[15];//������� ����� 5 
};

struct Holidays// 2 �������
{
	char* Thanksgiving_Day = new char[410]{ "9 ������ 1620 ���� ������� ��������� ������� ���������� �� ���� ����-���, ��� ������� ����� ��������� ��������������� ������. ������ ������ ��������� ������� ���� ������ ������. ��� �������� ��������, �� ������� ���������� ����� ������-��������, � ������� ��� ������������. ������ ������������ ���������� �� ����� ��� ���, � ������� ������� ��������� � �� ����� ��������� ������� ��������, ������ � ���������." };
	char* New_Year = new char[410]{ "��� ������ ������ ����� ��� - ��� ����, �����, ����������� �� �������� 365 ����, ���� ��������� ���� �����, ������ ����� �� �������. ����� ������� � ������ ��� ���, �� ������, ��� �� �����, ��������, ��� ����������� ��� �������� ��� � ��� ������� ���-�� �����, ������� � ������. ������� ������� �������� ������������ � �������� ������ � � ������� ��������� � �������. " };
	char* Valentines_Day = new char[530]{ "��� �� ���������� 14 �������? ��� � � ��� � ������ �������-�� ������ ��-�� ������� ��������, - ���� ������� ���������. ��� �� ����� ���� ������ �������� � ������ ��� ��� ������� � ���������� ���������? � III ���� ����� ��� ������ � ���� ������� � ����������� ��������� �������. ������ ����� �� ����� ����� � �����, ����� ��� ����� ������� �� ����������� �� �������� ������� ����. ��, ���! ������ �����, �������� ������, �������� ���������� ������ �������. ������� � �� ���������� ����������, �������� � ��������� ������� ������ " };
	char* St_Nicolas_day = new char[500]{ " ������ ��� 5 ������� � ����������� ���������� ���������� �������� ������� �������, ������� ��������� �������� �����. ����� �� ����������� � ��������, �� ���� ������ ���������� �������� ���������. �������� �������� � ������������� ����� ����������� �������� ����� � �������� ��������. ������������ ����� - ��� ������ �������, ���� �������� ��������� 6 �������. ��� ��� ����� ���� ���, �� � ��������� ����������� ����. ��� ������� �� ��������� ������ ����� ��� ������ � ��������� ��������� ��������." };
	char* Feast_of_St_Patrick = new char[460]{ "�� ���� ������ �� ���������� � �������� ����� ����������, ��� ������ ������. �� - ������������ ������ ���� ������, ���������� ��������. �� ������� ������ ������ �� � ��������, � � ��������. ����� ��� ����������� ����������� ���, ��� �������� ������� ����������. ��� ������ ����� � �������� � ��� ������� ��� � �������. ����� ��� ������ ��� ����. � �������� �� �������� � ������ ������, �������� ������ ������ � ���� ������������ � ����������� �� ������. " };
	char* Nativity = new char[410]{ " ���� �������� ������ ������ ��� ��� ����� 2000 ��� �������� �������� ����� � ������ ������ ���� � ��������� ������������ ���������. ���������� �� ���� - ���� � ������� ������ ������. � ������ � ����� ���������, ��� �������, ��������� ����� �������� �����, ���� ������ ����, ������ ������������ ���� ��� ������ ���������� ��������. ���� ����� ��� �������� ���������" };
};

struct Group //������� 3
{
	char* pname = new char[15];//���
	char* psecond_name = new char[25];
	unsigned short age;
	char* number_of_group = new char[10];
	char* ptelephone_number = new char[15];
	int number_of_estimates;/*��� ��������� ������� ������ ��� ����� � �����*/
	unsigned int* pmark_physics = new unsigned int[15];//������� ����� 1 
	unsigned int* pmark_psychology = new unsigned int[15];//������� ����� 2 
	unsigned int* pmark_mathematics = new unsigned int[15];//������� ����� 3 
	unsigned int* pmark_geography = new unsigned int[15];//������� ����� 4 
	unsigned int* pmark_english = new unsigned int[15];//������� ����� 5 
	unsigned int* pmark_history = new unsigned int[15];//������� ����� 6 
};

void fill_out_student_list(Group* pname_of_student, const int size) //���������
{
	for (int i = 0; i < size; i++)
	{
		cout << "\t\t\tStudent number: " << i + 1 << endl;

		cout << "Enter a name of student :" << endl;
		cin >> pname_of_student[i].pname;

		cout << "Enter a second name of student :" << endl;
		cin >> pname_of_student[i].psecond_name;

		cout << "Enter age of student :" << endl; //�������
		cin >> pname_of_student[i].age;

		cout << "Enter group of student :" << endl; //������
		cin >> pname_of_student[i].number_of_group;

		cout << "Enter a telephone number of student :" << endl;
		cin >> pname_of_student[i].ptelephone_number;// ���������

		cout << "Enter the number of estimates per month :";
		cin >> pname_of_student[i].number_of_estimates; cout << endl;

		cout << "Enter grades for the subject Physics :" << endl; //������ �� ��������
		for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//��������� ������ 
		{
			cin >> pname_of_student[i].pmark_physics[j];
		}

		cout << "Enter grades for the subject Phychology :" << endl;
		for (int j = 0; j < pname_of_student[i].number_of_estimates/*������ ��� �������� ���������� ������ � �����*/; j++)//��������� ������ �� ��������
		{
			cin >> pname_of_student[i].pmark_psychology[j];
		}

		cout << "Enter grades for the subject Mathematics" << endl;
		for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//��������� ������ �� ��������
		{
			cin >> pname_of_student[i].pmark_mathematics[j];
		}

		cout << "Enter grades for the subject Geography :" << endl;
		for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//��������� ������ �� ��������
		{
			cin >> pname_of_student[i].pmark_geography[j];
		}

		cout << "Enter grades for the subject English :" << endl;
		for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//��������� ������ �� ��������
		{
			cin >> pname_of_student[i].pmark_english[j];
		}

		cout << "Enter grades for the subject History :" << endl;
		for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//��������� ������ �� ��������
		{
			cin >> pname_of_student[i].pmark_history[j];
		} 

	}
	end(pname_of_student, size); //�����
}

void look_student_list(Group* pname_of_student, const int size)
{
	int index/*������*/;
	float counter1 = 0;

	cout << "Enter the student number you want to see : ";
	cin >> index;
	cout << endl;

	cout << pname_of_student[index - 1].pname << " "; //�������
	cout << pname_of_student[index - 1].psecond_name << endl;
	cout << "age :" << " ";
	cout << pname_of_student[index - 1].age << endl;
	cout << "number of group :" << " ";
	cout << pname_of_student[index - 1].number_of_group << endl;
	cout << "telephone number :" << " ";
	cout << pname_of_student[index - 1].ptelephone_number << endl;// ���������

	cout << "Physics grades :" << " "; //������ �� ��������
	for (int j = 0; j < pname_of_student[index - 1].number_of_estimates; j++)//��������� ������ 
	{
		cout << pname_of_student[index - 1].pmark_physics[j] << " ";
		counter1 += pname_of_student[index - 1].pmark_physics[j]; //�������� �������
	}
	cout << " Average :" << (counter1 / pname_of_student[index - 1].number_of_estimates) << endl;
	counter1 = 0;//��������

	cout << "Phychology grades :" << " ";
	for (int j = 0; j < pname_of_student[index - 1].number_of_estimates; j++)//��������� ������ �� ��������
	{
		cout << pname_of_student[index - 1].pmark_psychology[j] << " ";
		counter1 += pname_of_student[index - 1].pmark_psychology[j]; //�������� �������
	}
	cout << " Average :" << counter1 / pname_of_student[index - 1].number_of_estimates << endl;
	counter1 = 0;//��������

	cout << "Mathematics grades :" << " ";
	for (int j = 0; j < pname_of_student[index - 1].number_of_estimates; j++)//��������� ������ �� ��������
	{
		cout << pname_of_student[index - 1].pmark_mathematics[j] << " ";
		counter1 += pname_of_student[index - 1].pmark_mathematics[j]; //�������� �������
	}
	cout << " Average :" << counter1 / pname_of_student[index - 1].number_of_estimates << endl;
	counter1 = 0;//��������

	cout << "Geography grades :" << " ";
	for (int j = 0; j < pname_of_student[index - 1].number_of_estimates; j++)//��������� ������ �� ��������
	{
		cout << pname_of_student[index - 1].pmark_geography[j] << " ";
		counter1 += pname_of_student[index - 1].pmark_geography[j]; //�������� �������
	}
	cout << " Average :" << counter1 / pname_of_student[index - 1].number_of_estimates << endl;
	counter1 = 0;//��������

	cout << "English grades :" << " ";
	for (int j = 0; j < pname_of_student[index - 1].number_of_estimates; j++)//��������� ������ �� ��������
	{
		cout << pname_of_student[index - 1].pmark_english[j] << " ";
		counter1 += pname_of_student[index - 1].pmark_english[j]; //�������� �������
	}
	cout << " Average :" << counter1 / pname_of_student[index - 1].number_of_estimates << endl;
	counter1 = 0;//��������

	cout << "History grades :" << " ";
	for (int j = 0; j < pname_of_student[index - 1].number_of_estimates; j++)//��������� ������ �� ��������
	{
		cout << pname_of_student[index - 1].pmark_history[j] << " ";
		counter1 += pname_of_student[index - 1].pmark_history[j]; //�������� �������
	}
	cout << " Average :" << counter1 / pname_of_student[index - 1].number_of_estimates << endl;
	counter1 = 0;//��������

	end(pname_of_student, size); //�����
}

void add_new_student(Group* pname_of_student, const int size) //�������� 
{
	int answer2;

	cout << " Enter the number of students you want to add : ";
	cin >> answer2;//���������� ��������� ,������� ����� ��������

	Group* pname_of_student_new = new  Group[size + answer2];// ������ ����� ������ ��� ���������

	for (int i = 0; i < size; i++) // ��������� ����� ������ ������� �����������
	{
		pname_of_student_new[i].pname = pname_of_student[i].pname;
	}

	for (int i = size; i < size + answer2; i++) //��������� ���� ��� ����� ���������
	{
		cout << "Enter a name of student : " << endl;
		cin >> pname_of_student_new[i].pname;

		cout << "Enter a second of student :" << endl;
		cin >> pname_of_student_new[i].psecond_name;

		cout << "Enter age of student :" << endl; //�������
		cin >> pname_of_student_new[i].age;

		cout << "Enter group of student :" << endl; //������
		cin >> pname_of_student_new[i].number_of_group;

		cout << "Enter a telephone number of student :" << endl;
		cin >> pname_of_student_new[i].ptelephone_number;// ���������

		cout << "Enter grades for the subject Physics :" << endl; //������ �� ��������
		for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//��������� ������ 
		{
			cin >> pname_of_student_new[i].pmark_physics[j];
		}

		cout << "Enter grades for the subject Phychology :" << endl;
		for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//��������� ������ �� ��������
		{
			cin >> pname_of_student_new[i].pmark_psychology[j];
		}

		cout << "Enter grades for the subject Mathematics" << endl;
		for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//��������� ������ �� ��������
		{
			cin >> pname_of_student_new[i].pmark_mathematics[j];
		}

		cout << "Enter grades for the subject Geography :" << endl;
		for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//��������� ������ �� ��������
		{
			cin >> pname_of_student_new[i].pmark_geography[j];
		}

		cout << "Enter grades for the subject English :" << endl;
		for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//��������� ������ �� ��������
		{
			cin >> pname_of_student_new[i].pmark_english[j];
		}

		cout << "Enter grades for the subject History :" << endl;
		for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//��������� ������ �� ��������
		{
			cin >> pname_of_student_new[i].pmark_history[j];
		}
	}

	cout << "New student list :" << endl;
	for (int i = 0; i < (size + answer2); i++) //����� ����� ��������
	{
		cout << pname_of_student_new[i].pname << endl;
	}

	//delete[]pname_of_student;

	end(pname_of_student, size);
}

void remove_students(Group* pname_of_student, const int size) //��������
{
	for (int i = 0; i < size; i++) //�������� ���������� ��������
	{
		cout << pname_of_student[i].pname << endl;
	}

	while (true)
	{
		int answer;
		cout << "Enter a student's name which you want to delete : ";
		cin >> answer;

		if (answer > size || answer < 1) //�������� �� �����./������� �����
		{
			cout << "Error ,try again " << endl;
			//remove_students(pname_of_student, size);
		}
		else //���� �� ��
		{
			for (int i = answer - 1; i < size - 1; i++)
			{
				pname_of_student[i].pname = pname_of_student[i + 1].pname;

				pname_of_student[i].psecond_name = pname_of_student[i + 1].psecond_name;

				pname_of_student[i].age = pname_of_student[i + 1].age;

				pname_of_student[i].number_of_group = pname_of_student[i + 1].number_of_group;

				pname_of_student[i].ptelephone_number = pname_of_student[i + 1].ptelephone_number;

				for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//��������� ������ 
				{
					pname_of_student[i].pmark_physics[j] = pname_of_student[i + 1].pmark_physics[j];
				}

				for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//��������� ������ �� ��������
				{
					pname_of_student[i].pmark_psychology[j] = pname_of_student[i + 1].pmark_psychology[j];
				}

				for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//��������� ������ �� ��������
				{
					pname_of_student[i].pmark_mathematics[j] = pname_of_student[i + 1].pmark_mathematics[j];
				}

				for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//��������� ������ �� ��������
				{
					pname_of_student[i].pmark_geography[j] = pname_of_student[i + 1].pmark_geography[j];
				}

				for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//��������� ������ �� ��������
				{
					pname_of_student[i].pmark_english[j] = pname_of_student[i + 1].pmark_english[j];
				}

				for (int j = 0; j < pname_of_student[i].number_of_estimates; j++)//��������� ������ �� ��������
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
		case 1: // ����������
		{
			fill_out_student_list(pname_of_student, size);
			break;
		}
		case 2: // ��������� 
		{
			add_new_student(pname_of_student, size);
			break;
		}
		case 3: // �������
		{
			remove_students(pname_of_student, size);
			break;
		}
		case 4://�������
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
	//������� 1
	//Student student;
	//cin >> student.pfirst_name;
	//cin >> student.psecond_name;
	//cin >> student.age;
	//cin >> student.number_of_group;
	//
	//for (int i = 0; i < 15; i++)//��������� ������ 
	//{
	//	cin >> student.pmark_item1[i];
	//}	
	//
	//for (int i = 0; i < 15; i++)//��������� ������ 
	//{
	//	cin >> student.pmark_item2[i];
	//}
	//
	//for (int i = 0; i < 15; i++)//��������� ������ 
	//{
	//	cin >> student.pmark_item3[i];
	//}

	//for (int i = 0; i < 15; i++)//��������� ������ 
	//{
	//	cin >> student.pmark_item3[i];
	//}
	/////////////////////////////////////////////////////////////////////////////
	//������� 2

	//setlocale(LC_ALL, "Russian");// ��� 2-�� �������
	//
	//Holidays day;

	//cout << day.Feast_of_St_Patrick << endl;
	//cout << day.Nativity << endl;
	//cout << day.New_Year << endl;
	//cout << day.St_Nicolas_day << endl;
	//cout << day.Thanksgiving_Day << endl;
	//cout << day.Valentines_Day << endl;

	/////////////////////////////////////////////////////////////////////////////
	//������� 3

	unsigned size;
	cout << "Enter the size of the student journal :";
	cin >> size;
	Group* pname_of_student = new  Group[size];
	journal_of_students(pname_of_student, size);
	system("pause");
	return 0;
}












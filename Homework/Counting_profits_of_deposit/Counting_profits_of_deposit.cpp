#include<iostream>

using std::cout;
using std::cint;
using std::endl;

int main()
{
	setlocale(LC_ALL, "rus");
	const double PROCENT_IN_YEAR = 0.05;
	int sum_deposit;
	int koll_months;
	double procent_in_one_month;
	double procent_all_months;

	cout << " ââåäèòå ñóìó äåïîçèòà  : " << endl;
	cin >> sum_deposit;
	cout << "ââåäèòå êîëè÷åñòâî ìåñÿöåâ : " << endl;
	cin >> koll_months;

	procent_in_one_month = sum_deposit * (PROCENT_IN_YEAR) / 365 * 30;

	cout <<"ïðèáûëü â ìåñÿö ñîñòîâëÿåò : "<< procent_in_one_month << endl;

	procent_all_months = koll_months * procent_in_one_month;

	
	cout << "ïðèáûëü çà âñå ìåñÿöû ñîñòîâëÿåò : " << procent_all_months << endl;

	
	cout << "èòîãî âûõîæèò : " <<procent_all_months + sum_deposit;

    
	system("pause");
}

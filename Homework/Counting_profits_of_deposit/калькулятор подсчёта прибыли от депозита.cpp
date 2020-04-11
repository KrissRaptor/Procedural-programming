#include<iostream>

using namespace std;



int main()
{
	setlocale(LC_ALL, "rus");
	const double PROCENT_IN_YEAR = 0.05;
	int sum_deposit;
	int koll_months;
	double procent_in_one_month;
	double procent_all_months;

	cout << " введите суму депозита  : " << endl;
	cin >> sum_deposit;
	cout << "введите количество мес€цев : " << endl;
	cin >> koll_months;

	procent_in_one_month = sum_deposit * (PROCENT_IN_YEAR) / 365 * 30;

	cout <<"прибыль в мес€ц состовл€ет : "<< procent_in_one_month << endl;

	procent_all_months = koll_months * procent_in_one_month;

	
	cout << "прибыль за все мес€цы состовл€ет : " << procent_all_months << endl;

	
	cout << "итого выхожит : " <<procent_all_months + sum_deposit;

    
	system("pause");
}
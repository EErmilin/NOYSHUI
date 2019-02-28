#include <iostream>
using namespace std;

//Класс датчика температуры и влажности
class temps
{
private:
	int temp;
	int min;
	int max;
public:
	void set_min_temp(int received_min_temp) // Ввод минимального значения температуры
	{
		min = received_min_temp;
	}

	void set_max_temp(int received_max_temp) // Ввод максимального значения температуры
	{
		max = received_max_temp;
	}

	void set_temp(int received_temp) 
	{
		temp = received_temp;
	}

	void print() {
		cout << "Реальная температура: " << temp << endl;
		cout << "Минимальная допустимая температура: " << min << endl;
		cout << "Максимальная допустимая температура: " << max << endl;
	}
};

//Класс датчика освещённости
class light
{
public:
	int min;
	int max;

	void set_min(int received_min_temp) // Ввод минимального значения температуры
	{
		min = received_min_temp;
	}

	void set_max(int received_max_temp) // Ввод максимального значения температуры
	{
		max = received_max_temp;
	}
	void print() {
		cout << "Минимальная допустимая освещенность:" << min << endl;
		cout << "Максимальная допустимая освещенность: " << max << endl;
	}
};

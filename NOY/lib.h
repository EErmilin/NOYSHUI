#include <iostream>
using namespace std;
//Класс датчика температуры и влажности
class temps
{
public:
	int min_temp;
	int max_temp;
	int min_light;
	int max_light;

	void set_min_temp(int received_min_temp) // Ввод минимального значения температуры
	{
		min_temp = received_min_temp;
	}

	void set_max_temp(int received_max_temp) // Ввод максимальногшо значения температуры
	{
		max_temp = received_max_temp;
	}
	void print() {
		cout << "Минимальная допустимая температура: " << min_temp << endl;
		cout << "Максимальная допустимая температура: " << max_temp << endl;
	}
	void set_min_light(int received_min_light) // Ввод минимального значения температуры
	{
		min_light = received_min_light;
	}

	void set_max_light(int received_max_light) // Ввод максимальногшо значения температуры
	{
		max_light = received_max_light;
	}
	void print2() {
		cout << "Минимальная допустимая освещённость: " << min_light << endl;
		cout << "Максимальная допустимая освещённость: " << max_light << endl;
	}
};

//Класс датчика освещённости

#include <iostream>
using namespace std;
//����� ������� ����������� � ���������
class temps
{
public:
	int min_temp;
	int max_temp;
	int min_light;
	int max_light;

	void set_min_temp(int received_min_temp) // ���� ������������ �������� �����������
	{
		min_temp = received_min_temp;
	}

	void set_max_temp(int received_max_temp) // ���� �������������� �������� �����������
	{
		max_temp = received_max_temp;
	}
	void print() {
		cout << "����������� ���������� �����������: " << min_temp << endl;
		cout << "������������ ���������� �����������: " << max_temp << endl;
	}
	void set_min_light(int received_min_light) // ���� ������������ �������� �����������
	{
		min_light = received_min_light;
	}

	void set_max_light(int received_max_light) // ���� �������������� �������� �����������
	{
		max_light = received_max_light;
	}
	void print2() {
		cout << "����������� ���������� ������������: " << min_light << endl;
		cout << "������������ ���������� ������������: " << max_light << endl;
	}
};

//����� ������� ������������

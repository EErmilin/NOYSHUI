#include <iostream>
using namespace std;

//����� ������� ����������� � ���������
class temps
{
private:
	int temp;
	int min;
	int max;
public:
	void set_min_temp(int received_min_temp) // ���� ������������ �������� �����������
	{
		min = received_min_temp;
	}

	void set_max_temp(int received_max_temp) // ���� ������������� �������� �����������
	{
		max = received_max_temp;
	}

	void set_temp(int received_temp) 
	{
		temp = received_temp;
	}

	void print() {
		cout << "�������� �����������: " << temp << endl;
		cout << "����������� ���������� �����������: " << min << endl;
		cout << "������������ ���������� �����������: " << max << endl;
	}
};

//����� ������� ������������
class light
{
public:
	int min;
	int max;

	void set_min(int received_min_temp) // ���� ������������ �������� �����������
	{
		min = received_min_temp;
	}

	void set_max(int received_max_temp) // ���� ������������� �������� �����������
	{
		max = received_max_temp;
	}
	void print() {
		cout << "����������� ���������� ������������:" << min << endl;
		cout << "������������ ���������� ������������: " << max << endl;
	}
};

#include <iostream>
#include <string>
#include <windows.h>
#include "lib.h"
using namespace std;
void ReadCOM();
void ReadCOM2();
int k = 0;
HANDLE hSerial;
temps a;

int main() {
	setlocale(LC_ALL, "Russian");
	LPCTSTR sPortName = L"COM5"; //!!!������� ����!!!
	hSerial = ::CreateFile(sPortName, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	DCB dcbSerialParams = { 0 };
	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

	if (!SetCommState(hSerial, &dcbSerialParams))
	{
		cout << "error setting serial port state\n";
	}
	if (!GetCommState(hSerial, &dcbSerialParams))
	{
		cout << "getting state error\n";
	}
	dcbSerialParams.BaudRate = CBR_9600;
	dcbSerialParams.ByteSize = 8;
	dcbSerialParams.StopBits = ONESTOPBIT;
	dcbSerialParams.Parity = NOPARITY;
	
	int min_t = 0;
	int max_t = 0;
	cout << "������� ����������� �����������" << endl;
	cin >> min_t;
	a.set_min_temp(min_t);
	cout << "������� ������������ �����������" << endl;
	cin >> max_t;
	a.set_max_temp(max_t);
	/*int min_l = 0;
	int max_l = 0;
	cout << "������� ����������� ������������" << endl;
	cin >> min_l;
	a.set_min_light(min_l);
	cout << "������� ������������ ������������" << endl;
	cin >> max_l;
	a.set_max_light(max_l);*/
	ReadCOM();

	cout << endl;
	return 0;
	}

void ReadCOM()
{
	DWORD iSize;
	char sReceivedChar;
	while (true)
	{
		ReadFile(hSerial, &sReceivedChar, 1, &iSize, 0);  // �������� 1 ����
		if (iSize > 0)   // ���� ���-�� �������, �������
			while (1)
			{

					cout  << sReceivedChar << endl;
			}
	}
}
	void ReadCOM2()
	{
		DWORD iSize2;
		char sReceivedChar2;
		while (true)
		{
			ReadFile(hSerial, &sReceivedChar2, 1, &iSize2, 0);  // �������� 1 ����
			if (iSize2 > 0)   // ���� ���-�� �������, �������
				while (1)
				{
					if (sReceivedChar2 > a.min_light && sReceivedChar2 < a.max_light)

						cout << "������������: " << sReceivedChar2 << endl;

					else

						cout << "������������ !�� � �����!: " << sReceivedChar2 << endl;

				}
		}
	}
#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include "lib.h"
#include <conio.h>
#include <thread>

using namespace std;

void tempFunction();

HANDLE hSerial;
temps a;


int main() {
	setlocale(LC_ALL, "Russian");
	LPCTSTR sPortName = L"COM7"; 
	hSerial = ::CreateFile(sPortName, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	if (hSerial == INVALID_HANDLE_VALUE)
	{
		if (GetLastError() == ERROR_FILE_NOT_FOUND)
		{
			cout << "serial port does not exist.\n";
		}
		cout << "some other error occurred.\n";
	}
	DCB dcbSerialParams = { 0 };
	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
	if (!GetCommState(hSerial, &dcbSerialParams))
	{
		cout << "getting state error\n";
	}
	dcbSerialParams.BaudRate = CBR_9600;
	dcbSerialParams.ByteSize = 8;
	dcbSerialParams.StopBits = ONESTOPBIT;
	dcbSerialParams.Parity = NOPARITY;
	if (!SetCommState(hSerial, &dcbSerialParams))
	{
		cout << "error setting serial port state\n";
	}
	int tmp = 0;
	
menu:
	system("cls");
	cout << "����:" << endl;
	cout << "1. ������ �����������" << endl;
	cout << "2. ������ ���������" << endl;
	cout << "����: "; 
	cin >> tmp;
	switch (tmp)
	{
	case 1:
	menu_temp:
		system("cls");
		cout << "������ �����������:" << endl;
		cout << "1. ������ ������� �����������" << endl;
		cout << "2. ������� ������ �����������" << endl;
		cout << "3. ��������� � ������� ����" << endl;
		cout << "����: ";
		cin >> tmp;
		switch (tmp)
		{
		case 1:
			system("cls");
			cout << "������� ����������� �����������" << endl;
			cin >> tmp;
			a.set_min_temp(tmp);
			cout << "������� ������������ �����������" << endl;
			cin >> tmp;
			a.set_max_temp(tmp);
			system("cls");
			cout << "������� ����������� �����������." << endl;
			cout << "������� ����� ������� ��� �������� � ����." << endl;
			_getch();
			goto menu_temp;
			break;
		case 2:
			system("cls");
			tempFunction();
			cout << "������� ����� ������� ��� �������� � ����." << endl;
			_getch();
			goto menu_temp;
		break;

		case 3:
			
			goto menu;
			break;

		default:
			goto menu_temp;
			break;
		}
	break;

	case 2:
		
		break;

	default:
		goto menu;
		break;
	}
	return 0;
	}




void tempFunction()
{
	char data[] = "temp";
	DWORD dwSize = sizeof(data);
	DWORD dwBytesWritten;
	BOOL iRet = WriteFile(hSerial, data, dwSize, &dwBytesWritten, NULL);
	DWORD iSize;
	int sReceivedChar = 0;
	while (true) {
		ReadFile(hSerial, &sReceivedChar, 1, &iSize, 0);
		if (iSize > 0)   // ���� ���-�� �������, �������
			cout << "�������� ������: " << sReceivedChar << endl;
		else
			cout << "�� ������� ������� ������" << endl;
	}
}
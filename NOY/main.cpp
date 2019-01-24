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
	cout << "Меню:" << endl;
	cout << "1. Датчик температуры" << endl;
	cout << "2. Датчик влажности" << endl;
	cout << "Ввод: "; 
	cin >> tmp;
	switch (tmp)
	{
	case 1:
	menu_temp:
		system("cls");
		cout << "Датчик температуры:" << endl;
		cout << "1. Задать граници температуры" << endl;
		cout << "2. Вывести данные температуры" << endl;
		cout << "3. Вернуться в главное меню" << endl;
		cout << "Ввод: ";
		cin >> tmp;
		switch (tmp)
		{
		case 1:
			system("cls");
			cout << "Введите минимальную температуру" << endl;
			cin >> tmp;
			a.set_min_temp(tmp);
			cout << "Введите максимальную температуру" << endl;
			cin >> tmp;
			a.set_max_temp(tmp);
			system("cls");
			cout << "Граници температуры установлены." << endl;
			cout << "Нажмите любую клавишу для возврата в меню." << endl;
			_getch();
			goto menu_temp;
			break;
		case 2:
			system("cls");
			tempFunction();
			cout << "Нажмите любую клавишу для возврата в меню." << endl;
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
		if (iSize > 0)   // если что-то принято, выводим
			cout << "Принятые данные: " << sReceivedChar << endl;
		else
			cout << "Не удалось принять данные" << endl;
	}
}
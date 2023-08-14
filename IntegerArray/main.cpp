#include <iostream>
#include "IntegerArray.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");


		cout << "������� ���������(10): ";
		IntegerArray arr (10);
		for (int i = 0; i < 10; ++i)
		{
			arr[i] = i+1;
			std::cout << arr[i] << " ";
		}
		cout << endl;

		cout << "�������� ���������(10): ";
		IntegerArray b{ arr };
		for (int i = 0; i < 10; ++i)
		cout << b[i] << " ";
		cout << endl;

		cout << "�������� ������ � �������� ���������� �� �������(5): " << arr[5] << endl;

		cout << "�������� ������ ���������� (10 �� 8): ";
		arr.resize(8);
		for (int i = 0; i < 8; ++i)
			cout << arr[i] << " ";
		cout << endl;

		cout << "��������� ������� (5) � ��������� - � ������: ";
		arr.insertAtBeginning(5);
		for (int i = 0; i < 9; ++i)
			cout << arr[i] << " ";
		cout << endl;

		cout << "��������� ������� (6) � ��������� - � �����: ";
		arr.insertAtEnd(6);
		for (int i = 0; i < 10; ++i)
			cout << arr[i] << " ";
		cout << endl;

		cout << "������� ������� ��� �������� (6) �� ����������:";
		arr.remove(6);
		for (int i = 0; i < 9; ++i)
			cout << arr[i] << " ";
		cout << endl;

		cout << "�������� ����������:\n";
		cout << "�������� ������������� ������� ���������� (-5): ";
		try
		{
			IntegerArray arrErr(-5);
		}
		catch (const char* exception)
		{
			cout << "Exception: " << exception;
		}
		cout << endl;
		cout << "����� �� ������� ���������� (12): ";
		try
		{
			arr.insert(5, 12);
		}
		catch (const char* exception)
		{
			cout << "Exception: " << exception;
		}
		cout << endl; 

		cout << "����� � ���������� �� �������� (8), ��������� � �������: ";
		try
		{
			cout << arr.getSearch(8);
		}
		catch (const char* exception)
		{
			cout << "Exception: " << exception;
		}
		cout << endl;

		cout << "����� � ���������� �� �������� (25), �������� ����������, ��������� � �������: ";
		try
		{
			cout << arr.getSearch(25);
		}
		catch (const char* exception)
		{
			cout << "Exception: " << exception;
		}
		cout << endl;


	return 0;
}
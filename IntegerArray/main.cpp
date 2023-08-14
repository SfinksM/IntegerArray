#include <iostream>
#include "IntegerArray.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");


		cout << "Создаем контейнер(10): ";
		IntegerArray arr (10);
		for (int i = 0; i < 10; ++i)
		{
			arr[i] = i+1;
			std::cout << arr[i] << " ";
		}
		cout << endl;

		cout << "Копируем контейнер(10): ";
		IntegerArray b{ arr };
		for (int i = 0; i < 10; ++i)
		cout << b[i] << " ";
		cout << endl;

		cout << "Получаем доступ к элементу контейнера по индуксу(5): " << arr[5] << endl;

		cout << "Изменяем размер контейнера (10 на 8): ";
		arr.resize(8);
		for (int i = 0; i < 8; ++i)
			cout << arr[i] << " ";
		cout << endl;

		cout << "Вставляем элемент (5) в контейнер - в начало: ";
		arr.insertAtBeginning(5);
		for (int i = 0; i < 9; ++i)
			cout << arr[i] << " ";
		cout << endl;

		cout << "Вставляем элемент (6) в контейнер - в конец: ";
		arr.insertAtEnd(6);
		for (int i = 0; i < 10; ++i)
			cout << arr[i] << " ";
		cout << endl;

		cout << "Удаляем элемент под индексом (6) из контейнера:";
		arr.remove(6);
		for (int i = 0; i < 9; ++i)
			cout << arr[i] << " ";
		cout << endl;

		cout << "Проверка исключений:\n";
		cout << "Создание неправильного размера контейнера (-5): ";
		try
		{
			IntegerArray arrErr(-5);
		}
		catch (const char* exception)
		{
			cout << "Exception: " << exception;
		}
		cout << endl;
		cout << "Выход за границы контейнера (12): ";
		try
		{
			arr.insert(5, 12);
		}
		catch (const char* exception)
		{
			cout << "Exception: " << exception;
		}
		cout << endl; 

		cout << "Поиск в контейнере по значению (8), находится в индексе: ";
		try
		{
			cout << arr.getSearch(8);
		}
		catch (const char* exception)
		{
			cout << "Exception: " << exception;
		}
		cout << endl;

		cout << "Поиск в контейнере по значению (25), проверка исключения, находится в индексе: ";
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
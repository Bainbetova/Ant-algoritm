/* Файл main.cpp */
/* ОТИ МИФИ */
/* 1ПО-24Д */
/* Баинбетова Владлена Владиславна */
/* Алгоритмы и структура данных */
/* Программа Ant_alg */
/* Основной модуль */
/* 19.05.2016 */

/* Подключение библиотек */
#include "Ant_alg.h"
#include <locale>
#include <stdlib.h>
#include <iostream>
#include <malloc.h>
#include <conio.h>

/* Подключение пространства имен */
using namespace std;

/* Функция main					                                                  */
/* Назначение:                                                                    */
/*      Главная функция									                          */
/* Входные данные:																  */
/*		отсутствуют																  */
/* Выходные данные:                                                               */
/*		отсутсвтуют																  */
/* Возвращаемое значение:                                                         */
/*      отсутствует                                                               */
void main() 
{
	setlocale(LC_ALL, ".1251");
	/* Объявление и инициализация переменных */
	double **D = NULL;
	int size = 0, city_1 = 0, city_2 = 0;
	char name[SIZE];
	
	/* Запрос пути к файлу */
	printf("Введите путь файла: ");
	scanf_s("%s", name, SIZE);

	/* Вызов функции readSize */
	size = ReadSize(D, name, &size);
	D = new double*[size];

	/* Создание двумерного массива */
	for (int t = 0; t < size; ++t) {
		D[t] = new double[size];
	}

	/* Обнуление полученного массива */
	for (int k = 0; k < size; k++) {
		for (int r = 0; r < size; r++) {
			D[k][r] = 0.0;
		}
	}

	/* Заполнение массива D */
	ReadMatrix(D, name, &size);

	/* Инициализация начальной и конечной точек */ 
	while (city_1 < 1 || city_1 > size) {
		cout << "Введите начальную вершину от 1 до " << size << ": "; 
		cin >> city_1;
	}
	while (city_2 < 1 || city_2 > size || city_2 == city_1) {
		cout << "Введите конечную вершину от 1 до " << size << ", исключая " << city_1 << ": ";
		cin >> city_2;
	}
	
	/* Использование муравьиного алгоритма */
	ANT_TYPE way = AntColony(D, size, --city_1, --city_2);
	
	/* Вывод результата на экран */
	PrintResult(way);

	/* Задержка сообщения на экране */
	_getch();

	/* Освобождение памяти */
	delete[] D;

	return;
}
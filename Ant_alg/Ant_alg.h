#pragma once
/* Файл Ant_alg.h */
/* ОТИ МИФИ */
/* 1ПО-24Д */
/* Баинбетова Владлена Владиславна */
/* Алгоритмы и структура данных */
/* Программа Ant_alg */
/* Заголовочный файл */
/* 19.05.2016 */

/* Подключение модуля */
#include "Ant_alg.h"

/* Объявление констант */
#define ALPHA	1			// вес фермента
#define BETA	3			// коэффициент эвристики
#define T_MAX	100			// время жизни колонии
#define M		20			// количество муравьев в колонии
#define p		0.5			// коэффициент испарения феромона
#define SIZE 1000000		// максимальная длина названия файла

/* Структура МУРАВЕЙ */
struct ANT_TYPE {
	int number; // количество вершин
	double length; // длина
	int *array; // массив вершин
};

/* Прототипы функций */
int ReadSize(double**, char[SIZE], int *);
int ReadMatrix(double**, char[SIZE], int *);
double Probability(int, ANT_TYPE, double **, double **, int);
void InitializationAnts(ANT_TYPE [M], int, int);
void InitializationLength(double **, double **, int);
void GenerationPheromon(double **, int);
void Pheromon(ANT_TYPE [M], double, double **, int);
ANT_TYPE AntColony(double **, int, int, int);
void PrintResult(ANT_TYPE);
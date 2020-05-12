/* ���� main.cpp */
/* ��� ���� */
/* 1��-24� */
/* ���������� �������� ����������� */
/* ��������� � ��������� ������ */
/* ��������� Ant_alg */
/* �������� ������ */
/* 19.05.2016 */

/* ����������� ��������� */
#include "Ant_alg.h"
#include <locale>
#include <stdlib.h>
#include <iostream>
#include <malloc.h>
#include <conio.h>

/* ����������� ������������ ���� */
using namespace std;

/* ������� main					                                                  */
/* ����������:                                                                    */
/*      ������� �������									                          */
/* ������� ������:																  */
/*		�����������																  */
/* �������� ������:                                                               */
/*		�����������																  */
/* ������������ ��������:                                                         */
/*      �����������                                                               */
void main() 
{
	setlocale(LC_ALL, ".1251");
	/* ���������� � ������������� ���������� */
	double **D = NULL;
	int size = 0, city_1 = 0, city_2 = 0;
	char name[SIZE];
	
	/* ������ ���� � ����� */
	printf("������� ���� �����: ");
	scanf_s("%s", name, SIZE);

	/* ����� ������� readSize */
	size = ReadSize(D, name, &size);
	D = new double*[size];

	/* �������� ���������� ������� */
	for (int t = 0; t < size; ++t) {
		D[t] = new double[size];
	}

	/* ��������� ����������� ������� */
	for (int k = 0; k < size; k++) {
		for (int r = 0; r < size; r++) {
			D[k][r] = 0.0;
		}
	}

	/* ���������� ������� D */
	ReadMatrix(D, name, &size);

	/* ������������� ��������� � �������� ����� */ 
	while (city_1 < 1 || city_1 > size) {
		cout << "������� ��������� ������� �� 1 �� " << size << ": "; 
		cin >> city_1;
	}
	while (city_2 < 1 || city_2 > size || city_2 == city_1) {
		cout << "������� �������� ������� �� 1 �� " << size << ", �������� " << city_1 << ": ";
		cin >> city_2;
	}
	
	/* ������������� ����������� ��������� */
	ANT_TYPE way = AntColony(D, size, --city_1, --city_2);
	
	/* ����� ���������� �� ����� */
	PrintResult(way);

	/* �������� ��������� �� ������ */
	_getch();

	/* ������������ ������ */
	delete[] D;

	return;
}
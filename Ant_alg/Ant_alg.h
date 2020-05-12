#pragma once
/* ���� Ant_alg.h */
/* ��� ���� */
/* 1��-24� */
/* ���������� �������� ����������� */
/* ��������� � ��������� ������ */
/* ��������� Ant_alg */
/* ������������ ���� */
/* 19.05.2016 */

/* ����������� ������ */
#include "Ant_alg.h"

/* ���������� �������� */
#define ALPHA	1			// ��� ��������
#define BETA	3			// ����������� ���������
#define T_MAX	100			// ����� ����� �������
#define M		20			// ���������� �������� � �������
#define p		0.5			// ����������� ��������� ��������
#define SIZE 1000000		// ������������ ����� �������� �����

/* ��������� ������� */
struct ANT_TYPE {
	int number; // ���������� ������
	double length; // �����
	int *array; // ������ ������
};

/* ��������� ������� */
int ReadSize(double**, char[SIZE], int *);
int ReadMatrix(double**, char[SIZE], int *);
double Probability(int, ANT_TYPE, double **, double **, int);
void InitializationAnts(ANT_TYPE [M], int, int);
void InitializationLength(double **, double **, int);
void GenerationPheromon(double **, int);
void Pheromon(ANT_TYPE [M], double, double **, int);
ANT_TYPE AntColony(double **, int, int, int);
void PrintResult(ANT_TYPE);
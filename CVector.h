#pragma once
#include <iostream>
using namespace std;
class CVector
{
protected:
	int size;
	double* data;
private:
	void init();
public:
	// очистка
	void clear();
	// Конструктор инициализации
	CVector(int size = 0, const double* NewData = nullptr);
	// Копия конструктор
	CVector(const CVector& vec);
	// Деструктор
	~CVector();
	// Копирование объект
	void copyobj(const CVector& vec);
	// Копирование размер и данные
	int copy(const int New_size, const double* New_data);
	// Вывод
	void print();
	// прибавление
	void add(CVector& vec);
	//вычитание
	void subtract(CVector& vec);
	//модуль
	double length();
	// скалярное произведение
	friend double scalar_product(CVector& vec1, CVector& vec2);
	// сумма
	friend CVector sum(CVector& vec1, CVector& vec2);
	// разность
	friend CVector diff(CVector& vec1, CVector& vec2);
};
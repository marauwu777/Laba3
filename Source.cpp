#include <iostream>
#include <vector>
#include "CVector.h"
#include <cmath>
using namespace std;
void CVector::init()
{
	size = 0;
	data = nullptr;
}

// очистка
void CVector::clear() {
	delete[] data;
	init();
}
// Копирование объект
void CVector::copyobj(const CVector& vec) {
	if (this == &vec) {
		return;
	}
	copy(vec.size, vec.data);
}
// копирование размер и данные
int CVector::copy(const int New_size, const double* New_data) {
	if (data != New_data) {
		clear();
		data = new double[New_size];
		if (data) {
			size = New_size;
			for (int i = 0; i < size; i++) {
				data[i] = New_data[i];
			}
		}
	}
	return New_size;
}
// Конструктор инициализации
CVector::CVector(const int NewSize, const double* NewData) {
	init();
	copy(NewSize, NewData);

}
// Копия конструктор
CVector::CVector(const CVector& vec) {
	init();
	copyobj(vec);
}
// Деструктор
CVector::~CVector() {
	clear();
}
// Вывод
void CVector::print() {
	cout << "Num: " << size << " Data: ";
	if (data) {
		for (int i = 0; i < size; i++) {
			cout << data[i] << " ";
		}
	}
	else {
		cout << "NULL";
	}
	cout << endl;
}
// скалярное произведение
double scalar_product(CVector& vec1, CVector& vec2) {
	double result = 0;
	int s = min(vec1.size, vec2.size);
	for (int i = 0; i < s; i++) {
		result += vec1.data[i] * vec2.data[i];
	}
	return result;
	
}

// модуль
double CVector::length() {
	return(sqrt(scalar_product(*this, *this)));
}
// сумма
CVector sum(CVector& vec1, CVector& vec2) {
	int smin = min(vec1.size, vec2.size);
	int smax = max(vec1.size, vec2.size);
	double* resultData = new double[smax];

	for (int i = 0; i < smin; i++) {
		resultData[i] = vec1.data[i] + vec2.data[i];
	}
	for (int i = smin; i < vec1.size; i++) {
		resultData[i] = vec1.data[i];
	}
	for (int i = smin; i < vec2.size; i++) {
		resultData[i] = vec2.data[i];
	}
	CVector result;
	result.size = smax;
	result.data = resultData;
	return result;
}
// разность
CVector diff(CVector& vec1, CVector& vec2) {
	int smin = min(vec1.size, vec2.size);
	int smax = max(vec1.size, vec2.size);
	double* resultData = new double[smax];

	for (int i = 0; i < smin; i++) {
		resultData[i] = (vec1.data[i] - vec2.data[i]);
	}
	for (int i = smin; i < vec1.size; i++) {
		resultData[i] = vec1.data[i];
	}
	for (int i = smin; i < vec2.size; i++) {
		resultData[i] = -vec2.data[i];
	}
	CVector result;
	result.size = smax;
	result.data = resultData;
	return result;
}

// прибавление
void CVector::add(CVector& vec) {
	this->copyobj(sum(*this, vec));
}
// вычитание
void CVector::subtract(CVector& vec) {
	this->copyobj(diff(*this, vec));
}

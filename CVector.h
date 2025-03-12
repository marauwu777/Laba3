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
	// �������
	void clear();
	// ����������� �������������
	CVector(int size = 0, const double* NewData = nullptr);
	// ����� �����������
	CVector(const CVector& vec);
	// ����������
	~CVector();
	// ����������� ������
	void copyobj(const CVector& vec);
	// ����������� ������ � ������
	int copy(const int New_size, const double* New_data);
	// �����
	void print();
	// �����������
	void add(CVector& vec);
	//���������
	void subtract(CVector& vec);
	//������
	double length();
	// ��������� ������������
	friend double scalar_product(CVector& vec1, CVector& vec2);
	// �����
	friend CVector sum(CVector& vec1, CVector& vec2);
	// ��������
	friend CVector diff(CVector& vec1, CVector& vec2);
};
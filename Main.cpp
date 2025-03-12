#include <iostream>
#include "CVector.h"

using namespace std;

int main() {
    int size1, size2;
    cout << "Enter vec1 size - ";
    cin >> size1;
    cout << endl;
    cout << "Enter vec2 size - ";
    cin >> size2;
    cout << endl;
    double* arr1 = new double[size1];
    double* arr2 = new double[size2];
    cout << "Enter vec1 data: " << endl;
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }
    cout << "Enter vec2 data: " << endl;
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }
    CVector vec1(size1, arr1);
    CVector vec2(size2, arr2);
    cout << "Check scalar func (vec1 * vec2) = " << scalar_product(vec1, vec2);
    cout << endl;
    cout << "Check length func vec1 - " << vec1.length() << " vec2 - " << vec2.length() << endl;
    CVector vec3 = sum(vec1, vec2);
    cout << "Check sum func (vec1 + vec2): " << endl;
    vec3.print();
    CVector vec4 = diff(vec1, vec2);
    cout << "Check diff func (vec1 - vec2): " << endl;
    vec4.print();
    vec1.add(vec2);
    cout << "Check add func (vec1 += vec2) " << endl;
    vec1.print();
    vec1.copy(size1, arr1);
    vec1.subtract(vec2);
    cout << "Check subtract func (vec1 -= vec2) " << endl;
    vec1.print();
    delete[] arr1;
    delete[] arr2;
    return 0;
}

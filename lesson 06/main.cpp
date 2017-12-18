#include <iostream>
#include "m1.h"

template<typename T>
Matrix<T>::Matrix(int size_1, int size_2) : _size_1(size_1),_size_2(size_2){
	_mat = new T*[_size_1];
	for (int i = 0; i < _size_1; i++) {
		_mat[i] = new T[_size_2];
	}
}
template<typename T>
int Matrix<T>::GetSize_1() const {
	return _size_1;
}
template<typename T>
int Matrix<T>::GetSize_2() const {
	return _size_2;
}
template<typename T>
void Matrix<T>::SetSize_1(int size_1) {
	_size_1 = size_1;
}
template<typename T>
void Matrix<T>::SetSize_2(int size_2) {
	_size_2 = size_2;
}
template<typename T>
T Matrix<T>::GetElem(int i,int j) const {
	if (i <= _size_1 && j <= _size_2) {
		return _mat[i][j];
	}
	else {
		std::cout << "Error enter index" << std::endl;
	}
}
template<typename T>
void Matrix<T>::SetElem(int i, int j,T elem) {
	_mat[i][j] = elem;
}


template<typename T>
void Matrix<T>::ReSize(int size_1, int size_2) {
	//SetSize_1(size_1);
	//SetSize_2(size_2);
	T** _mat_2 = new T*[size_1];
	for (int i = 0; i < size_1; i++) {
		_mat_2[i] = new T[size_2];
	}
	for (int i = 0; i < _size_1; i++) {
		for (int j = 0; j < _size_2; j++) {
			_mat_2[i][j] = _mat[i][j];
		}
	}
	delete _mat;
	_mat = _mat_2;
	SetSize_1(size_1);
	SetSize_2(size_2);

}
template<typename T>
void  Matrix<T>::print()const {
	for (int i = 0; i < GetSize_1(); i++) {
		for (int j = 0; j < GetSize_2(); j++) {
			std::cout << GetElem(i, j) <<" ";
		}
		std::cout << std::endl;
	}
}

int main() {

	Matrix<int> m1(2, 2);
	m1.SetElem(0, 0, 5);
	m1.SetElem(0, 1, 6);
	m1.SetElem(1, 0, 7);
	m1.SetElem(1, 1, 8);
	std::cout << " matrix 1 :  "<< std::endl;
	m1.print();
	m1.ReSize(3, 3);
	m1.SetElem(2, 0, 3);
	m1.SetElem(2, 1, 1);
	m1.SetElem(2, 2, 2);
	m1.SetElem(1, 2, 11);
	m1.SetElem(0, 2, 13);
	std::cout << " matrix 2 :  " << std::endl;
	m1.print();
	system("Pause");
	return 0;
}
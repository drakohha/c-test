#include "m1.h"
#include <iostream>


template<typename T>
Vector<T>::Vector() {

}

template<typename T>
Vector<T>::Vector(int size) : _size(size) {
	_v = new T[size];
}

template<typename T>
Vector<T>::~Vector() {
	delete _v;
}

template<typename T>
int Vector<T>::GetSize() const {
	return _size;
}


template<typename T>
void Vector<T>::ReSize(int size) {
	_size = size;
	_v = new T[size];

}

template<typename T>
void Vector<T>::AddElem(int index, T elem) {
	if (index >= _size){
		ReSize(index);
	}
	_v[index] = elem;
}

template<typename T>
T Vector<T>::GetElem(int index) const {
	return _v[index];
}


template<typename T>
T Vector<T>::operator[](int index) const {
	return GetElem(index);
}


template<typename T>
void Vector<T>::DelElem(int index) {
	for (int i = index; i < _size-1; i++) {
		_v[i] = _v[i + 1];
	}
	ReSize(_size - 1);
}

int main() {

	Vector<int> v1;
	Vector<int> v2(5);
	int index = 6;
	v2.AddElem(1, 51);
	std::cout << v2[1] << std::endl;
	try {
		if (index >= v2.GetSize()) {
			throw "Error";
		}
		else {
			std::cout << v2.GetElem(index) << std::endl;
		}
	}
	catch (...) {
		std::cout << "Index enter error" << std::endl;
	}
	//std::cout << v2.GetElem(index) << std::endl;
	system("Pause");
	return 0;

}

#include <iostream>
#include <vector>
#include <string>
#include "m1.h"
template<typename T>
Array<T>::Array(){

}
template<typename T>
void Array<T>::SetSize(int size, int grow) {
	T *_mass = new T[size];
	_grow = grow;
	_size = size;
}

template<typename T>
int Array<T>::GetSize()const {
	return _size;
}
template<typename T>
int Array<T>::GetUpperBound()const {
	

	return _kol_size-1;
}
template<typename T>
void Array<T>::print()const {

	for (int i = 0; i < _kol_size; i++) {
		std::cout << _mass[i] << " ";
	}
	
}

template<typename T>
bool Array<T>::IsEmpty()const {
	if (GetSize() == 0){
		return true;
	}
	else {
		return 0;
	}
}

template<typename T>
void Array<T>::FreeExtra() {
	int tmp = GetUpperBound();
	T *_mass = new T[tmp];
	_size = tmp+1;
	
}
template<typename T>
void Array<T>::RemoveAll() {
	delete _mass;
	_size = 0;
	_kol_size = 0;
	_grow = 0;
}

template<typename T>
T Array<T>::GetAt(int indx)const {
	return _mass[indx];
}


template<typename T>
void Array<T>::SetAr(int indx,T& elem) {
	if (indx < size) {
		_mass[indx] = elem;
	}
}

template<typename T>
void Array<T>::Append(Array<T> const& r) {
	
	for (int i = 0; i < r._kol_size; i++) {
		Add(r._mass[i]);
		
	}
	
}
int main() {

	Array<int> a1;
	int t = 55;
	int t1=25;
	a1.Add(t);
	a1.Add(t1);
	std::cout << a1.GetSize() << std::endl;
	std::cout << a1.GetUpperBound() << std::endl;
	a1.print();
	a1.FreeExtra();
	std::cout << a1.GetSize() << std::endl;
	std::cout << a1.GetUpperBound() << std::endl;
	Array<int> a2;
	int t_2 = 21;
	int t_3 = 33;
	a2.Add(t_2);
	a2.Add(t_3);
	a1.Append(a2);
	a1.print();
	system("Pause");
	return 0;

}
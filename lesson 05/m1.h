#pragma once
#include <vector>
template<typename T>
class Array {
public:
	Array();
	int GetSize()const;
	void Add(T& t);
	int GetUpperBound()const;
	void print()const;
	bool IsEmpty()const;
	void SetSize(int i, int j);
	void FreeExtra();
	void RemoveAll();
	T GetAt(int indx)const;
	void SetAr(int indx,T& elem);
	void Append(Array<T> const& r);
private:
	int _grow = 5;
	int _size = 5;
	int _kol_size = 0;
	T *_mass= new T[_size+_grow];
};


template<typename T>
void Array<T>::Add(T& t) {
	int i = _kol_size;
	if (_kol_size >= _size) {
		T *_mass= new T[i+_grow];
	}
	
	_mass[i]=t;
	_kol_size++;
}
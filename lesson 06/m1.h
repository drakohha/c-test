#pragma once

template<typename T>
class Matrix {
public:
	Matrix(int size_1, int size_2);
	int GetSize_1() const;
	int GetSize_2() const;
	void SetSize_1(int size_1);
	void SetSize_2(int size_2);
	T GetElem(int i,int j) const;
	void SetElem(int i, int j,T elem);
	void ReSize(int size_1,int size_2);
	void print()const;

private:
	T * * _mat;
	int _size_1 = 5;
	int _size_2 = 5;
	
	
};
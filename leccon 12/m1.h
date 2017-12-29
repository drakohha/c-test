#pragma once
template<typename T>
class Vector {
public:
	Vector();
	Vector(int size);
	~Vector();
	int GetSize() const;
	void ReSize(int size);
	void AddElem(int index, T elem);
	void DelElem(int index);
	T operator[](int index) const;
	T GetElem(int index) const;
private:
	int* _v=nullptr;
	int _size;
};







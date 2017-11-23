#pragma once
#include <string>
#include <cstdint>


class Massiv{
	public:
		Massiv()=default;
		Massiv(int size);
		Massiv(Massiv& ms);
		~Massiv();
		int GetSize() const;
		bool Empty() const;
		int* operator[](int id);
		void SetValue(int x,int index);
		Massiv& operator=(Massiv& r);
		void DelValue(int index);
		void print(Massiv& ms);

	private:
		int* _ms=nullptr;
		int _size = 0;



};
	
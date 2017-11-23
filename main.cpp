#define _CRT_SECURE_NO_WARNINGS
#include "module_1.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>




Massiv::Massiv(Massiv& ms){
	
	
}

Massiv& Massiv::operator=(Massiv& r){
	delete _ms;
	_ms = new int[r._size];
	_size=r._size;
	memcpy(_ms,r._ms,r._size);
	return *this;
	
}

Massiv::Massiv(int size){
	_ms = new int[size];
	for (int i = 0; i < size; i++){
		_ms[i]=0;
	}
	_size=size;
}
Massiv::~Massiv(){
	delete _ms;
}

int Massiv::GetSize() const{
	return _size;
}

bool Massiv::Empty() const{
	if (_ms == nullptr){
		return true;
	}
	else{
		return false;
	}
}


void Massiv::SetValue(int x,int index){
	
	_ms[index]=x;
	
}

void Massiv::DelValue(int index){
	int* ms_2=new int[_size-1];
	int id=0;
	for (int i = 0; i < _size; i++){
		if (i != index){
			ms_2[id] = _ms[i];
			id++;
		}
	}
	_size--;
	delete _ms;
	_ms=ms_2;
	
	
}

void Massiv::print(Massiv& ms){
	for (int i = 0; i < _size; i++){
		std::cout << *ms[i] <<" ";
	}
	std::cout << "\n";
}

int* Massiv::operator[](int id){
	return (_ms + id);
}

int main(){

	Massiv m_1(5);
	m_1.SetValue(1, 1);
	m_1.SetValue(2, 2);
	m_1.SetValue(3, 3);
	m_1.SetValue(4, 4);
	m_1.SetValue(11, 0);
	std::cout << m_1.GetSize() << std::endl;
	std::cout << *m_1[0] << std::endl;
	m_1.print(m_1);
	
	m_1.DelValue(0);
	m_1.print(m_1);
	
	
	
	std::cin.get();
	system("Pasue");
	return 0;
}
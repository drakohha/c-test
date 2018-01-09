#include "m1.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>


//List::List() {
//
//}

List::~List() {
	for (int i = 0; i < _size; i++) {
		_sp.pop_back();
	}
}

TheList::TheList() {

}

TheList::TheList(std::string firm_name, std::string vladelec, int number, std::string adres, std::string rabota) :
	_firm_name(firm_name), _vladelec(vladelec), _number(number), _adres(adres), _rabota(rabota){
}


std::string TheList::GetFirm() const {
	return _firm_name;
}

void TheList::SetFirm(std::string firm_name) {
	_firm_name = firm_name;
}


std::string TheList::GetVlad() const {
	return _vladelec;
}
void TheList::SetVlad(std::string vladelec) {
	_vladelec = vladelec;
}
int TheList::GetNum() const {
	return _number;
}
void TheList::SetNum(int number) {
	_number = number;
}
std::string TheList::GetAdres() const {
	return _adres;
}
void TheList::SetAdres(std::string adres) {
	_adres = adres;
}
std::string TheList::GetRabota() const {
	return _rabota;
}
void TheList::SetRabota(std::string rabota) {
	_rabota = rabota;
}


void List::Out(int index) const{
	std::cout << _sp[index].GetFirm()<< " ";
	std::cout << _sp[index].GetVlad() << " ";
	std::cout << _sp[index].GetNum() << " ";
	std::cout << _sp[index].GetAdres() << " ";
	std::cout << _sp[index].GetRabota() << std::endl;
}

void List::Add(TheList const& sp) {
	_sp.push_back(sp);
	SetSize(GetSize() + 1);
}
void List::Dell(int index) {
	_sp.erase(_sp.begin() + index);
	SetSize(GetSize() - 1);
	
}
int List::FindFirm(std::string firm_name) {
	for (int i = 0; i < GetSize(); i++) {
		if (_sp[i].GetFirm() == firm_name) {
			return i;
		}
		else {
			throw std::exception("error");
			return 0;
		}
	}
	return 0;
}
int List::FindVladelec(std::string vladelec){
	for (int i = 0; i < GetSize(); i++) {
		if (_sp[i].GetVlad() == vladelec) {
			return i;
		}
		else {
			throw std::exception("error");
			return 0;
		}
	}
	return 0;
}
int List::FindNumber(int number){
	for (int i = 0; i < GetSize(); i++) {
		if (_sp[i].GetNum() == number) {
			return i;
		}
		else {
			throw std::exception("error");
			return 0;
		}
	}
	return 0;
}
int List::FindRabota(std::string rabota){
	for (int i = 0; i < GetSize(); i++) {
		if (_sp[i].GetRabota() == rabota) {
			return i;
		}
		else {
			throw std::exception("error");
			return 0;
		}
	}
	return 0;
}


int  List::FindAdres(std::string adres) {
	for (int i = 0; i < GetSize(); i++) {
		if (_sp[i].GetAdres() == adres) {
			return i;
		}
		else {
			throw std::exception("error");
			return 0;
		}
	}
	return 0;
}

void List::SetSize(int size){
	_size = size;
}
int List::GetSize() const{
	return _size;
}






int main() {
	setlocale(LC_ALL, "rus");
	List s_1;
	TheList l_1("adidas", "major", 123456789, "street 32", "menejer");
	
	s_1.Add(l_1);
	try {
		int ind = s_1.FindFirm("adidas");
		s_1.Out(ind);
	}
	catch (...) {
		std::cout << "Not found !" << std::endl;
	}



	// test test test

	std::ofstream fs("test.txt"); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
	fs << "Работа с файлами в С++"; // запись строки в файл
	fs.close(); // закрываем файл
	std::ifstream fs_1 ("test.txt") ;
	char buff[50];
	fs_1.getline(buff, 50);



	int flag_menu = 0;
	std::cout << "vibirete deistvie : 1-otkrut, 2-naiti,3-dobavit,4-delete,5-zakrut" << std::endl;
	do {
		std::cin >> flag_menu;
		if (flag_menu == 1) {
			std::cout << buff;
		}
		if (flag_menu == 2) {

		}
	} while (flag_menu != 0);


	system("Pause");
	return 0;
}
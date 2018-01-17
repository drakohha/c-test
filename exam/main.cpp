#include "m_1.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>


Acsess::Acsess(){}
void Acsess::Load(Acsess& ac_1) {
	
	std::ifstream f_1("file_1.txt");
	std::string login;
	std::string Password;
	
	while (!f_1.eof()) {
		f_1 >> login;
		f_1 >> Password;
		ac_1.Add(login, Password);
	}
	
	f_1.close();
}
void Acsess::Save(Acsess const& ac_1){
	std::ofstream f_2("file_1.txt");
	for (auto itr = this->_ac.begin(); itr != this->_ac.end(); ++itr) {
		f_2 << itr->first <<" ";
		f_2 << itr->second << std::endl;
	}
	f_2.close();
}
void Acsess::Add(std::string login, std::string Password) {
	_ac[login] = Password;
}


int Acsess::Find(std::string login,std::string Password) {
	int flag = 0;
	for (auto itr = _ac.begin(); itr != _ac.end(); ++itr) {
		if (itr->first == login and itr->second == Password) {
			std::cout << " Acsess eneible" << std::endl;
			flag = 1;
			return 1;
			break;
		}

	}
	if (flag == 0) {
		std::cout << "Acsess denaied!" << std::endl;
		return 0;
	}
}


Float::Float(int nomber, int num_type, int prise, bool state):
	_nomber(nomber) , _num_type(num_type) , _prise(prise) , _state(state) {}
void Float::SetPrise(int prise) {
	_prise = prise;
}
void Float::SetState(bool state) {
	_state = state;
}
bool Float::GetState() const {
	return _state;
}
int Float::GetNomber() const {
	return _nomber;
}
int Float::GetNT() const {
	return _num_type;
}
int Float::GetPrise() const {
	return _prise;
}


Float::Float() {}
Work::Work() {
}
Info_float::Info_float() {}
Info_float::Info_float(time_t start_brone, time_t start_in, time_t end_in, bool brone) :
	_start_brone(start_brone) , _start_in(start_in) , _end_in(end_in) , _brone(brone){}


int Work::GetCount() const {
	return _count;
}
void Work::ReCount(int count) {
	_count = count;
}
void Work::Add() {
	int count = GetCount();
	int num;
	int num_type;
	int prise;
	bool state =true;
	time_t start_brone=0;
	time_t start_in=0;
	time_t start_end=0;
	bool brone = 0;
	std::cout << "Vvedite nomer = ";
	std::cin >> num;
	std::cout << "vvedite kol_mest = ";
	std::cin >> num_type;
	std::cout << "Vvedite prise = ";
	std::cin >> prise;
	Float fl_1(num,num_type,prise,state);
	Info_float Ifl_1(start_brone,start_in,start_end,brone);
	_nm.push_back ( fl_1);
	_ni.push_back( Ifl_1);
	ReCount(count + 1);
}






int main() {
	Acsess ac_1;
	ac_1.Load(ac_1);
	int flag_menu = 0;
	int flag_dopusk = 0;
	do {
		std::cout << " Vvedite Login i parol vahei y4 zapisi ili sozdaite novuu ." << std::endl;
		std::cout << "1-voiti , 2-sozdatb, 0-vuhod" << std::endl;
		std::cin >> flag_menu;
		if (flag_menu == 1) {
			int flag_id = 0;
			do {
				std::string login;
				std::string Password;
				std::cout << " login = ";
				std::cin >> login;
				std::cout << "  Password = ";
				std::cin >> Password;

				flag_dopusk=ac_1.Find(login, Password);
				flag_menu = 0;
				break;

			} while (flag_id != 0);
		}
		if (flag_menu == 2) {
			std::string login;
			std::string Password;
			std::cout << " Login = ";
			std::cin >> login;
			std::cout << " Password = ";
			std::cin >> Password;
			ac_1.Add(login, Password);
			ac_1.Save(ac_1);
		}
	} while (flag_menu != 0);
	
	if (flag_dopusk == 1) {
		Work nw_1;
		std::cout << "poli4en dostup admin! " << std::endl;
		int flag_id = 0;
		do {
			std::cout << "1-dobavit nomer, 2- prosmotr info ,0-vihod" << std::endl;
			std::cin >> flag_id;
			if (flag_id == 1) {
		
			nw_1.Add();
			}
			if (flag_id == 2) {

			}
		} while (flag_id != 0);
		
	}
	



	system("Pause");
	return 0;
}
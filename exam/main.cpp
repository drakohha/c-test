#include "m_1.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <chrono>
#include <time.h>
#include <ctime>



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
	if (login == "admin" and Password == "admin") {
		return 66;
	}
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
		throw ("Erorr");
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

	for (int i = 0; i < GetCount(); i++) {
		if (_nm[i].GetNomber() == num) {
			throw("error!");
			break;
		}
		if (num_type < 1 or num_type>4) {
			throw("error!");
			break;
		}
	}

	Float fl_1(num,num_type,prise,state);
	Info_float Ifl_1(start_brone,start_in,start_end,brone);
	Persone pfl_1("","");
	_nm.push_back ( fl_1);
	_ni.push_back( Ifl_1);
	_np.push_back(pfl_1);
	ReCount(count + 1);
}


void Work::Add_2(int nom,int nt,int prise,bool state) {
	Float fl_1(nom, nt, prise, state);
	_nm.push_back(fl_1);
	
}

void Work::Add_3(time_t brone_start, time_t start_in , time_t end_in, bool brone) {
	
	Info_float Ifl_1(brone_start, start_in, end_in, brone);
	_ni.push_back(Ifl_1);
}

void Work::Add_4(std::string name, std::string sename) {
	if (name == "none" and sename == "none") {
		Persone pfl_1("", "");
		_np.push_back(pfl_1);
	}
	else {
		Persone pfl_1(name, sename);
		_np.push_back(pfl_1);
	}
	
}



time_t Info_float::Get_st_brone()const{
	return _start_brone;
}
bool Info_float::Get_brone()const{
	return _brone;
}

void Float::Show()const {
	std::cout <<" nomer = " << GetNomber() << " ";
	std::cout << "kol_mest = "<<GetNT() << " ";
	std::cout <<" prise = "  << GetPrise() << " ";
	if (GetState() == 1) {
		std::cout << " nomer svoboden " << std::endl;
	}
	else {
		std::cout << "nomer zan9t " << std::endl;
	}

}

time_t Info_float::Get_st_in()const {
	return _start_in;
}
time_t Info_float::Get_end_in()const {
	return _end_in;
}

void Info_float::Show()const {
	if (Get_brone() == 1) {
		std::cout << " nomer zabronirovan ";

	}
	else {
		std::cout << " nomer NE zabronirovan ";
	}



	std::cout <<" data broni = " <<Get_st_brone() << " ";
	std::cout <<"data vseleni9 = " << Get_st_in() << " ";
	std::cout << "data vusileni9 = " << Get_end_in() << std::endl;
}

std::string Persone::GetName()const{
	return _name;
}
std::string Persone::GetSename()const{
	return _sename;
}

void Persone::Show()const {
	std::cout <<" name = " <<GetName() << " ";
	std::cout <<" sename = " <<GetSename() << std::endl;
}

void Work::Info_bron()const{
	for (int i = 0; i < GetCount(); i++) {
		if (_ni[i].Get_brone() == true) {
			_nm[i].Show();
			_ni[i].Show();
			_np[i].Show();
		}
	}
}
void Work::Info_empty(time_t new_time)const{
	time_t start;
	time_t end;
	struct tm * f_1;
	struct tm * f_2;
	struct tm * f_new;


	for (int i = 0; i < GetCount(); i++) {
		start = _ni[i].Get_st_in();
		end = _ni[i].Get_end_in();
		f_1 = localtime(&start);
		f_2 = localtime(&start);
		f_new = localtime(&new_time);

		if (_nm[i].GetState() == true )  {
			if (f_new->tm_mday < f_1->tm_mday or f_new->tm_mday > f_2->tm_mday) {
				if (f_new->tm_mon < f_1->tm_mon or f_new->tm_mon > f_2->tm_mon) {
					_nm[i].Show();
					_ni[i].Show();
					_np[i].Show();
				}
			}

			
		}
		if (_nm[i].GetState() == true and _ni[i].Get_st_in()==0) {
			_nm[i].Show();
			_ni[i].Show();
			_np[i].Show();
		}
	}
}


Persone::Persone(){}
Persone::Persone(std::string name, std::string sename) {
	_name = name;
	_sename = sename;
}
	
void Persone::Add(std::string name, std::string sename) {
	_name = name;
	_sename = sename;
}
void Persone::Dell(std::string name) {
	_name = "";
	_sename = "";
}


void Work::Save(Work const& nw_1) {
	std::ofstream f_10("file_2.txt");
	std::ofstream f_100("file_3.txt");
	std::ofstream f_1000("file_4.txt");
	std::ofstream f_count_2("file_5.txt");
	f_count_2 << GetCount();
	for (int i = 0; i < GetCount(); i++) {
		f_10 << _nm[i].GetNomber() << " ";
		f_10 << _nm[i].GetNT() << " ";
		f_10 << _nm[i].GetPrise() << " ";
		f_10 << _nm[i].GetState() << std::endl;
		f_100 << _ni[i].Get_st_brone() << " ";
		f_100 << _ni[i].Get_st_in() << " ";
		f_100 << _ni[i].Get_end_in() << " ";
		f_100 << _ni[i].Get_brone() << std::endl;
		
		
		if (_np[i].GetName() == "") {
			f_1000 << "none" << " ";
		}
		else {
			f_1000 << _np[i].GetName() << " ";
		}
		if (_np[i].GetSename()== "") {
			f_1000 << "none" << std::endl;
		}
		else {
			f_1000 << _np[i].GetSename() << std::endl;
		}
		
	}
	f_10.close();
	f_100.close();
	f_1000.close();
	f_count_2.close();
}

void Work::Load(Work & nw_1) {
	std::ifstream f_11("file_2.txt");
	std::ifstream f_111("file_3.txt");
	std::ifstream f_1111("file_4.txt");
	std::ifstream f_count("file_5.txt");
	int nomber;
	
	int NT;
	int prise;
	bool state;
	int count;
	f_count >> count;
	ReCount(count);
	int count_id = count;
	bool brone;
	time_t start_in;
	time_t end_in;
	time_t brone_start;
	std::string name;
	std::string sename;
	
	
	for(int i=0;i<count_id;i++) {

		f_11 >> nomber;
		f_11 >> NT;
		f_11 >> prise;
		f_11 >> state;
		f_111 >> brone_start;
		f_111 >> start_in;
		f_111 >> end_in;
		f_111 >> brone;
		f_1111 >> name;
		f_1111 >> sename;
		nw_1.Add_2(nomber, NT, prise, state);
		nw_1.Add_3(brone_start, start_in, end_in, brone);
		nw_1.Add_4(name, sename);
		
		//ReCount(count + 1);
		//count = GetCount();
	}

	f_11.close();
	f_111.close();
	f_1111.close();
	f_count.close();
}

void Work::Show(Work& nw_1)const {
	std::cout << " nomer = " << nw_1.GetNomber() << " ";
	std::cout << "kol_mest = " << nw_1.GetNT() << " ";
	std::cout << " prise = " << nw_1.GetPrise() << std::endl;
}

void Work::Pers_Find(Work & nw_1) {
	std::cout << "Vvedite daty zaseleni9 = ";
	time_t start_in;
	std::cin >> start_in;
	std::cout << "Vvedite daty viseleni9 = ";
	time_t end_in;
	std::cin >> end_in;
	std::cout << "Vvedite kol_mest = ";
	int NT;
	std::cin >> NT;

	for (int i = 0; i < GetCount(); i++) {
		if (_nm[i].GetNT() == NT ) {
			if (_ni[i].Get_brone() == 0 and _nm[i].GetState()==true) {
				std::cout << " nomer = " << _nm[i].GetNomber() << " ";
				std::cout << "kol_mest = " << _nm[i].GetNT() << " ";
				std::cout << " prise = " << _nm[i].GetPrise() << std::endl;
			}
			else {
				if (nw_1.Get_end_in() < start_in) {
					std::cout << " nomer = " << _nm[i].GetNomber() << " ";
					std::cout << "kol_mest = " << _nm[i].GetNT() << " ";
					std::cout << " prise = " << _nm[i].GetPrise() << std::endl;
				}
			}
		}
	}

}


void Info_float::Set_st_brone(time_t start_brone){
	_start_brone = start_brone;
}
void Info_float::Set_st_in(time_t start_in){
	_start_in = start_in;
}
void Info_float::Set_end_in(time_t end_in){
	_end_in = end_in;
}

void Info_float::Set_brone(bool brone) {
	_brone = brone;
}
void Work::Pers_brone(Work & nw_1) {
	struct tm * in;
	struct tm * end;
	time_t now;
	time(&now);
	std::cout << "Viberete nomer zaseleni9 iz dostupnuh = ";
	int num;
	std::cin >> num;
	std::cout << "Vvedite daty zaseleni9 : ";
	std::cout << "viberete month(0-11) = ";
	int month;
	int day;
	try {
		std::cin >> month;
		if (month < 0 or month >11) {
			throw("Enter error!");
		}
	}
	catch (...) {
		std::cout << "enter error!" << std::endl;
	}
	std::cout << "viberete day(1-31) = ";
	
	try {
		std::cin >> day;
		if (day < 1 or day >31) {
			throw("Enter error!");
		}
	}
	catch (...) {
		std::cout << "enter error!" << std::endl;
	}
	
	
	in = localtime(&now);
	in->tm_mon = month;
	in->tm_mday = day;
	time_t start_in;
	start_in = mktime(in);
	std::cout << "Vvedite daty viseleni9 = ";
	try {
		std::cout << "viberete month(0-11) = ";
		std::cin >> month;
		if (month < 0 or month >11) {
			throw("Enter error!");
		}
	}
	catch (...) {
		std::cout << "enter error!" << std::endl;
	}
	std::cout << "viberete day(1-31) = ";

	try {
		std::cin >> day;
		if (day < 1 or day >31) {
			throw("Enter error!");
		}
	}
	catch (...) {
		std::cout << "enter error!" << std::endl;
	}
	end = localtime(&now);
	end->tm_mon = month;
	end->tm_mday = day;


	time_t end_in;
	end_in = mktime(end);
	std::cout << "Vedite svoi name = ";
	std::string name;
	std::cin >> name;
	std::cout << "Vedite svoi sename = ";
	std::string sename;
	std::cin >> sename;
	int flag_ide = 0;

	for (int i = 0; i < GetCount(); i++) {
		if (_nm[i].GetNomber() == num and _nm[i].GetState()==true) {
			_nm[i].SetState(0);
			_ni[i].Set_brone(true);
			_ni[i].Set_st_brone(start_in);
			_ni[i].Set_st_in(start_in);
			_ni[i].Set_end_in(end_in);
			_np[i].Add(name, sename);
			flag_ide = 1;
		}
	}
	if (flag_ide == 0) {
		throw("Error!");
	}
}



int main() {
	setlocale(LC_ALL, "Russian");
	Acsess ac_1;
	ac_1.Load(ac_1);
	int flag_menu = 0;
	int flag_dopusk = 0;

	
	struct tm * timeinfo;
	time_t now;
	time(&now);
	timeinfo = localtime(&now);   // получить текущую дату

	//struct tm * timeinfo;
	/*
	
	time(&now);                              
	timeinfo = localtime(&now);
	std::cout << "Текущее локальное время и дата " << asctime(timeinfo);
	std::cout << now << std::endl;
	struct tm * timeinfo_2;
	timeinfo_2 = localtime(&now);
	timeinfo_2->tm_mday = 15;
	timeinfo_2->tm_mon = 5;
	now = mktime(timeinfo_2);
	timeinfo_2 = localtime(&now);
	std::cout << "nova9 data " << asctime(timeinfo_2) << std::endl;
	now = mktime(timeinfo_2);
	std::cout << now << std::endl;
	*/
	
	

	do {
		std::cout << " Vvedite Login i parol vahei y4 zapisi ili sozdaite novuu ." << std::endl;
		std::cout << "1-voiti , 2-sozdatb, 0-rabotatb" << std::endl;
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
				try {
					flag_dopusk=ac_1.Find(login, Password);
				}
				catch(...){
					std::cout << "Error enter or this login not exsist" << std::endl;
					system("Pause");
					//flag_menu = 0;
				}
				
				

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

	if (flag_dopusk == 0) {
		std::cout << "You not enter , program close." << std::endl;
		system("Pause");
		return 0;
	}
	
	Work nw_1;
	nw_1.Load(nw_1);
	
	if (flag_dopusk == 66) {
		
		std::cout << "poli4en dostup admin! " << std::endl;
		int flag_id = 0;
		do {
			std::cout << "1-dobavit nomer, 2- prosmotr info ,0-vihod" << std::endl;
			std::cin >> flag_id;
			if (flag_id == 1) {
				try {
					nw_1.Add();
					nw_1.Save(nw_1);
				}
				catch (...) {
					std::cout << "Error enter! check your info" << std::endl;
				}
				
				
			}
			if (flag_id == 2) {
				int flag_id_2 = 0;
				do { 
					std::cout << "viberete : 1- info broni, 2- info svobodnih nomerov po date,0-vihod" << std::endl;
					std::cin >> flag_id_2;
					if (flag_id_2 == 1) {
						nw_1.Info_bron();
					}
					if (flag_id_2 == 2) {
						std::cout << " vibere datu poiska : " << std::endl;
						std::cout << "viberete month(0-11) = ";
						int month;
						try {
							std::cin >> month;
							if (month < 0 or month >11) {
								throw("Enter error!");
							}
						}
						catch (...) {
							std::cout << "enter error!" << std::endl;
						}
						std::cout << "viberete day(1-31) = ";
						int day;
						try {
							std::cin >> day;
							if (day < 1 or day >31) {
								throw("Enter error!");
							}
						}
						catch (...) {
							std::cout << "enter error!" << std::endl;
						}

						struct tm * newinfo;
						newinfo= localtime(&now);
						newinfo->tm_mon = month;
						newinfo->tm_mday = day;

						time_t  new_time;
						new_time = mktime(newinfo);
						nw_1.Info_empty(new_time);
					}
				} while (flag_id_2 != 0);
			}
		} while (flag_id != 0);
		
	}
	if (flag_dopusk == 1) {
		std::cout << "poli4en dostup polsovatel! " << std::endl;
		int flag_id = 0;
		do {
			std::cout << "1-poisk nomera, 2- brone ,0-vihod" << std::endl;
			std::cin >> flag_id;
			if (flag_id == 1) {
				nw_1.Pers_Find(nw_1);
			}
			if (flag_id == 2) {
				try {
					nw_1.Pers_brone(nw_1);
				}
				catch (...) {
					std::cout << "Error enter! check info enter!" << std::endl;
				}
				
			}
			nw_1.Save(nw_1);
		} while (flag_id != 0);
	}
	
	


	system("Pause");
	return 0;
}
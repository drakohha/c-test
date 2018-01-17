#include "m1.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>



Slovar::Slovar(){}

void Slovar::Add(std::string key, std::string value) {
	_sl[key] = value;
}
void Slovar::Find(std::string key) {
	for (auto itr = _sl.begin(); itr != _sl.end(); ++itr) {
		if (itr->first == key) {
			std::cout << itr->second << std::endl;
			break;
		}
	}
}


void Slovar::Dell(std::string key) {
	for (auto itr = _sl.begin(); itr != _sl.end(); ++itr) {
		if (itr->first == key) {
			itr = _sl.erase(itr);
		}
	}

}
void Slovar::Redact(std::string key, std::string value) {
	_sl[key] = value;
}



void Slovar::Save(Slovar const& sl) {
	std::ofstream f("test.txt");
	
	for (auto itr = _sl.begin(); itr != _sl.end(); ++itr) {
		
		f << itr->first;
		f << std::endl;
		f << itr->second;
		f << std::endl;
	}
	f.close();
}


void Slovar::Save_2(Slovar const& sl_2) {
	std::ofstream f_3("test_2.txt");

	for (auto itr = _sl.begin(); itr != _sl.end(); ++itr) {

		f_3 << itr->first;
		f_3 << std::endl;
		f_3 << itr->second;
		f_3 << std::endl;
	}
	f_3.close();
}


void Slovar::Load(Slovar& sl) {
	std::ifstream f_2("test.txt");
	char buff[100];
	
	std::string key;
	std::string value;
	while(!f_2.eof()){
		f_2.getline(buff,100);
		key = buff;
		f_2.getline(buff, 100);
		value = buff;
		sl.Add(key, value);
		
	}
	
	f_2.close();
}


void Slovar::Show(Slovar const& sl_2) {
	for (auto itr = this->_sl.begin(); itr != this->_sl.end(); ++itr) {
		std::cout << itr->first << " " << itr->second << std::endl;
	}
}

int main() {

	Slovar sl_1;

	


	int flag_menu = 0;
	
	do {
		std::cout << "Vvedite deistvie: 1- zagruzit fail, 2- dobavit, 3-poisk, 4-ydalit,5-sohranit,6-vivesti info,0-vuhod" << std::endl;
		fflush(stdin);
		//while (getchar() != '/n');
		
		std::cin >> flag_menu;

		if (flag_menu == 1) {
			sl_1.Load(sl_1);
		}
		if (flag_menu == 2) {
			char buffer[100];
			std::string key;
			std::string value;
			std::cout << "Vvedite slovo = ";
			std::cin >> key;
			std::cout << std::endl;
			std::cout << "Vvedite zna4enie = ";
			//std::cin >> value;
			//while (getchar() != '/n');
			fflush(stdin);
			gets_s(buffer, 100);
			gets_s(buffer, 100);
			fflush(stdin);
			value = buffer;
			std::cout << std::endl;
			sl_1.Add(key, value);
		}
		if (flag_menu == 3) {
			std::string key;
			std::cout << "Vvedite slovo = ";
			std::cin >> key;
			std::cout << std::endl;
			sl_1.Find(key);

		}
		if (flag_menu == 4) {
			std::string key;
			std::cout << "Vvedite slovo = ";
			std::cin >> key;
			std::cout << std::endl;

			sl_1.Dell(key);
		}
		if (flag_menu == 5) {

			sl_1.Save(sl_1);

		}
		if (flag_menu == 6) {
			Slovar sl_2;
			sl_1.Save_2(sl_1);
			std::ifstream f_4("test.txt");
			
			char buff[100];
			std::ostringstream id_count_s;
			int id_count=0;
			std::string key;
			std::string value;
			//std::string key_2;
			while (!f_4.eof()) {
				f_4 >> key;
				std::ifstream f_5("test_2.txt");
				while (!f_5.eof()) {
					f_5 >> value;
					if (key == value) {
						id_count++;
					}
				}
				id_count_s << id_count;
				//std::ostringstream key_2;
				//key_2 << id_count;
				std::string key_2 = id_count_s.str();
				sl_2.Add(key, key_2);
				id_count = 0;
				id_count_s.seekp(SEEK_SET);
				f_5.close();

			}

			f_4.close();
			sl_2.Show(sl_2);
		}

	} while (flag_menu != 0);


	system("Pause");
	return 0;
}
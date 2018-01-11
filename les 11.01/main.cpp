#include "m1.h"
#include <iostream>
#include <fstream>





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
	char buff[100];
	for (auto itr = _sl.begin(); itr != _sl.end(); ++itr) {
		strcpy_s(buff, itr->first.data());
		strcpy_s(buff, itr->second.data());
		f.write(buff, 100);
	}
	f.close();
}

int main() {

	Slovar sl_1;

	sl_1.Add("first", "pervii");
	sl_1.Find("first");
	sl_1.Add("Second", "vtoroi");
	sl_1.Find("Second");
	sl_1.Redact("Second", "new_vtoroi");
	sl_1.Find("Second");

	
	
	
	
	sl_1.Save(sl_1);

	system("Pause");
	return 0;
}
#pragma once
#include <map>
#include <string>


class Slovar {
public:
	Slovar();
	void Add(std::string key, std::string value);
	void Find(std::string key);
	
	void Dell(std::string key);
	void Redact(std::string key, std::string value);
	void Save(Slovar const& sl);
	void Save_2(Slovar const& sl_2);
	void Load(Slovar& sl);
	void Show(Slovar const& sl_2);

private:
	std::map<std::string, std::string> _sl;
};


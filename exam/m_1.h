#pragma once
#include <string>
#include <map>
#include <vector>

class Acsess {
public:
	Acsess();
	void Load(Acsess& ac_1);
	void Save(Acsess const& ac_1);
	void Add(std::string login, std::string Password);
	int Find(std::string login, std::string Password);
private:
	std::map<std::string, std::string> _ac;
	
};

class Float {
public:
	Float();
	Float(int nomber, int num_type, int prise, bool state);
	void SetPrise(int prise);
	void SetState(bool state);
	bool GetState() const;
	int GetNomber() const;
	int GetNT() const;
	int GetPrise() const;
private:
	
	int _nomber;
	int _num_type;
	int _prise;
	bool _state;
	
};


class Info_float : public Float {
public:
	Info_float();
	Info_float(time_t start_brone,time_t start_in,time_t end_in,bool brone);
private:
	time_t _start_brone;
	time_t _start_in;
	time_t _end_in;
	bool _brone;
};

class Work : public Info_float {
public:
	Work();
	void Add();
	int GetCount() const;
	void ReCount(int count);
private:
	int _count;
	std::vector<Float> _nm;
	std::vector<Info_float> _ni;
};
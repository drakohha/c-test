#pragma once
#include <string>
#include <map>
#include <vector>
#include <ctime>

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
	void Show()const;
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
	time_t Get_st_brone()const;
	bool Get_brone()const;
	void Show()const;
	time_t Get_st_in()const;
	time_t Get_end_in()const;
	void Set_brone(bool brone);
	void Set_st_brone(time_t start_brone);
	void Set_st_in(time_t start_in);
	void Set_end_in(time_t end_in);
private:
	time_t _start_brone; //data bronirivati9
	time_t _start_in; // data vseleni9
	time_t _end_in; // data vuseleni9
	bool _brone;  // zabronirovan li nomer
};


class Persone : public Info_float {
public:
	Persone();
	Persone(std::string name, std::string sename);
	void Add(std::string name, std::string sename);
	void Dell(std::string name);
	void Show()const;
	std::string GetName()const;
	std::string GetSename()const;
	
private:
	std::string _name;
	std::string _sename;
};





class Work :  public Persone {
public:
	Work();
	void Add();
	void Add_2(int num,int nt,int prise,bool state);
	void Add_3(time_t brone_start,time_t start_in, time_t end_in ,bool brone);
	void Add_4(std::string name, std::string sename);
	void Save(Work const& nw_1);
	void Load(Work & nw_1);
	void Pers_Find(Work & nw_1);
	void Pers_brone(Work & nw_1);
	void Show(Work& nw_1)const;
	void Info_bron()const;
	void Info_empty(time_t new_time)const;
	int GetCount() const;
	void ReCount(int count);
private:
	int _count;
	std::vector<Float> _nm;
	std::vector<Info_float> _ni;
	std::vector<Persone> _np;
};



#pragma once
#include <string>
#include <vector>





class TheList  {
public:
	TheList();
	TheList(std::string _firm_name, std::string _vladelec, int _number, std::string _adres, std::string _rabota);
	
	std::string GetFirm() const;
	void SetFirm(std::string firm_name);
	std::string GetVlad() const;
	void SetVlad(std::string vladelec);
	int GetNum() const;
	void SetNum(int number);
	std::string GetAdres() const;
	void SetAdres(std::string adres);
	std::string GetRabota() const;
	void SetRabota(std::string rabota);
private:
	std::string _firm_name;
	std::string _vladelec;
	int _number;
	std::string _adres;
	std::string _rabota;

};


class List : public TheList {
public:

	//List() = default;
	~List();
	void Add(TheList const& sp);
	void Dell(int index);
	int FindFirm(std::string firm_name);
	int FindVladelec(std::string vladelec);
	int FindNumber(int number);
	int FindRabota(std::string rabota);
	int FindAdres(std::string adres);
	void Out(int index) const;
	void SetSize(int size);
	int GetSize() const;

private:
	std::vector<TheList> _sp;
	int _size;
	
};
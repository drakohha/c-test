#pragma once
#include<string>


class Data{
public:
	Data(int day,int month,int year);
	void GetData() const;
	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);
	Data& operator+(Data const&);
	bool operator>(Data const&);
	bool operator<(Data const&);
	bool operator==(Data const&);
	bool operator>=(Data const&);
	bool operator<=(Data const&);
	
private:
	int _day;
	int _month;
	int _year;
};
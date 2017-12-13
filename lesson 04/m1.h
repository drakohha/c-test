#pragma once
#include <iostream>


class Okr{
	public:
		Okr(int rad);
		int GetRad() const;
		void SetRad(int rad);
		 bool operator==(Okr const& l);
		 int operator+(Okr const& l);
		 bool operator>(Okr const& l);
		 bool operator<(Okr const& l);
		 int operator+=(Okr const& l);	
		 int operator-=(Okr const& l);
		 
		 friend std::ostream& operator<<(std::ostream &s, Okr const& p);
	private:
		int _rad;
};

std::ostream& operator<<(std::ostream &s,Okr const& p);
#include "m1.h"
#include <iostream>



Okr::Okr(int rad):_rad(rad){

}


void Okr::SetRad(int rad){
	_rad=rad;
}

int Okr::GetRad()const{
	return _rad;
}

bool Okr::operator==(Okr const& l){
	if (l._rad == _rad){
		return true;
	}
	else{
		return 0;
	}
}

int Okr::operator+(Okr const& l){
	_rad+=l._rad;
	return _rad;
}


bool Okr::operator>(Okr const& l){
	if (l._rad > _rad){
		return true;
	}
	else{
		return 0;
	}
}
bool Okr::operator<(Okr const& l){
	if (l._rad < _rad){
		return true;
	}
	else {
		return 0;
	}
}
int Okr::operator+=(Okr const& l){
	_rad=_rad+l._rad;
	return _rad;
}
int Okr::operator-=(Okr const& l){
	_rad=_rad-l._rad;
	return _rad;
}
std::ostream& operator<<(std::ostream &s, Okr const& p){
	s<<p._rad;
	return s;
}

int main(){


	Okr r1(15);
	Okr r2(25);
	Okr r3(5);

	std::cout << r1.GetRad() << std::endl;
	std::cout << r2.GetRad() << std::endl;
	if (r1==r2){
		std::cout << "true" << std::endl;
	}
	else{
		std::cout << "folse" << std::endl;
	}
	
	r1+10;
	std::cout << r1.GetRad() << std::endl;
	if (r1 == r2){
		std::cout << "true" << std::endl;
	}
	else{
		std::cout << "folse" << std::endl;
	}
	r3+=r1+r2;
	std::cout << r1.GetRad() << std::endl;
	std::cout << r2.GetRad() << std::endl;
	std::cout << r3.GetRad() << std::endl;

	std::cout << "tyt"<<r1;
	system("Pause");
	return 0;
}


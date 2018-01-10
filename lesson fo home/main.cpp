#include "m1.h"
#include <iostream>
#include <string>
#include <typeinfo>

Shape::Shape() {
	
}
Square::Square() {

}

void Shape::Show() const {
	for (int i = 0; i < GetSize(); i++) {
		//_ms[i].info(i);
	}
}

int Shape::GetSize() const {
	return _size;
}
void Shape::Save() const {

}
void Shape::Load() {

}

void Shape::info(int i) const {
	if (typeid(_ms[i]).name() == typeid(Square).name()) {
		//Look(i);
	}
}


std::string Square::Look(int index) const {
	
	std::string x;
	x = _v[index].GetX();
	std::string y;
	y = _v[index].GetY();
	std::string gran;
	gran = _v[index].GetGran();
	return "figura square gde x= " + x  + " y= " +y + " so ctoronoi = " + gran  ;
}

Square::Square(int x, int y, int gran) : _x(x), _y(y), _gran(gran) {

}
int Square::GetX() const {
	return _x;
}
void Square::SetX(int x){
	_x = x;
}
int Square::GetY() const{
	return _y;
}
void Square::SetY(int y){
	_y = y;
}
int Square::GetGran() const{
	return _gran;
}
void Square::SetGran(int gran){
	_gran = gran;
}


void Shape::Resize(int size) {
	_size = size;
}

void Square::AddS(Square const& s) {
	
	_ms = new Square[1];
	_ms[0] = s;
	Resize(GetSize() + 1);
	_v.push_back(s);
}







int main(){
	Shape sh;
	Square s_1(10, 10, 15);

	s_1.AddS(s_1);
	sh._ms->Show();




	system("Pause");
	return 0;
}
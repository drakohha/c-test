#include "m1.h"
#include <iostream>
#include <string>
#include <typeinfo>
#include <fstream>

Shape::Shape() {
	
}

void Shape::ReSize(int size) {
	_size = size;
}
int Shape::GetSize() const {
	return _size;
}

void Shape::Show() const {
	
}


void Shape::Save() const {

}
void Shape::Load() {

}

void Shape::area() const {

}


Square::Square(int x, int y, int gran) : _x(x), _y(y), _gran(gran) {

}

void Square::SetX(int x) {
	_x = x;
}
void Square::SetY(int y) {
	_y = y;
}
void Square::SetGran(int gran) {
	_gran = gran;
}


int Square::GetX()const {
	return _x;
}
int Square::GetY()const {
	return _y;
}
int Square::GetGran()const {
	return _gran;
}


void Square::area() const {
	
	
}



void Square::Show() const {
	std::cout <<" Square : x= " << GetX() << " ";
	std::cout <<" y= " << GetY() << " ";
	std::cout <<"gran=  " << GetGran() << std::endl;
}


Rectangle::Rectangle(int x, int y, int dlina, int shirina)
	: _x(x), _y(y) , _dlina(dlina) , _shirina(shirina)
{}
int Rectangle::GetX() const {
	return _x;
}
int Rectangle::GetY() const {
	return _y;
}
int Rectangle::GetDlina()const {
	return _dlina;
}
int Rectangle::GetShirina()const {
	return _shirina;
}
void Rectangle::area() const{}
void Rectangle::Show() const{
	std::cout << "Rectangle : x= " << GetX() << " ";
	std::cout << " y= " << GetY() << " ";
	std::cout << " dlina= " << GetDlina() << " ";
	std::cout << " shirina= " << GetShirina() << std::endl;
}

Circle::Circle(int x, int y, int r)
	: _x(x), _y(y), _r(r){}
int Circle::GetX() const{
	return _x;
}
int Circle::GetY() const{
	return _y;
}
int Circle::GetR()const{
	return _r;
}
void Circle::area() const{}
void Circle::Show() const{
	std::cout << " Circle : x= " << GetX() << " ";
	std::cout << " y= " << GetY() << " ";
	std::cout << "radius=  " << GetR() << std::endl;
}


Ellipse::Ellipse(int x, int y, int dlina, int shirina, int r1, int r2):
	_x(x), _y(y) , _dlina(dlina), _shirina(shirina) , _r1(r1), _r2(r2) {}
int Ellipse::GetX() const {
	return _x;
}
int Ellipse::GetY() const {
	return _y;
}
int Ellipse::GetDlina()const {
	return _dlina;
}
int Ellipse::GetShirina()const {
	return _shirina;
}
int Ellipse::GetR1() const {
	return _r1;
}
int Ellipse::GetR2() const {
	return _r2;
}
void Ellipse::area() const{}
void Ellipse::Show() const{
	std::cout << "Ellipse x=  " << GetX() << " ";
	std::cout << " y= " << GetY() << " ";
	std::cout << " dlina= " << GetDlina() << " ";
	std::cout << " shirina= " << GetShirina() << std::endl;
	std::cout << " radius_1 = " << GetR1() << " ";
	std::cout << " radius_2 = " << GetR2() << std::endl;


}



void Shape::ReCount(int _count) {
	count = _count;
}

int  Shape::GetCount() const {
	return count;
}




void Square::Save() const {  
	std::ofstream m("test.txt");
	m.seekp(SEEK_END);
	m << GetSize();
	m << GetX();
	m << GetY();
	m << GetGran();
	m.close();

}
void  Rectangle::Save() const {




}
void Circle::Save() const {

}
void Ellipse::Save() const {

}


void Square::Load() {
	int buff;
	std::ifstream m("test.txt");
	m >> buff;
	ReSize(buff);
	m >> buff;
	SetX(buff);
	m >> buff;
	SetY(buff);
	m >> buff;
	SetGran(buff);
	m.close();
}

void Rectangle::Load() {

}

void Circle::Load() {

}

void Ellipse::Load() {

}




int main(){
	Shape *shapes[100]; // vzat iz faila
	int _count=0; // vzat iz faila
	


	int flag_menu = 0;
	int flag_id = 0;
	do {
		std::cout << "Vibirete deistvie : 1- sozdatb figuru, 2-pokazat vse figuri , 3- sohranit v faile, 4- zagruzit iz faila , 0-vuhod " << std::endl;
		std::cin >> flag_menu;

		if (flag_menu == 1) {

			std::cout << "viberete kakui sozdatb: 1-Square,2-Rectangle,3-Circle,4-Ellipse,0-vuhod" << std::endl;
			do {
				std::cin >> flag_id;
				if (flag_id == 1) {
					shapes[_count] = new Square(6, 2, 10);
					shapes[_count]->ReSize(3);
					shapes[_count]->ReCount(_count + 1);
					_count++;
					
					
				}
				if (flag_id == 2) {
					shapes[_count] = new Rectangle(5, 6, 10, 15);
					shapes[_count]->ReSize(4);
					shapes[_count]->ReCount(_count + 1);
					_count++;

				}
				if (flag_id == 3) {
					shapes[_count] = new Circle(2, 3, 5);
					shapes[_count]->ReSize(3);
					shapes[_count]->ReCount(_count + 1);
					_count++;

				}
				if (flag_id == 4) {
					shapes[_count] = new  Ellipse(5, 6, 10, 15, 7, 8);
					shapes[_count]->ReSize(6);
					shapes[_count]->ReCount(_count + 1);
					_count++;



				}
			} while (flag_id != 0);
		}
		if (flag_menu == 2) {
			for (int i = 0; i < _count; i++) {
				shapes[i]->Show();
			}
		}
		if (flag_menu == 3) {
			for (int i = 0; i < _count; i++) {
				shapes[i]->Save();
			}
		}
		if (flag_menu == 4) {
			for (int i = 0; i < _count; i++) {
				shapes[i]->Load();
			}
		}
		




	} while (flag_menu != 0);


	system("Pause");
	return 0;
}
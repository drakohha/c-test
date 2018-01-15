#pragma once
#include <string>
#include <vector>


class Shape  {
public:
	Shape();
	virtual void Show() const;
	virtual void Save() const;
	virtual void Load();
	virtual void area() const;
	void ReSize(int size);
	int GetSize() const;
	void ReCount(int count);
	int  GetCount() const;
private:
	int _size;
	int count;
	
};



class Square : public  Shape {
public:
	Square(int _x, int _y, int _gran);
	void SetX(int x);
	void SetY(int y);
	void SetGran(int gran);
	int GetX()const;
	int GetY()const;
	int GetGran()const;
	virtual void area() const;
	virtual void Show() const;
	virtual void Save() const;
	virtual void Load();
private:
	int _x;
	int _y;
	int _gran;
	
};


class Rectangle : public  Shape {
public:
	Rectangle(int x, int y, int dlina, int shirina);
	int GetX() const;
	int GetY() const;
	int GetDlina()const;
	int GetShirina()const;
	virtual void area() const;
	virtual void Show() const;
	virtual void Save() const;
	virtual void Load();
private:
	int _x;
	int _y;
	int _dlina;
	int _shirina;

};


class Circle : public  Shape {
public:
	Circle(int x, int y, int r);
	int GetX() const;
	int GetY() const;
	int GetR()const;
	virtual void area() const;
	virtual void Show() const;
	virtual void Save() const;
	virtual void Load();
private:
	int _x;
	int _y;
	int _r;
};

class Ellipse : public  Shape {
public:
	Ellipse(int x, int y, int dlina, int shirina, int r1, int r2);
	int GetX() const;
	int GetY() const;
	int GetDlina()const;
	int GetShirina()const;
	int GetR1() const;
	int GetR2() const;
	virtual void area() const;
	virtual void Show() const;
	virtual void Save() const;
	virtual void Load();
private:
	int _x;
	int _y;
	int _dlina;
	int _shirina;
	int _r1;
	int _r2;
};
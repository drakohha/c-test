#pragma once
#include <string>
#include <vector>

class Shape  {
public:
	Shape();
	virtual void Show() const;
	virtual void Save() const;
	virtual void Load();
	void Resize(int size);
	int GetSize() const;
	virtual void info(int i) const;
	Shape * _ms = nullptr;
private:
	
	int _size;
};



class Square : public virtual Shape {
public:
	Square() = default;
	Square(int _x, int _y, int _gran);
	int GetX() const;
	void SetX(int x);
	int GetY() const;
	void SetY(int y);
	int GetGran() const;
	void SetGran(int gran);
	void AddS(Square const& s);
	 std::string Look(int index) const;
private:
	int _x;
	int _y;
	int _gran;
	std::vector<Square> _v;
};


class Rectangle : public virtual Shape {
public:
private:
	int _x;
	int _y;
	int _dlina;
	int _shirina;

};


class Circle : public virtual Shape {
public:
private:
	int _x;
	int _y;
	int _r;
};

class Ellipse : public virtual Shape {
public:
private:
	int _x;
	int _y;
	int _dlina;
	int _shirina;
	int _r1;
	int _r2;
};
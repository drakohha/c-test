#pragma once
#include <string>
#include <vector>



class figura {
public:
	figura();
	figura(std::string name, std::string color);
	std::string GetName() const;
private:
	std::string _name;
	std::string _color;
};

class kletka :public figura{
public:
	kletka();
	kletka(int kord_x, int kord_y, bool kl,std::string color);
	bool GetKl() const;
	void SetKl(bool kl);
	int GetX()const;
	int GetY()const;
	void SetX(int kord_x);
	void SetY(int kord_y);
	std::string GetColor()const;
	void SetFigura(figura & figura);
	figura GetFigura()const;
private:
	int _kord_x;
	int _kord_y;
	bool _kl;
	std::string _color;
	figura  _figura;
};





class Haxmatu : public kletka{
public:
	Haxmatu();
	void Show();
	void Add(kletka& kl_1);
private:
	std::vector<kletka> _pole;
};


class Player {
public:
	Player(std::string name,std::string side);
	std::string GetName() const;
	std::string GetSise()const;
private:
	std::string _name;
	std::string _side;
};




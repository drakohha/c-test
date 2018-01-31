#include "m1.h"
#include <iostream>

Haxmatu::Haxmatu() {

}

void Haxmatu::Show() {

}

kletka::kletka(int kord_x, int kord_y, bool kl, std::string color) :
	_kord_x(kord_x), _kord_y(kord_y), _kl(kl), _color(color) {

}
kletka::kletka(){}



bool kletka::GetKl() const {
	return _kl;
}
void kletka::SetKl(bool kl) {
	_kl = kl;
}
int kletka::GetX()const {
	return _kord_x;
}
int kletka::GetY()const {
	return _kord_y;
}
void kletka::SetX(int kord_x) {
	_kord_x = kord_x;
}
void kletka::SetY(int kord_y) {
	_kord_y = kord_y;
}
std::string kletka::GetColor()const {
	return _color;
}
void kletka::SetFigura(figura & figura) {
	_figura = figura;
}
figura kletka::GetFigura()const {
	return _figura ;
}

figura::figura(){}



Player::Player(std::string name, std::string side):
	_name(name), _side(side) {}


std::string Player::GetName() const {
	return _name;
}
std::string Player::GetSise()const {
	return _side;
}


figura::figura(std::string name, std::string color) :
	_name(name), _color(color){}


std::string figura::GetName() const {
	return _name;
}


void Haxmatu::Add(kletka& kl_1) {
	_pole.push_back(kl_1);
}




int main() {
	Haxmatu hm;
	kletka kl_11(0, 0, true, "Black");
	kletka kl_12(0, 1, true, "Light");
	kletka kl_13(0, 2, true, "Black");
	kletka kl_14(0, 3, true, "Light");
	kletka kl_15(0, 4, true, "Black");
	kletka kl_16(0, 5, true, "Light");
	kletka kl_17(0, 6, true, "Black");
	kletka kl_18(0, 7, true, "Light");

	kletka kl_21(1, 0, true, "Light");
	kletka kl_22(1, 1, true, "Black");
	kletka kl_23(1, 2, true, "Light");
	kletka kl_24(1, 3, true, "Black");
	kletka kl_25(1, 4, true, "Light");
	kletka kl_26(1, 5, true, "Black");
	kletka kl_27(1, 6, true, "Light");
	kletka kl_28(1, 7, true, "Black");

	kletka kl_31(2, 0, true, "Black");
	kletka kl_32(2, 1, true, "Light");
	kletka kl_33(2, 2, true, "Black");
	kletka kl_34(2, 3, true, "Light");
	kletka kl_35(2, 4, true, "Black");
	kletka kl_36(2, 5, true, "Light");
	kletka kl_37(2, 6, true, "Black");
	kletka kl_38(2, 7, true, "Light");

	kletka kl_41(3, 0, true, "Light");
	kletka kl_42(3, 1, true, "Black");
	kletka kl_43(3, 2, true, "Light");
	kletka kl_44(3, 3, true, "Black");
	kletka kl_45(3, 4, true, "Light");
	kletka kl_46(3, 5, true, "Black");
	kletka kl_47(3, 6, true, "Light");
	kletka kl_48(3, 7, true, "Black");

	kletka kl_51(4, 0, true, "Black");
	kletka kl_52(4, 1, true, "Light");
	kletka kl_53(4, 2, true, "Black");
	kletka kl_54(4, 3, true, "Light");
	kletka kl_55(4, 4, true, "Black");
	kletka kl_56(4, 5, true, "Light");
	kletka kl_57(4, 6, true, "Black");
	kletka kl_58(4, 7, true, "Light");

	kletka kl_61(5, 0, true, "Light");
	kletka kl_62(5, 1, true, "Black");
	kletka kl_63(5, 2, true, "Light");
	kletka kl_64(5, 3, true, "Black");
	kletka kl_65(5, 4, true, "Light");
	kletka kl_66(5, 5, true, "Black");
	kletka kl_67(5, 6, true, "Light");
	kletka kl_68(5, 7, true, "Black");

	kletka kl_71(6, 0, true, "Black");
	kletka kl_72(6, 1, true, "Light");
	kletka kl_73(6, 2, true, "Black");
	kletka kl_74(6, 3, true, "Light");
	kletka kl_75(6, 4, true, "Black");
	kletka kl_76(6, 5, true, "Light");
	kletka kl_77(6, 6, true, "Black");
	kletka kl_78(6, 7, true, "Light");

	kletka kl_81(7, 0, true, "Light");
	kletka kl_82(7, 1, true, "Black");
	kletka kl_83(7, 2, true, "Light");
	kletka kl_84(7, 3, true, "Black");
	kletka kl_85(7, 4, true, "Light");
	kletka kl_86(7, 5, true, "Black");
	kletka kl_87(7, 6, true, "Light");
	kletka kl_88(7, 7, true, "Black");

	
	hm.Add(kl_11);
	hm.Add(kl_12);
	hm.Add(kl_13);
	hm.Add(kl_14);
	hm.Add(kl_15);
	hm.Add(kl_16);
	hm.Add(kl_17);
	hm.Add(kl_18);
	hm.Add(kl_21);
	hm.Add(kl_22);
	hm.Add(kl_23);
	hm.Add(kl_24);
	hm.Add(kl_25);
	hm.Add(kl_26);
	hm.Add(kl_27);
	hm.Add(kl_28);
	hm.Add(kl_31);
	hm.Add(kl_32);
	hm.Add(kl_33);
	hm.Add(kl_34);
	hm.Add(kl_35);
	hm.Add(kl_36);
	hm.Add(kl_37);
	hm.Add(kl_38);
	hm.Add(kl_41);
	hm.Add(kl_42);
	hm.Add(kl_43);
	hm.Add(kl_44);
	hm.Add(kl_45);
	hm.Add(kl_46);
	hm.Add(kl_47);
	hm.Add(kl_48);

	hm.Add(kl_51);
	hm.Add(kl_52);
	hm.Add(kl_53);
	hm.Add(kl_54);
	hm.Add(kl_55);
	hm.Add(kl_56);
	hm.Add(kl_57);
	hm.Add(kl_58);
	hm.Add(kl_61);
	hm.Add(kl_62);
	hm.Add(kl_63);
	hm.Add(kl_64);
	hm.Add(kl_65);
	hm.Add(kl_66);
	hm.Add(kl_67);
	hm.Add(kl_68);
	hm.Add(kl_71);
	hm.Add(kl_72);
	hm.Add(kl_73);
	hm.Add(kl_74);
	hm.Add(kl_75);
	hm.Add(kl_76);
	hm.Add(kl_77);
	hm.Add(kl_78);
	hm.Add(kl_81);
	hm.Add(kl_82);
	hm.Add(kl_83);
	hm.Add(kl_84);
	hm.Add(kl_85);
	hm.Add(kl_86);
	hm.Add(kl_87);
	hm.Add(kl_88);








	system("Pause");
	return 0;
}


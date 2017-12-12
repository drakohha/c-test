#include "m1.h"
#include <iostream>
Data::Data(int day, int month, int year):
_day(day), _month(month), _year(year)
{
}

void Data::GetData() const{
	std::cout << "\nday is " << _day;
	std::cout << " month is " << _month;
	std::cout << " year is " << _year << std::endl;
}

void Data::SetDay(int day){
	if (day > 0 && day < 32){
		_day=day;
	}
	else{
		std::cout << "\n Value of day must be in range (1-31)"<< std::endl;
	}
	
}
void Data::SetMonth(int month){
	if (month > 0 && month < 13){
		_month = month;
	}
	else{
		std::cout << "\n Value of month must be in range (1-12)" << std::endl;
	}

}

void Data::SetYear(int year){
	if (year > 0){
		_year = year;
	}
	else{
		std::cout << "\n Value of day must be in range (1 -...)" << std::endl;
	}

}

bool Data::operator==(Data const&){
	
}

int main(){
	Data d(11,5,1990);
	Data d2(18,9,2000);
	bool n;
	if (d == d2){
		n=true;
		std::cout << n;
	}
	else{
		std::cout << "folse";
	}
	d.GetData();
	
	
	system("Pause");
	return 0;
}
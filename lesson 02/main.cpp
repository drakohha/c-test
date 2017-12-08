#include "m_1.h"
#include <algorithm>
Book::Book(){
}

Book::Book(std::string avtor, std::string name, int yer) :_avtor( avtor),_name(name),_yer(yer) {

}

library::library(std::vector<Book>){

}

library::library(){

}

void library::SetBook(){
	std::string avtor;
	std::string name;
	int yer;
	std::cout << "\n"<< "vvedite im9 avtora :" << "\n";
	std::cin >>avtor;
	std::cout << "\n" << "vvedite im9 knigi :" << "\n";
	std::cin >> name;
	std::cout << "\n" << "vvedite god knigi :" << "\n";
	std::cin >> yer;
	v.push_back(Book(avtor,name,yer));
}

std::string Book::GetAvtor() const{
	return _avtor;
}

std::string Book::GetName() const{
	return _name;
}

int Book::GetYer() const{
	return _yer;
}


void Book::SetAvtor(){
	std::cout << "Vvedite im9 avtora : ";
	std::cin >> _avtor;
}

void Book::SetName(){
	std::cout << "Vvedite im9 knigi : ";
	std::cin >> _name;
}

void Book::SetYer(){
	std::cout << "Vvedite god kinigi : ";
	std::cin >> _yer;
}

void library::GetBook() const{
	
	for (int i = 0; i < v.size(); i++){
		std::cout << "\n" <<"Avtor knigi : " << v[i].GetAvtor() <<" im9 knigi : ";
		std::cout << v[i].GetName() << "god knigi : "  ;
		std::cout << v[i].GetYer()<<"\n";
	}
}

void library::GetListAvtors() const{
	std::vector<Book>::iterator it;
	std::sort(v.begin(), v.end());
	std::cout << "myvector contains:";
	//for (it = v.begin(); it != v.end(); ++it)
	//	std::cout << "\n " << *it;

	std::cout << "\n";


}

void library::GetListYer() const{

}

int main(){
Book b_1;
Book b_2;

library lib;

lib.SetBook();

lib.GetBook();


system("Pause");
return 0;
}
#pragma once
#include <iostream>
#include <string>
#include <vector>

class Book{
	public:
		explicit Book();
		explicit Book(std::string avtor, std::string name, int yer);
		std::string GetAvtor() const;
		void SetAvtor();
		int GetYer() const;
		void SetYer();
		void SetName();
		std::string GetName() const;
		
	private:
		std::string _avtor;
		std::string _name;
		int _yer;
};


class library{
	public:
		explicit library();
		explicit library(std::vector<Book>);
		void SetBook();
		void GetBook() const;
		void GetListAvtors() const;
		void GetListYer() const;
		
	private:
		std::vector<Book> v;
};
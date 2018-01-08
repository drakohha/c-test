#include "m1.h"
#include <iostream>
#include <string>



template<typename Key, typename Value>
Tree<Key, Value>::Tree() {

}

/* probnik
template<typename T>
T fun_1(int data_3, T data_4) {
	switch (data_3) {
	case 1:{
		try {
			const std::type_info& ti1 = typeid(int);
			const std::type_info& ti2 = typeid(data_4);
			if (&ti1 != &ti2) {
				throw std::exception("\nerror\n");
			}
			else if (data_4 < 0) {
				throw std::exception("\nerror\n");
			}
			else {
				
				return data_4;
			}
			
			
		}
		catch (std::exception const& e) {
			std::cout << e.what();
			return 0;
		}
	}
	case 2: {
		try {
			const std::type_info& ti1 = typeid(std::string);
			const std::type_info& ti2 = typeid(data_4);
			if (&ti1 == &ti2) {
				return data_4;
			}
			else {
				throw std::exception("\nerror\n");
			}
			
			

		}
		catch (std::exception const& e) {
			std::cout << e.what();
			return 0;
		}

	}
	}
	
}
*/

template<typename Key, typename Value>
void Tree<Key, Value>::Add(Key data, Value data_2) {
	TreeItem* temp=nullptr;
	TreeItem *item = new TreeItem;
	item->_Key = data;
	item->_Value = data_2;
	if (_data == nullptr) {
		_data = item;
	}
	else {
		
		temp = _data;
		while (true) {
			
			 
			if (temp->_Key < data) {
				
				if (temp->left == nullptr) {
				temp->left = item;
				break;
				}
				else {
				temp = temp->left;
				}
			}
			else {
				
				if (temp->right == nullptr) {
				temp->right = item;
				break;
				}
				else{
				temp = temp->right;
				}
				
			}
		}
		
		
	}
	
}
template<typename Key, typename Value>
Key Tree<Key, Value>::GetKey()const {
	
	return _data->_Key;
}

template<typename Key, typename Value>
Value Tree<Key, Value>::GetValue() const {
	
	return _data->_Value;
}


template<typename Key, typename Value>
void Tree<Key, Value>::SetValue(Key data, Value data_2) {
	if (_data->_Key == data) {
		_data->_Value = data_2;
	}
	
}


template<typename Key, typename Value>
Key Tree<Key, Value>::FindValue(Value data) const {
	if (_data->_Value == data) {
		return _data->_Key;
	}
	else {
		TreeItem* temp = nullptr;
		TreeItem *item = new TreeItem;
		item->_Value = GetValue();
		item->_Key = GetKey();
		if (_data->_Value == data) {
			return _data->_Key;
		}
		else {

			temp = _data;
			while (true) {


				if (temp->_Key < GetKey()) {

					if (temp->_Value == data) {
						return temp->_Key;
						break;
					}
					else {
						temp = temp->left;
					}
				}
				else {

					if (temp->_Value == data) {
						return temp->_Key;
						break;
					}
					else {
						temp = temp->right;
					}

				}
			}


		}
	}

}

template<typename Key, typename Value>
Value Tree<Key, Value>::FindKey(Key data) const {
	if (_data->_Key == data) {
		return _data->_Value;
	}
	else {
		TreeItem* temp = nullptr;
		TreeItem *item = new TreeItem;
		item->_Key = data;
		
		if (_data == nullptr) {
			return _data->_Value;
		}
		else {

			temp = _data;
			while (true) {


				if (temp->_Key < data) {

					if (temp->left == nullptr) {
						return temp->_Value;
						break;
					}
					else {
						temp = temp->left;
					}
				}
				else {

					if (temp->right == nullptr) {
						return temp->_Value;
						break;
					}
					else {
						temp = temp->right;
					}

				}
			}


		}

	}
}


void f1(int index) {
	if (index < 0) {
		throw std::exception("Error");
	}
	else {
	
	}
}


void f2(int index,Tree<int, std::string> tr_1) {
	if (index < 0) {
		throw std::exception("Error");
	}
	else {
		std::cout << tr_1.FindKey(index) << std::endl;
	}
}



int main() {

	int index = 0;
	Tree<int,std::string> tr_1;

	tr_1.Add(10, "first");
	std::cout << tr_1.GetKey() << std::endl;
	std::cout << tr_1.GetValue() << std::endl;
	tr_1.SetValue(10, "new first");
	tr_1.Add(11, "thrid");
	std::cout << tr_1.FindKey(11) << std::endl;
	std::cout << tr_1.FindKey(10) << std::endl;
	std::cin >> index;
	try {
		f1(index);
		tr_1.Add(index, "New");
	}
	catch (...) {
		std::cout << "Error index enter!!!" << std::endl;
	}
	try {
		f2(index,tr_1);
	}
	catch (...) {
		std::cout << "Error print info !!! " << std::endl;
	}
	





	system("Pause");
	return 0;
}


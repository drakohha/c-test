#include "m1.h"
#include <iostream>
#include <string>



template<typename Key, typename Value>
Tree<Key, Value>::Tree() {

}



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


int main() {


	Tree<int,std::string> tr_1;

	tr_1.Add(10, "first");
	std::cout << tr_1.GetKey() << std::endl;
	std::cout << tr_1.GetValue() << std::endl;
	tr_1.SetValue(10, "new first");
	std::cout << tr_1.GetValue() << std::endl;
	system("Pause");
	return 0;
}


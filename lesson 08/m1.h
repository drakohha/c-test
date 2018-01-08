#pragma once



template<typename Key,typename Value>
class Tree {

struct TreeItem {
		Key _Key;
		Value _Value;
		TreeItem* left = nullptr;
		TreeItem* right = nullptr;
		
	};



public:
	Tree();
	void Add(Key data, Value data_2);
	void Delete(Key data, Value data_2);
	Key GetKey()const;
	Value GetValue() const;
	void SetValue(Key data, Value data_2);
	Key FindValue(Value data) const;
	Value FindKey(Key data) const;
	
private:
	TreeItem * _data=nullptr;
	
};
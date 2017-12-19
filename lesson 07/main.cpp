#include "m1.h"
#include <iostream>

template<typename T>
Stack<T>::Stack(std::initializer_list<T> const& list) {
	for (auto& item : list) {
		PushBack(item);
	}
}
template<typename T>
void Stack<T>::fun_1() {
	while (_tail) {
		StackItem* item = _tail;
		_tail = item->previous;
		delete item;
	}
}

template<typename T>
Stack<T>::~Stack() {
	fun_1();
}
template<typename T>
Stack<T>::Stack(Stack const& stack) {
	ReverseInsert(stack._tail);
}
template<typename T>
void Stack<T>::PushBack(T const& data) {
	StackItem *item = new StackItem;
	item->data = data;
	item->previous = _tail;
	_tail = item;
}
template<typename T>
T Stack<T>::PopBack() {
	if (_tail) {
		T data(std::move(_tail->data));

		StackItem *item = _tail;
		_tail = _tail->previous;

		delete item;
		return std::move(data);
	}
	return T();
}
template<typename T>

std::size_t Stack<T>::Count() const {
	std::size_t count = 0;
	StackItem* item = _tail;
	while (item) {
		item = item->previous;
		count++;
	}
	return count;
}
template<typename T>
void Stack<T>::ReverseInsert(StackItem* item) {
	if (item->previous != nullptr) {
		ReverseInsert(item->previous);
	}
	PushBack(item->data);
}

template<typename T>
void Stack<T>::print()const {
	StackItem* item = _tail;
	while (item) {
		std::cout << item->data << std::endl;
		item = item->previous;
	}
}

template<typename T>
void Stack<T>::operator=(Stack const& st) {
	fun_1();
	ReverseInsert(st._tail);
}

template<typename T>
T& Stack<T>::operator[](int index) {
	//if (Count() <= index) {
	//	std::cout << "Error index";
	//
	//	return std::string (" error ");
	//}
	StackItem* item = _tail;
	int temp=0;
	while (temp!=index) {
		
		item = item->previous;
		temp++;
	}
	return item->data;
}

template<typename T>
T& Stack<T>::operator[](int index)const {
	//if (Count() <= index) {
	//	std::cout << "Error index";
	//	return std::string(" error ");
	//}
	StackItem* item = _tail;
	int temp = 0;
	while (temp != index) {

		item = item->previous;
		temp++;
	}
	return item->data;
}

template<typename T>
void Stack<T>::Insert(size_t count, T data_new) {
	StackItem* item = _tail;
	int temp = 0;
	while (temp != count) {

		item = item->previous;
		temp++;
	}
	item->data = data_new;
}

template<typename T>
void Stack<T>::Remove(size_t count) {
	StackItem* item = _tail;
	int temp = 0;
	while (temp != count) {

		item = item->previous;
		temp++;
	}
	delete item->data;

}

int main() {

	Stack<std::string> st1;
	st1.PushBack("abc");
	st1.PushBack("123");
	st1.PushBack("drakohha");
	std::cout << st1.Count() << std::endl;
	std::cout << "vuvod na ekrat stacka : " << std::endl;
	st1.print();
	Stack<std::string> st2;
	st2 = st1;
	std::cout << "vuvod elementa 0:";
	std::cout << st1[0] << std::endl;
	std::cout << "vuvod elementa 1:";
	std::cout << st1[1] << std::endl;
	std::cout << "vuvod elementa 2:";
	std::cout << st1[2] << std::endl;
	//std::cout << "vuvod elementa 3:";
	//std::cout << st1[3] << std::endl;
	st1.Insert(1, "Igor");
	std::cout << "vuvod elementa 1:";
	std::cout << st1[1] << std::endl;
	st1[1] = "ne igor";
	std::cout << "vuvod elementa 1:";
	std::cout << st1[1] << std::endl;

	system("Pause");
	return 0;
}
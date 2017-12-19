#pragma once
#include <initializer_list>
#include <cstddef>
#include <string>
#include <initializer_list>

template<typename T>
class Stack {
	struct StackItem {
		T data;
		StackItem* previous = nullptr;
	};
public:
	Stack() = default;
	Stack(std::initializer_list<T> const& list);
	~Stack();
	Stack(Stack const& stack);
	void PushBack(T const& data);
	T PopBack();
	void operator=(Stack const& st);
	std::size_t Count() const;
	void print()const;
	void fun_1();
	T& operator[](int idex);
	T& operator[](int idex)const;
	void Insert(size_t count, T data);
	void Remove(size_t count);
private:
	void ReverseInsert(StackItem* item);

	StackItem* _tail = nullptr;
};
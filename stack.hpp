#pragma once
#include <iostream>

template <typename T> class stack {
public:
	void push(const T&);
	void pop();
	T& top();
	int size() const;

private:
	T storage[64];
	int top_index = 0;
};

template <typename T>
void stack<T>::push(const T& x) {
	storage[top_index] = x;
	++top_index;
}

template <typename T> 
void stack<T>::pop() {
	--top_index;
}

template <typename T>
T& stack<T>::top() {
	return storage[top_index - 1];
}

template <typename T>
int stack<T>::size() const {
	return top_index;
}
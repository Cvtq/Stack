#pragma once
#include <vector>

template <typename T>
class Stack
{
private:
	std::vector<T> _stack;
	size_t _size = 0;
public:	

	Stack() {

	}

	void Push(T item) {
		this->_stack.push_back(item);
		this->_size++;
	}

	T Pop() {
		T element;
		if (this->size() > 0) {
			element = _stack.back();
			this->_stack.pop_back();
			this->_size--;			
		}
		return element;
	}

	T Peek() {
		T element = _stack.back();
		return element;
	}

	size_t size() {
		return this->_size;
	}

	bool stackEmpty() {
		if (this->_size == 0) {
			return true;
		}
		return false;
	}
};


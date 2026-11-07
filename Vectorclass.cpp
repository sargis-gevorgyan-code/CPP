#include "Vectorclass.h"
#include <iostream>

/*

// public functions
template <class T>
Vector<T>::Vector() {
	_data = new T[_capacity];
}
template <class T>
Vector<T>::Vector(const T value) {
	setCapacity(5);
	setSize(1);
	_data = new T[_capacity];
	_data[0] = value; 
}
template <class T>
Vector<T>::Vector(const T* array,const size_t size) {
	if (_capacity <= size) {
		setCapacity(size * 2);
	}
	setSize(size);
	_data = new T[_capacity];
	for (int i = 0; i < _size; i++) {
		_data[i] = array[i];
	}
}
template <class T>
Vector<T>::~Vector() {
	delete[] _data;
	_data = nullptr;
 }



template <class T>
const size_t Vector<T>::size() {
	return _size;
}

template <class T>
void Vector<T>::printVector() {
	if (_size > 0) {
		for (int i = 0; i < _size; i++) {
			std::cout << _data[i] << " ";
		}
		std::cout << std::endl;
	} else {
		std::cout << "Vector is empty" << std::endl;
	}
}

template <class T>
void Vector<T>::pop_back() {
	if (_size > 0) {
		_size--;
		if (_capacity > 3 * _size) {
			updateCapacity(_size);
		}
	}
}

template <class T>
void Vector<T>::push_back(T value) {
	if (_capacity  <= _size) {
		updateCapacity(_size + 1);
	}
	_data[_size] = value;
	_size++;

}

// operators override

template <class T>
T& Vector<T>::operator[]	(const size_t index) {
	if (index < _size) {
		return _data[index];
	}
}

template <class T>
Vector<T>& Vector<T>::operator= (const Vector<T>& rightVector) {
	if (this == &rightVector) {
		return *this;
	}
	delete[] this->_data;
	this->_capacity = rightVector._capacity;
	this->_size = rightVector._size;
	this->_data = new T[_capacity];

	for (int i = 0; i < this->_size; i++) {
		this->_data[i] = rightVector._data[i];
	}
	return *this;
}

template <class T>
Vector<T> Vector<T>::operator+ (const Vector<T>& rightVector) {
	Vector<T> sum;
	sum = *this;

	if (sum._capacity < sum._size + rightVector._size) {
		sum.updateCapacity(sum._size + rightVector._size);
	}

	for (int i = 0; i < rightVector._size; i++) {
		sum._data[sum._size + i] = rightVector._data[i];
	}
	sum._size += rightVector._size;
	
	return sum;
	
}


// private functions
template <class T>
void Vector<T>::updateCapacity(const size_t newSize) {
		std::cout << "Updating capacity..." << std::endl;
		T* temp = _data;
		_capacity = newSize * 2;
		_data = new T[_capacity];
		for (int i = 0; i < _size; i++) {
			_data[i] = temp[i];
		}
		delete[] temp;
		temp = nullptr;
}


template <class T>
void Vector<T>::setCapacity(const size_t capacity) {
	_capacity = capacity;
}

template <class T>
void Vector<T>::setSize(const size_t size) {
	_size = size;
}

*/
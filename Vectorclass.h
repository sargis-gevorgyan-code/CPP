//Vectorclass.h
#ifndef VECTORCLASS_H
#define VECTORCLASS_H
#include <iostream>

template <class T>
class Vector {
public:
	Vector();
	Vector(const Vector<T>& rightVector);
	Vector(const T value);
	Vector(const T* array, const size_t size);
	~Vector();
	
	const size_t size();
	void printVector();
	void pop_back();
	void push_back(T value);
	void pop_front();
	void push_front(T value);

	

	T& operator[] (const size_t index);
	Vector<T>& operator= (const Vector<T>& rightVector);
	Vector<T> operator+ (const Vector<T>& rightVector);
	bool operator== (const Vector<T>& rightVector);
	bool operator!= (const Vector<T>& rightVector);



private:
	T* _data = nullptr;
	size_t _capacity = 0;
	size_t _size = 0;


	
	void updateCapacity(const size_t size);

	void setCapacity(const size_t capacity);
	void setSize(const size_t size);
};

////////////////////////////////////         FUNCTION IMPLEMENTATIONS        //////////////////////////////////////////////////////////



// public functions
template <class T>
Vector<T>::Vector() {
}

template <class T>
Vector<T>::Vector(const Vector<T>& rightVector) {
	*this = rightVector;
}

template <class T>
Vector<T>::Vector(const T value) {
	setCapacity(5);
	setSize(1);
	_data = new T[_capacity];
	_data[0] = value;
}
template <class T>
Vector<T>::Vector(const T* array, const size_t size) {
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
			std::cout << _data[i] << "\t";
		}
		std::cout << std::endl;
	}
	else {
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
	if (_capacity <= _size) {
		updateCapacity(_size + 1);
	}
	_data[_size] = value;
	_size++;

}

template <class T>
void Vector<T>::pop_front() {
	if (_size > 0) {
		for (int i = 0; i < size() - 1; i++) {
			this[i] = this[i + 1];
		}
		pop_back();
	}
}

template <class T>
void Vector<T>::push_front(T value) {
	if (_capacity <= _size) {
		updateCapacity(_size + 1);
	}
	_size++;
	for (int i = size() - 1; i > 0; i--) {
		_data[i] = _data[i - 1];
	}
	_data[0] = value;
	
}

// operators override

template <class T>
T& Vector<T>::operator[](const size_t index) {
	if (index >= _size) {
		throw std::out_of_range("Vector index out of range");
	}

		return _data[index];
 
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

template <class T>
bool Vector<T>::operator== (const Vector<T>& rightVector) {
	if (this == &rightVector) {
		return true;
	}
	if (this->_size != rightVector._size) {
		return false;
	}
	for (int i = 0; i < this->_size; i++) {
		if (this->_data[i] != rightVector._data[i]) {
			return false;
		}
	}
	return true;
}

template <class T>
bool Vector<T>::operator!= (const Vector<T>& rightVector) {
	return !(*this == rightVector);
}


// private functions



template <class T>
void Vector<T>::updateCapacity(const size_t newSize) {
	//std::cout << "Updating capacity..." << std::endl;
	/*std::cout << "_size = " << _size
		<< ", _capacity = " << _capacity
		<< ", newSize = " << newSize << std::endl;
		*/
	T* temp = _data;
	_capacity = newSize * 2;

	//std::cout << "Allocating capacity: " << _capacity << std::endl;

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



#endif 




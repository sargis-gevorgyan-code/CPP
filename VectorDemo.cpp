//VectorDemo.cpp
#include <iostream>
#include "Vectorclass.h"

int main() {

	Vector first('2');

	for (int i = 0; i < 10; i++) {
		first.push_back('h');
	}

	std::cout << "First Vector: ";
	first.printVector();


	Vector<char> second;

	for (int i = 0; i < 5; i++) {
		second.push_back((char)i);
	}


	std::cout << "Second Vector: ";
	second.printVector();


	Vector third = first;


	std::cout << "Third Vector: ";
	third.printVector();



	std::cout << "Is first == third: " << (first == third) << std::endl;

	std::cout << "Is first != third: " << (first != third) << std::endl;

	std::cout << "Is second == third: " << (second == third) << std::endl;

	std::cout << "Is second != third: " << (second != third) << std::endl;











	std::cout << "\n\n\n\n\n" << std::endl;

	Vector<int> myVector;
	
	for (int i = 0; i < 10; i++) {
		myVector.push_back(i);
		myVector.printVector();
	}
	for (int i = -9; i < 0; i++) {
		myVector.push_front(i);
		myVector.printVector();
	}

	return 0;
}
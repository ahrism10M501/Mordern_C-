#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

template<typename T>
T add(T const& a, T const& b) {
	return a + b;
}

template<>
char* add<char*>(char* const& a, char* const& b) {
	char* res = new char[strlen(a) + strlen(b) + 1];
	strcpy(res, a);
	strcat(res, b);
	return res;
}

/*
int main() {
	int intA = 10, intB = 20;
	std::cout << "int add: " << add(intA, intB) << "\n";
	double doubleA = 5.5, doubleB = 4.3;
	std::cout << "double add: " << add(doubleA, doubleB) << "\n";
	char strA[] = "Hello, ";
	char strB[] = "World!";
	char* strC = add<char*>(strA, strB);
	std::cout << "char* add: " << strC << "\n";
	delete[] strC;
	return 0;
}
*/
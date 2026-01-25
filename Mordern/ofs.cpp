#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define EXAMPLE 2

// the way of making namespaces in C++
namespace Space1 {
	int value = 1;
}

namespace Space2 {
	int value = 2;
}

int main(void) {
#if EXAMPLE == 1
	ofstream ofs;
	ofs.open("file.txt");
	ofs.write("Hello, World!", 13);

	// tellep으로 파일의 현재 커서 위치 찾기
	long pos = ofs.tellp();

	// 현재 위치에서 7만큼 위치를 뒤로 이동
	ofs.seekp(pos - 7);

	ofs.write("file", 4);

	ofs.close();

#elif EXAMPLE==2
	using salary = double;
	using point = int;

	salary sangwon = 125.20;
	salary peter = 100.20;

	// auto type deduction
	auto a1 = 2;
	auto a2 = 3.5;
	auto a3 = 'c';
	cout << "a1: " << a1 << ", a2: " << a2 << ", a3: " << a3 << endl;

	// decltype didn't assign value, just assign type  
	decltype (a1) b1 = 5;
	decltype (a2) b2 = 7.5;
	cout << "b1: " << b1 << ", b2: " << b2 << endl;
#endif
	return 0;
}
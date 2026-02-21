// #define THREAD_CPP
#ifdef THREAD_CPP

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

ull EvenSum = 0;
ull OddSum = 0;

void findEven(ull start, ull end) {
	ull locals = 0; // 만약 EvenSum에 직접 더한다면, 다른 스레드가 OddSum을 계산하는 동안 EvenSum이 변경될 수 있다 (만약 oddsum과 evensum이 같은 캐시 라인에 있다면, 데이터 무결성을 위해 계속 데이터를 읽어오는 작업이 병행되어 오히려 느려질 수 있다) 따라서 지역 변수를 사용하여 계산한 후, 최종적으로 EvenSum에 할당하는 것이 안전하다.
	for (ull i = start; i <= end; ++i) {
		if ((i & 1) == 0) {
			locals += i;
		}
	}
	EvenSum = locals;
}

void findOdd(ull start, ull end) {
	ull locals = 0;
	for (ull i = start; i <= end; ++i) {
		if ((i & 1) == 1) {
			locals += i;
		}
	}
	OddSum = locals;
}

int main() {

	cout << "Program started...\n";

	ull start = 0, end = 1900000000;
	
	auto startTime = high_resolution_clock::now();

	std::thread t1(findEven, start, end);
	std::thread t2(findOdd, start, end);

	t1.join();
	t2.join();

	auto endTime = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(endTime - startTime);

	cout << "Odd Sum: " << OddSum << endl;
	cout << "Even Sum: " << EvenSum << endl;
	cout << "Time taken: " << duration.count() << " ms" << endl;

	OddSum = 0;
	EvenSum = 0;

	startTime = high_resolution_clock::now();

	findOdd(start, end);
	findEven(start, end);

	endTime = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(endTime - startTime);

	cout << "Odd Sum: " << OddSum << endl;
	cout << "Even Sum: " << EvenSum << endl;
	cout << "Time taken: " << duration.count() << " ms" << endl;

	return 0;
}

#endif
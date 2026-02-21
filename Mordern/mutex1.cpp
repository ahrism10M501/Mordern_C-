// #define MUTEX1_CPP
#ifdef MUTEX1_CPP

#include <iostream>
#include <thread>

// mutex? the solver of the Race Condition Problem
// Race Condition: when two or more threads access the same resource at the same time, and at least one of them is modifying the resouce, it can lead to unprecitable results.
// 

#include <iostream>
#include <thread>
#include <mutex>

int myAmount = 0;
std::mutex mtx;

void addMoney() {
	++myAmount;
}

void addMoney2() {
	mtx.lock(); // lock the mutex before accessing the shared resource
	++myAmount;
	mtx.unlock(); // unlock the mutex after accessing the shared resource
}

int main(void) {
	std::thread t1(addMoney);
	std::thread t2(addMoney);

	t1.join();
	t2.join();

	std::cout << myAmount << std::endl;
	// the output of this program may be 1 or 2, it is not deterministic

	// with mutex, we can guarantee that the output will always be 2
	myAmount = 0;
	std::thread t3(addMoney2);
	std::thread t4(addMoney2);

	t3.join();
	t4.join();

	std::cout << myAmount << std::endl;

	return 0;
}

#endif
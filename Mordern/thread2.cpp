// #define THREAD2_CPP
#ifdef THREAD2_CPP

// the way of creating thread

// If we create multiple threads ar the same time, it doesn't quarantee the which one will be executed first. So the output of this program may be different each time we run it.

#include <iostream>
#include <thread>

void fun(int x) {
	while (x-- > 0) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}

class Base {
public:

	void run(int x) {
		while (x-- > 0) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}

	static void staticRun(int x) {
		while (x-- > 0) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}

	void operator()(int x) {
		while (x-- > 0) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}
};

int main(void) {

	// 1. Create thread with function pointer
	
	std::thread t(fun, 11);

	t.join();

	// 2. create thread with lambda function

	auto fun2 = [](int x) {
		while (x-- > 0) {
			std::cout << x << " ";
			}
		std::cout << std::endl;
		};

	std::thread t2(fun2, 12);
	t2.join();

	// 3. Create thread with function object

	std::thread t3(Base(), 13);
	t3.join();

	// 4. Non-static member function

	Base b;
	std::thread t4(&Base::run, &b, 14);
	// If we want to call non-static member function, we need to pass the object pointer as the first argument.
	t4.join();

	// 5. static member function

	std::thread t5(&Base::staticRun, 15);
	t5.join();

	return 0;
}

#endif
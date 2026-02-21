// #define THREAD3_CPP
#ifdef THREAD3_CPP

#include <iostream>
#include <chrono>
#include <thread>

// Once a thread is started, we cannot stop it. We can only wait for it to finish with join() or detach() it to run in the thread object. If we want to stop a thread, we need to use a flag to signal the thread to stop.
// Double join will result into program crash
//if we needed we should check thread is joinable before joining( using joinable() function) or detaching( using detach() function) the thread. If we try to join or detach a thread that is not joinable, it will throw an exception.

void run(int count) {
	while (count-- > 0)
		std::cout << count << " ";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << std::endl;
}

int main() {
	std::thread t1(run, 10);
	std::cout << "main()" << std::endl;
	
	// t1.join();
	// t1.join(); // Error Occured in execute time not a comile time

	/*if (t1.joinable())
		t1.join();*/

	t1.detach(); // the admin of the t1 thread from main thread to OS
	
	if (t1.joinable()) // Double detach also be problem
		t1.detach();

	std::cout << "main() after" << std::endl;

	// if detached, the main thread doesn't wait for the thread to finish its task.
	// When the main thread completes (return), all detached threads r terminated along with the process forcefully
	std::this_thread::sleep_for(std::chrono::seconds(5));

	return 0;
}

#endif
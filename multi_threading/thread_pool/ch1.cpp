#include <iostream>
#include <thread>

void printHelloThread() {
	std::cout << "Hello Thread\n";
}

#if false
int main() {
	std::thread t1(printHelloThread);
	//t1.join();
	t1.detach();

	return 0;
}
#endif
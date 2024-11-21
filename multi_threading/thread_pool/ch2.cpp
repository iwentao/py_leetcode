#include <iostream>
#include <thread>

int a = 1;

std::thread t;
void foo(int& x) {
	x += 1;
}

void foo(int* x) {
	*x += 1;
}

int main() {
	//int a = 1;
	//std::thread t(foo, std::ref(a)); // Use std::ref to convert a to be a ref type
	//t.join();
	int* ptr = new int(1);
	std::thread t2(foo, ptr);
	delete ptr;

	return 0;
}
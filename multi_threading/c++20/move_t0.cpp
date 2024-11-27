#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <thread>

void foo_1() {
	std::string str = "Hello Future";
	std::vector<std::string> v;

	v.push_back(str);
	std::cout << "str: " << str << std::endl;

	v.push_back(std::move(str));
	std::cout << "str: " << str << std::endl;
}

#if false
int main() {
	std::thread t(foo_1);
	t.join();

	return 0;
}
#endif


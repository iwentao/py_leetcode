#include <functional>
#include <map>
#include <iostream>
#include <thread>

using std::make_pair;
using std::map;
using std::cout;
using std::endl;
using std::thread;

void test() {
	map<const char, std::function<double(double, double)>> tab;
	tab.insert(make_pair('+', [](double a, double b) { return a + b; }));
	tab.insert(make_pair('-', [](double a, double b) { return a - b; }));
	tab.insert(make_pair('*', [](double a, double b) { return a * b; }));
	tab.insert(make_pair('/', [](double a, double b) { return a / b; }));

	cout << tab['+'](3.5, 4.5) << endl;
	cout << tab['-'](3.5, 4.5) << endl;
	cout << tab['*'](3.5, 4.5) << endl;
	cout << tab['/'](3.5, 4.5) << endl;
}

int foo(int param) {
	return param;
}

void test_func_1() {
	std::function<int(int)> func = foo;

	int important = 10;
	std::function<int(int)> func2 = [&](int value) -> int {
		return 1 + value + important;
	};
	cout << func(10) << endl;
	cout << func2(10) << endl;
}

void foo2(int a, int b, int c) {
	cout << a << " " << b << " " << c << endl;
}

void test_func_2() {
	auto bindFoo2 = std::bind(foo2, std::placeholders::_1, 1, 2);
	bindFoo2(3);
}

#if false
int main() {
	thread t(test);
	t.join();

	thread t2(test_func_1);
	t2.join();

	thread t3(test_func_2);
	t3.join();

	return 0;
}
#endif
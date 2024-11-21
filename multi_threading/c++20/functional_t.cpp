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

#if false
int main() {
	thread t(test);
	t.join();

	return 0;
}
#endif
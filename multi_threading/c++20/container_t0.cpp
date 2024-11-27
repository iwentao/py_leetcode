#include <iostream>
#include <unordered_map>
#include <map>
#include <thread>
#include <array>
#include <forward_list>

using std::cout;
using std::endl;
using std::unordered_map;
using std::map;
using std::thread;

void test_map() {
	unordered_map<int, std::string> u = {
		{1, "1"},
		{3, "3"},
		{2, "2"}
	};

	map<int, std::string> v = {
		{1, "1"},
		{3, "3"},
		{2, "2"}
	};

	cout << "unordered_map : " << endl;
	for (const auto& n : u)
		cout << " Key:[" << n.first << "] Value:[" << n.second << "]" << endl;

	cout << endl;
	cout << "map : " << endl;
	for (const auto& n : v)
		cout << " Key:[" << n.first << "] Value:[" << n.second << "]" << endl;
}

void foo_container_1(int *p, int len) {
	cout << "*p = " << *p << " len = " << len << endl;
}

void foo_std_array() {
	constexpr int len = 5;
	std::array<int, len> arr = { 1, 4, 2, 3, -1};
	foo_container_1(&arr[0], arr.size());
	foo_container_1(arr.data(), arr.size());
}

void foo_std_forward_list() {

}

#if true
int main() {
	thread t1(test_map);
	t1.join();

	return 0;
}
#endif


#include <memory>
#include <thread>
#include <iostream>

using std::cout;
using std::endl;
using std::thread;
using std::unique_ptr;
using std::shared_ptr;
using std::weak_ptr;

class MyStruct;

void foo() {
	unique_ptr<int> up1 = std::make_unique<int>(2024);
	//unique_ptr<int> up2 = up1; // ERR
	unique_ptr<int> up3 = std::move(up1);
	cout << *up3 << endl;

	unique_ptr<MyStruct[]> myUniqueArray = std::make_unique<MyStruct[]>(5);
}

class MyStruct {
public:
	MyStruct() : val(count) {
		cout << (void*)this << " Hello: " << val << endl;
		MyStruct::count++;
	}

	~MyStruct() {
		cout << (void*)this << " Good Bye: " << val << endl;
		MyStruct::count--;
	}
private:
	int val;
	static int count;
};

int MyStruct::count = 0;

int main() {
	thread t1(foo);
	t1.join();

	return 0;
}
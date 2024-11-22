#include <memory>
#include <thread>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::thread;
using std::unique_ptr;
using std::shared_ptr;
using std::weak_ptr;
using std::string;

class MyStruct;

weak_ptr<int> gw;

void observe() {
	cout << "gw.use_count = " << gw.use_count() << "; \n";
	if (shared_ptr<int> spt = gw.lock())
		cout << " *spt = " << *spt << "\n";
	else
		cout << "gw is expired.\n";
}

void test_weakptr() {
	{
		auto sp = std::make_shared<int>(42);
		gw = sp;

		observe();
	}
	observe();
}

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

// https://www.bilibili.com/video/BV1RD4y1W7hf
struct School;

struct Teacher {
	string name;
	int age;
	shared_ptr<School> school;
	~Teacher() {
		cout << "Teacher destructed.\n";
	}
};

struct School {
	string name;
	shared_ptr<Teacher> principle;
	~School() {
		cout << "School destructed.\n";
	}
};

void test_sharedptr() {
	auto principle = std::make_shared<Teacher>();
	auto university = std::make_shared<School>();

	principle->school = university;
	university->principle = principle;

	cout << "Principle use count = " << principle.use_count() << endl;
	cout << "School use count = " << university.use_count() << endl;
}

int main() {
	thread t1(foo);
	t1.join();

	thread t2(test_weakptr);
	t2.join();

	thread t3(test_sharedptr);
	t3.join();

	return 0;
}
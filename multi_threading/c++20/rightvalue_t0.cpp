// Illustration of std::move, std::forward
// demonstrate left value, right value usage.
// Wentao Sun (wentao.sun@qq.com)
// 2024-11-27

#include <iostream>
#include <utility>

using std::cout;
using std::endl;

void reference(int& v) {
	cout << " Left reference" << endl;
}

void reference(int&& v) {
	cout << " Right reference" << endl;
}

template <typename T>
void pass(T&& v) {
	cout << "	Pass by plain arg : ";
	reference(v);
	cout << "	Pass by std::move:";
	reference(std::move(v));
	cout << "	Pass by std::forward:";
	reference(std::forward<T>(v));
	cout << "	Pass by static_cast<T&&>:";
	reference(static_cast<T&&>(v));
}

#if false
int main() {
	cout << " Pass in right value:" << endl;
	pass(1);

	cout << "\n";

	cout << " Pass in left value:" << endl;
	int v = 1;
	pass(v);

	return 0;
}
#endif

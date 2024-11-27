#include <iostream>

template<typename ... T>
auto sum(T ... t) {
	return (t + ...);
}

template<typename T0>
void printf1(T0 value) {
	std::cout << value << std::endl;
}

template<typename T, typename ... Ts>
void printf1(T value, Ts ... args) {
	std::cout << value << std::endl;
	printf1(args ...);
}

#if false
int main() {
	std::cout << sum(1, 2, 3, 4, 5, 6) << std::endl;
	printf1(1, 2, "123", 1.1);

	return 0;
}
#endif

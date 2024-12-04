import <iostream>;
import <vector>;
import <algorithm>;
import <thread>;
import <array>;
import <numeric>;
import <string>;

void test_vector_1() {
	std::vector<int> v1{ 1, -20, 31, 29, 5, 12, 65 };
	int val = 23;
	auto result = std::find(v1.cbegin(), v1.cend(), val);
	std::cout << "Value " << val << (result == v1.cend() ? " is not present" : " is present") << std::endl;

	constexpr int a1_len = 11;
	std::array<int, a1_len> a1 = { 1, 3, 5, 7, 7, 9, 9, 99, 77, 17, 29 };
	const int val_2 = 7;
	auto a1_count_result = std::count(a1.cbegin(), a1.cend(), val_2);
	std::cout << "Count of " << val_2 << " is " << a1_count_result << std::endl;

	std::vector<int> v2{ 1, 2, 3, 4, 5, 6 };
	auto v2_result = std::accumulate(v2.cbegin(), v2.cend(), 0);
	std::cout << "Sum of v2 is " << v2_result << std::endl;

	std::vector<std::string> v3{ "This ", "is ", "a ", "good ", "opportunity" };
	auto v3_result = std::accumulate(v3.cbegin(), v3.cend(), std::string(""));
	std::cout << "Sum of string array is " << v3_result << std::endl;
}

#if false
int main() {
	std::thread t1(test_vector_1);
	t1.join();

	return 0;
}
#endif

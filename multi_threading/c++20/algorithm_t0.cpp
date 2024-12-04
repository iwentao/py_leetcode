import <iostream>;
import <algorithm>;
import <string>;
import <thread>;
import <vector>;
import <list>;
import <iomanip>;

void test_algorithm_1() {
	std::vector<std::string> roster1{ "Jim", "Bob", "Tom" };
	std::vector<const char*> roster2{ "Jim", "Bob", "Tim" };
	std::vector<std::string> roster3{ "Jim", "Bob", "Tom" };
	std::vector<const char*> roster4{ "Jim", "Bob", "Tim" };
	auto r_result_1 = std::equal(roster2.cbegin(), roster2.cend(),
		roster4.cbegin(), roster4.cend());
	std::cout << std::boolalpha << std::quoted("Is roster1 equal to roster2 ?: ") << r_result_1 << std::endl;

	const char* s1 = "Jim";
	const char* s2 = "Jim";
	std::cout << (s1 == s2 ? "Equal" : "Not equal") << std::endl;

	std::list<int> l1{ 1, 3, 5, 7, 9 };
	for (auto it = l1.crbegin(); it != l1.crend(); ++it)
		std::cout << *it << std::endl;
}

std::string make_plural(size_t ctr, const std::string& word, const std::string& ending) {
	return (ctr > 1) ? word + ending : word;
}

void test_algorithm_2() {
	std::vector<std::string> s1{ "ala", "bbc", "abcd", "efghi", "acd" };
	const int sz = 2;
	auto wc = std::find_if(s1.cbegin(), s1.cend(),
		[sz](const std::string& a) { return a.size() > sz; });
	auto count = s1.end() - wc;
	std::cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer" << std::endl;

	std::for_each(wc, s1.cend(),
		[](const std::string& s) { std::cout << s << " "; });
	std::cout << std::endl;
}

int main() {
	std::thread t1(test_algorithm_1);
	t1.join();

	std::thread t2(test_algorithm_2);
	t2.join();

	return 0;
}

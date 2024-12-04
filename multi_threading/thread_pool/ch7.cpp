import <iostream>;
import <condition_variable>;
import <thread>;
import <mutex>;
import <queue>;
import <string>;

std::queue<int> g_queue;
std::condition_variable g_cv;
std::mutex g_mtx;

void Producer() {
	for (int i = 0; i < 10; ++i) {
		{ // Notice the scope
			std::unique_lock<std::mutex> lock(g_mtx);
			g_queue.push(i);
			g_cv.notify_one();
			std::cout << "Task: " << i << std::endl;
		}

		std::this_thread::sleep_for(std::chrono::microseconds(100));
	}
}

void Consumer() {
	while (1) {
		std::unique_lock<std::mutex> lock(g_mtx);
		g_cv.wait(lock, []() { return !g_queue.empty(); });
		int value = g_queue.front();
		g_queue.pop();
		std::cout << "Consumer: " << value << std::endl;
	}
}

int main() {
	std::thread t1(Producer);
	std::thread t2(Consumer);
	t1.join();
	t2.join();

	return 0;
}
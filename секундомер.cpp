#include <iostream>
#include <thread>
#include <chrono>
int main()
{
	setlocale(0, "Russian");
	std::cout << "Нажимайте пробел для запуска и приостановки секундомера\n";
	char ch;
	auto start = std::chrono::high_resolution_clock::now();
	auto stop = start;
	while (true)
	 {
	if (std::cin.get(ch) && ch == ' ')
	 {
	start = std::chrono::high_resolution_clock::now();
	std::cin.get();
	std::cout << "START\n";
	
	}
	if (std::cin.get(ch) && ch == ' ')
	 {
	stop = std::chrono::high_resolution_clock::now();
	std::cin.get();
	std::cout << "STOP";
	std::cout << "\nTime: " << std::chrono::duration_cast<std::chrono::seconds>(stop - start).count()
	<< " seconds\n";
	
		}
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	
	}
	return 0;
}
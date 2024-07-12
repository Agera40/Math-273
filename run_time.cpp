#include "timer.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <random>
/*
int main() {

	auto sizes = {1000000, 2000000, 3000000, 4000000, 5000000, 6000000, 7000000, 8000000, 9000000};
	std::mt19937 e;
	std::uniform_int_distribution<int> u;
	std::vector<int> nums;
	std::cout << "algorithm\tsize\t\ttime\t\tratio\n";
	timer<std::chrono::milliseconds> my_timer;

	for (auto size : sizes) {
		nums.resize(size);
		for (auto& n : nums) n = u(e);

		my_timer.start();
		std::sort(nums.begin(), nums.end());
		my_timer.stop();
		
		std::cout << "Sort" << "\t\t" << size << "\t\t" << my_timer.count() << " ms\t\t" << my_timer.count() / (size * log2(size)) << "\n";
	}
}
*/
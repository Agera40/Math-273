#include "functions.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>

template <typename Num>
class my_less {
public:
    bool operator()(const Num& a, const Num& b) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        return a < b;
    }
};
/*
int main() {

    std::vector<int> sizes = { 1000000, 2000000, 3000000, 4000000, 5000000, 6000000, 7000000, 8000000, 9000000 };
    std::vector<int> bubble_data = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000 };

    std::mt19937 e;
    std::uniform_int_distribution<int> u;

    timer<std::chrono::milliseconds> my_timer;

    int min_val, target_value;
    bool found;

    int number;
    std::cout << "List of Algorithms: " << std::endl;
    std::cout << "\n";
    std::cout << "1) Bubble Sort " << std::endl;
    std::cout << "2) std::sort " << std::endl;
    std::cout << "3) maximum of a list " << std::endl;
    std::cout << "4) unsorted " << std::endl;
    std::cout << "5) std::binary_search " << std::endl;
    std::cout << "\n";
    std::cout << "Type the number of the algorithm you want to run: ";
    std::cin >> number;
    std::cout << "Algorithm\t\tSize\t\tTime\t\tRatio\t\tTarget\n";

    switch (number) {
    case 1:
        for (auto n : bubble_data) {
            std::vector<int> data(n);
            for (int& num : data)
                num = u(e);
            std::cout << "Bubble Sort\t\t" << n << "\t\t" << my_timer.count() << "ms\t\t" << static_cast<double>(my_timer.count()) / (n * n) << "\n";
            my_timer.start();
            bubbleSort(data);
            my_timer.stop();
        }
        break;
    case 2:
        for (auto n : sizes) {
            std::vector<int> data;
            data.resize(n);
            for (int& num : data)
                num = u(e);

            std::cout << "std::sort\t\t" << n << "\t\t" << my_timer.count() << "ms\t\t" << static_cast<double>(my_timer.count()) / (n * log10(n)) << "\n";
            my_timer.start();
            std::sort(data.begin(), data.end());
            my_timer.stop();
        }
        break;
    case 3:
        for (auto n : sizes) {
            std::vector<int> data;
            data.resize(n);
            for (int& num : data)
                num = u(e);

            std::sort(data.begin(), data.end());
            std::cout << "max_val  \t\t" << n << "\t\t" << my_timer.count() << "ms\t\t" << static_cast<double>(my_timer.count()) / n << "\n";
            my_timer.start();
            findMax(data);
            my_timer.stop();
        }
        break;
    case 4:
        for (auto n : sizes) {
            std::vector<int> data(n);
            for (int& num : data)
                num = u(e);

            target_value = u(e);
            double ratio = static_cast<double>(my_timer.count()) / n;

            my_timer.start();
            int index = searchUnsorted(data, target_value);
            my_timer.stop();

            if (index != -1) {
                std::cout << "unsorted\t\t" << n << "\t\t" << my_timer.count() << "ms\t\t" << ratio << "\t\t" << target_value << std::endl;
            }
            else {
                std::cout << "Target value " << target_value << " not found in the unsorted list " << std::endl;
            }
        }
        break;
    case 5:
        for (auto n : sizes) {
            
            std::vector<int> data;
            data.resize(n);
            for (int& num : data)
                num = 2*u(e);

            std::sort(data.begin(), data.end());
            target_value = 2*u(e)+1;

            my_less<int> slow_less;
            timer<std::chrono::milliseconds> my_timer;
            my_timer.start();
            std::binary_search(data.begin(), data.end(), target_value, slow_less);
            my_timer.stop();

            std::cout << "Binary search\t\t" << n << "\t\t" << my_timer.count() << "ms\t\t" << static_cast<double>(my_timer.count()) / log10(n) << "\t\t" << target_value << std::endl;
        }
        break;
    default:
        std::cerr << "Not a valid option. " << std::endl;
        return 1;
    }
}
*/
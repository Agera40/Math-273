#pragma once
#include <chrono>
#include <vector>
#include <random>

template <typename Units>
class timer {
public:
    void start();
    void stop();
    typename Units::rep count() const;
private:
    std::chrono::steady_clock clock;
    std::chrono::steady_clock::time_point start_time;
    std::chrono::steady_clock::duration elapsed_time;
};

template <typename Units>
void timer<Units>::start() {
    start_time = clock.now();
}

template <typename Units>
void timer<Units>::stop() {
    elapsed_time = clock.now() - start_time;
}

template <typename Units>
typename Units::rep timer<Units>::count() const {
    return std::chrono::duration_cast<Units>(elapsed_time).count();
}

std::vector<int> generateRandomList(int size);
void bubbleSort(std::vector<int>& list);
int findMax(const std::vector<int>& list);
int searchUnsorted(const std::vector<int>& list, int target);

void bubbleSort(std::vector<int>& list) {
    int n = list.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (list[j] > list[j + 1]) {
                std::swap(list[j], list[j + 1]);
            }
        }
    }
}

int findMax(const std::vector<int>& list) {
    int max_val = list[0];
    for (int i = 1; i < list.size(); ++i) {
        if (list[i] > max_val) {
            max_val = list[i];
        }
    }
    return max_val;
}

int searchUnsorted(const std::vector<int>& list, int target) {
    for (int i = 0; i < list.size(); ++i) {
        if (list[i] == target) {
            return i;
        }
    }
    return 1;
}
#pragma once
#include <map>
#include <unordered_map>
#include <chrono>
#include <iostream>


const std::string LITERALS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

#define MAP    std::map<int, int>
#define UN_MAP std::unordered_map<int, int>
#define PAIR   std::pair<int, int>

#define STR_MAP    std::map<std::string, int>
#define STR_UN_MAP std::unordered_map<std::string, int>
#define STR_PAIR   std::pair<std::string, int>

#define SMALL_SIZE 250'000
#define MID_SIZE   2'500'000
#define BIG_SIZE   25'000'000

#define MIN_TIME 500

#define UNIQUE_NUM -1

using namespace std::chrono;


class Timer {
    steady_clock::time_point Start;
    steady_clock::time_point End;

public:
    Timer() {
        Start = End = high_resolution_clock::now();
    }
    ~Timer() {

    }

    void start() {
        Start = high_resolution_clock::now();
    };
    void stop() {
        End = high_resolution_clock::now();
    }

    int duration() {
        return duration_cast<milliseconds>(End - Start).count();
    }

    void print_in_ms() {
        std::cout << "Time: " << duration_cast<milliseconds>(End - Start).count() << " ms\n";
    }
    void print_in_ns() {
        std::cout << "Time: " << duration_cast<nanoseconds>(End - Start).count() << " ns\n";

    }
};

int rand_int(int max = 1'000'000'000, int min = 0);
int rand_int(unsigned int seed, int max, int min = 0);

std::string rand_str(int length);

void print_comment(std::string const& comment, int data);

float avg_time(std::vector<int>& list);
void del_min(std::vector<int>& list);
void del_max(std::vector<int>& list);

template<typename T>
T* create_map(int seed, int size = SMALL_SIZE, int start = 0) {
    T* tmp = new T;

    srand(seed);
    for (int i = 0; i < size; i++) {
        (*tmp)[start++] = rand_int();
    }

    return tmp;
}

template<typename T>
T* create_str_map(int seed, int size = SMALL_SIZE, int lenght = 6) {
    srand(seed);
    T* tmp = new T;

    while (tmp->size() < size) {
        (*tmp)[rand_str(lenght)] = rand_int();
    }

    return tmp;
}

template<typename T>
void print_map(T& map) {
    for (auto [key, value] : map) {
        static int count = 0;
        std::cout << "[" << key << "] " << value << '\n';
        // if (count++ == 100) break;
    }
    std::cout << "\n";
}
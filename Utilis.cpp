#include <iostream>
#include <time.h>

#include "Utilis.h"


int rand_int(int max, int min) {
    return rand() % (max - min + 1) + min;
}

int rand_int(unsigned int seed, int max, int min) {
    srand(seed);
    return rand_int(max, min);
}

std::string rand_str(int length) {
    std::string tmp;

    while (tmp.size() < length) {
        tmp.append(1, LITERALS[rand_int(LITERALS.size())]);
    }

    return tmp;
}

void print_comment(std::string const& comment, int data) {
    std::cout << comment << ": " << data << "\n";
}

float avg_time(std::vector<int>& list) {
    int slice = list.size() / 10 < 1 ? 1 : list.size() / 10;
    for (int i = 0; i < slice; i++) {
        del_max(list);
        del_min(list);
    }

    int time = 0;
    for (auto data : list) {
        time += data;
    }

    return (float)time / list.size();
}

void del_min(std::vector<int>& list) {
    int tmp = list[0];
    int idx = 0;
    for (int i = 1; i < list.size(); i++) {
        if (list[i] < tmp) {
            tmp = list[i];
            idx = i;
        }
    }

    list.erase(list.begin() + idx);
}

void del_max(std::vector<int>& list) {
    int tmp = list[0];
    int idx = 0;
    for (int i = 1; i < list.size(); i++) {
        if (list[i] > tmp) {
            tmp = list[i];
            idx = i;
        }   
    }

    list.erase(list.begin() + idx);
}

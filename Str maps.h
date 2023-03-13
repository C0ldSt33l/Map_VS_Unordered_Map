#pragma once

#include "Utilis.h"


template<typename T>
int clear_str(Timer& timer, int size) {
    T* tmp = create_str_map<T>(time(0), size);

    timer.start();
    tmp->clear();
    timer.stop();

    delete tmp;

    return timer.duration();
}

template<typename T>
int insert_str(Timer& timer, int size) {
    T* tmp = create_str_map<T>(time(0), size);

    srand(time(0));
    timer.start();
    for (int i = 0; i < 100'000; i++)
        tmp->insert(STR_PAIR(rand_str(10), rand_int()));
    timer.stop();

    delete tmp;

    return timer.duration();
}

template<typename T>
int insert_or_assign_str(Timer& timer, int size) {
    T* tmp = create_str_map<T>(time(0), size);

    srand(time(0));
    timer.start();
    for (int i = 0; i < 100'000; i++)
        tmp->insert_or_assign(rand_str(10), UNIQUE_NUM);
    timer.stop();

    delete tmp;

    return timer.duration();
}

template<typename T>
int erase_str(Timer& timer, int size) {
    T* tmp = create_str_map<T>(time(0), size);

    srand(time(0));
    timer.start();
    for (int i = 0; i < 100'000; i++)
        tmp->erase(rand_str(6));
    timer.stop();

    delete tmp;

    return timer.duration();
}

template<typename T>
int swap_str(Timer& timer, int size) {
    T* tmp = create_str_map<T>(time(0), size);
    T* tmp2 = create_str_map<T>(time(0), size / 2, 8);

    timer.start();
    for (int i = 0; i < 10'000'001; i++)
        tmp->swap(*tmp2);
    timer.stop();

    delete tmp;
    delete tmp2;

    return timer.duration();
}

template<typename T>
int merge_str(Timer& timer, int size) {
    T* tmp = create_str_map<T>(time(0), size);
    T* tmp2 = create_str_map<T>(time(0), size, 8);
    
    timer.start();
    tmp->merge(*tmp2);
    timer.stop();

    delete tmp;
    delete tmp2;

    return timer.duration();
}

template<typename T>
int extract_str(Timer& timer, int size) {
    T* tmp = create_str_map<T>(time(0), size);

    srand(time(0));
    timer.start();
    for (int i = 0; i < 1'000'000; i++)
        tmp->extract(rand_str(6));
    timer.stop();

    delete tmp;

    return timer.duration();
}

template<typename T>
int emplace_str(Timer& timer, int size) {
    T* tmp = create_str_map<T>(time(0), size);

    srand(time(0));
    timer.start();
    for (int i = 0; i < 100'000; i++)
        tmp->emplace(rand_str(8), UNIQUE_NUM);
    timer.stop();

    delete tmp;

    return timer.duration();
}

template<typename T>
int emplace_hint_str(Timer& timer, int size) {
    T* tmp = create_str_map<T>(time(0), size);

    auto iter = tmp->begin();
    int rnd = rand_int(size);
    for (int i = 0; i < rnd; i++)
        iter++;

    srand(time(0));
    timer.start();
    for (int i = 0; i < 100'000; i++)
        tmp->emplace_hint(iter, rand_str(8), UNIQUE_NUM);
    timer.stop();

    delete tmp;

    return timer.duration();
}

template<typename T>
int try_emplace_str(Timer& timer, int size) {
    T* tmp = create_str_map<T>(time(0), size);
 
    timer.start();
    for (int i = 0; i < 100'000; i++)
        tmp->try_emplace(rand_str(8), UNIQUE_NUM);
    timer.stop();

    delete tmp;

    return timer.duration();
}

template<typename T>
int find_str(Timer& timer, int size) {
    T* tmp = create_str_map<T>(0, size);

    srand(time(0));
    timer.start();
    for (int i = 0; i < 30'000; i++)
        tmp->find(rand_str(6));
    timer.stop();

    delete tmp;

    return timer.duration();
}
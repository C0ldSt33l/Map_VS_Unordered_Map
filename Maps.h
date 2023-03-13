#pragma once

#include "Utilis.h"


template<typename T>
int clear(Timer& timer, int size) {
    T* tmp = create_map<T>(time(0), size);

    timer.start();
    tmp->clear();
    timer.stop();

    //print_comment("Size", tmp.size());
    delete tmp;

    return timer.duration();
}

template<typename T>
int insert(Timer& timer, int size) {
    T* tmp = create_map<T>(time(0), size);

    srand(time(0));
    timer.start();
    for (int i = 0; i < 100'000; i++)
        tmp->insert(PAIR(rand_int(0, -1'000'000), rand_int()));
    timer.stop();

    //print_comment("Size", tmp.size());
    delete tmp;

    return timer.duration();
}

template<typename T>
int insert_or_assign(Timer& timer, int size) {
    T* tmp = create_map<T>(time(0), size);

    srand(time(0));
    timer.start();
    for (int i = 0; i < 100'000; i++)
        tmp->insert_or_assign(rand_int(0, -1'000'000), UNIQUE_NUM);
    timer.stop();

    //print_comment("Size", tmp.size());
    delete tmp;

    return timer.duration();
}

template<typename T>
int erase(Timer& timer, int size) {
    T* tmp = create_map<T>(time(0), size);

    srand(time(0));
    timer.start();
    for (int i = 0; i < 100'000; i++)
        tmp->erase(rand_int());
    timer.stop();

    //print_comment("Size", tmp.size());
    delete tmp;

    return timer.duration();
}

template<typename T>
int swap(Timer& timer, int size) {
    T* tmp = create_map<T>(time(0), size);
    T* tmp2 = create_map<T>(time(0), size / 2, size + 100);

    timer.start();
    for (int i = 0; i < 10'000'001; i++)
        tmp->swap(*tmp2);
    timer.stop();

    //print_comment("Size", tmp.size());
    delete tmp;
    delete tmp2;

    return timer.duration();
}

template<typename T>
int merge(Timer& timer, int size) {
    T* tmp = create_map<T>(time(0), size);
    T* tmp2 = create_map<T>(time(0), size, size + 100);

    timer.start();
    tmp->merge(*tmp2);
    timer.stop();

    //print_comment("Size", tmp.size());
    delete tmp;
    delete tmp2;

    return timer.duration();
}

template<typename T>
int extract(Timer& timer, int size) {
    T* tmp = create_map<T>(time(0), size);

    srand(time(0));
    timer.start();
    for (int i = 0; i < 1'000'000; i++)
        tmp->extract(rand_int());
    timer.stop();

    //print_comment("Size", tmp.size());
    delete tmp;

    return timer.duration();
}

template<typename T>
int emplace(Timer& timer, int size) {
    T* tmp = create_map<T>(time(0), size);

    srand(time(0));
    timer.start();
    for (int i = 0; i < 100'000; i++)
        tmp->emplace(rand_int(), UNIQUE_NUM);
    timer.stop();

    //print_comment("Size", tmp.size());
    delete tmp;

    return timer.duration();
}

template<typename T>
int emplace_hint(Timer& timer, int size) {
    T* tmp = create_map<T>(time(0), size);

    auto iter = tmp->begin();
    int rnd = rand_int(size);
    for (int i = 0; i < rnd; i++)
        iter++;

    srand(time(0));
    timer.start();
    for (int i = 0; i < 100'000; i++)
        tmp->emplace_hint(iter, rand_int(), UNIQUE_NUM);
    timer.stop();

    //print_comment("Size", tmp.size());
    delete tmp;

    return timer.duration();
}

template<typename T>
int try_emplace(Timer& timer, int size) {
    T* tmp = create_map<T>(time(0), size);

    timer.start();
    for (int i = 0; i < 100'000; i++)
        tmp->try_emplace(rand_int(), UNIQUE_NUM);
    timer.stop();

    //print_comment("Size", tmp.size());
    delete tmp;

    return timer.duration();
}

template<typename T>
int find(Timer& timer, int size) {
    T* tmp = create_map<T>(0, size);

    srand(10);
    timer.start();
    for (int i = 0; i < 1'000'000; i++)
        tmp->find(rand_int());
    timer.stop();

    delete tmp;

    return timer.duration();
}
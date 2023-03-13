#include <iostream>

#include "Utilis.h"
#include "Maps.h"
#include "Str maps.h"


void test(int(*func)(Timer& timer, int size), int size = SMALL_SIZE) {
    Timer timer;
    int total_time = 0;
    int time;
    std::vector<int> list;

    for (int i = 0; 5 > i || MIN_TIME >= total_time; i++) {
        time = func(timer, size);

        list.push_back(time);
        total_time += list[i];
        print_comment("Time", time);
    }
    print_comment("Avg time", avg_time(list));
    std::cout << "\n";
}

void test_for_str(int size) {
    std::cout << "\nCLEAR\n";
    std::cout << "Map:\n";
    test(&clear_str<STR_MAP>, size);
    std::cout << "Un Map:\n";
    test(&clear_str<STR_UN_MAP>, size);

    std::cout << "\nMERGE\n";
    std::cout << "Map:\n";
    test(&merge_str<STR_MAP>, size);
    std::cout << "Un Map:\n\n";
    test(&merge_str<STR_UN_MAP>, size);

    std::cout << "\nEMPLACE\n";
    std::cout << "Map:\n";
    test(&emplace_str<STR_MAP>, size);
    std::cout << "Un Map:\n";
    test(&emplace_str<STR_UN_MAP>, size);

    std::cout << "\nEMPLACE_HINT\n";
    std::cout << "Map:\n";
    test(&emplace_hint_str<STR_MAP>, size);
    std::cout << "Un Map:\n";
    test(&emplace_hint_str<STR_UN_MAP>, size);

    std::cout << "\nTRY_EMPLACE\n";
    std::cout << "Map:\n";
    test(&try_emplace_str<STR_MAP>, size);
    std::cout << "Un Map:\n";
    test(&try_emplace_str<STR_UN_MAP>, size);

    std::cout << "\nINSERT\n";
    std::cout << "Map:\n";
    test(&insert_str<STR_MAP>, size);
    std::cout << "Un Map:\n";
    test(&insert_str<STR_UN_MAP>, size);

    std::cout << "\nINSERT_OR_ASSIGN\n";
    std::cout << "Map:\n";
    test(&insert_or_assign_str<STR_MAP>, size);
    std::cout << "Un Map:\n";
    test(&insert_or_assign_str<STR_UN_MAP>, size);

    std::cout << "\nERASE\n";
    std::cout << "Map:\n";
    test(&erase_str<STR_MAP>, size);
    std::cout << "Un Map:\n";
    test(&erase_str<STR_UN_MAP>, size);

    std::cout << "\nEXTRACT\n";
    std::cout << "Map:\n";
    test(&extract_str<STR_MAP>, size);
    std::cout << "Un Map:\n";
    test(&extract_str<STR_UN_MAP>, size);

    std::cout << "\nSWAP\n";
    std::cout << "Map:\n";
    test(&swap_str<STR_MAP>, size);
    std::cout << "Un Map:\n";
    test(&swap_str<STR_UN_MAP>, size);

    std::cout << "\nFIND\n";
    std::cout << "Map:\n";
    test(&find_str<STR_MAP>, size);
    std::cout << "Un Map:\n";
    test(&find_str<STR_UN_MAP>, size);
}

void test_for_int(int size) {
    std::cout << "\nCLEAR\n";
    std::cout << "Map:\n";
    test(&clear<MAP>, size);
    std::cout << "Un Map:\n";
    test(&clear<UN_MAP>, size);

    std::cout << "\nMERGE\n";
    std::cout << "Map:\n";
    test(&merge<MAP>, size);
    std::cout << "Un Map:\n\n";
    test(&merge<UN_MAP>, size);

    std::cout << "\nEMPLACE\n";
    std::cout << "Map:\n";
    test(&emplace<MAP>, size);
    std::cout << "Un Map:\n";
    test(&emplace<UN_MAP>, size);

    std::cout << "\nEMPLACE_HINT\n";
    std::cout << "Map:\n";
    test(&emplace_hint<MAP>, size);
    std::cout << "Un Map:\n";
    test(&emplace_hint<UN_MAP>, size);

    std::cout << "\nTRY_EMPLACE\n";
    std::cout << "Map:\n";
    test(&try_emplace<MAP>, size);
    std::cout << "Un Map:\n";
    test(&try_emplace<UN_MAP>, size);

    std::cout << "\nINSERT\n";
    std::cout << "Map:\n";
    test(&insert<MAP>, size);
    std::cout << "Un Map:\n";
    test(&insert<UN_MAP>, size);

    std::cout << "\nINSERT_OR_ASSIGN\n";
    std::cout << "Map:\n";
    test(&insert_or_assign<MAP>, size);
    std::cout << "Un Map:\n";
    test(&insert_or_assign<UN_MAP>, size);

    std::cout << "\nERASE\n";
    std::cout << "Map:\n";
    test(&erase<MAP>, size);
    std::cout << "Un Map:\n";
    test(&erase<UN_MAP>, size);

    std::cout << "\nEXTRACT\n";
    std::cout << "Map:\n";
    test(&extract<MAP>, size);
    std::cout << "Un Map:\n";
    test(&extract<UN_MAP>, size);

    std::cout << "\nSWAP\n";
    std::cout << "Map:\n";
    test(&swap<MAP>, size);
    std::cout << "Un Map:\n";
    test(&swap<UN_MAP>, size);

    std::cout << "\nFIND\n";
    std::cout << "Map:\n";
    test(&find<MAP>, size);
    std::cout << "Un Map:\n";
    test(&find<UN_MAP>, size);
}

int main() {
     std::cout << "\nFIND\n";
     std::cout << "Map:\n";
     test(&swap<MAP>, SMALL_SIZE);
     std::cout << "Un Map:\n";
     test(&swap<UN_MAP>, SMALL_SIZE);

    return 0;
}
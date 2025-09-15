#include "../include/memory.h"
#include <cstddef>
#include <iostream>
#include <memory.h>
#include "../include/log.h"

struct test_data {
    size_t size_of_cache;
    size_t size_of_data;
    std::vector<int> data;
    size_t correct_hits;
};

int main() {
    std::vector<test_data> tests = {
        {3, 6,  {1, 2, 3, 1, 2, 3},                   3},
        {3, 7,  {1, 2, 3, 4, 1, 2, 3},                0},
        {2, 6,  {1, 2, 1, 2, 1, 2},                   4},
        {2, 6,  {1, 2, 3, 1, 2, 3},                   0},
        {3, 9,  {1, 2, 3, 4, 2, 5, 2, 3, 2},          3},
        {4, 12, {1, 2, 3, 4, 5, 1, 2, 6, 1, 2, 3, 4}, 2}
    };
    size_t num_of_failed = 0;
    for (size_t i = 0; i < tests.size(); i++) {
        memory mem(tests[i].size_of_cache, tests[i].size_of_data, tests[i].data);
        int cache_hit_count = 0;
        for (int n = 0; n < tests[i].size_of_data; n++) {
            cache_hit_count += mem.memory_lookup(tests[i].data[n]);
        }
        if (cache_hit_count != tests[i].correct_hits) {
            num_of_failed++;
            std::cout << "Test " << i + 1 << ": got " << cache_hit_count << ", expected " << tests[i].correct_hits << std::endl;
        }
    }
    std::cout << "Correct " << tests.size() - num_of_failed << "out of" << tests.size();
    if (num_of_failed == 0) {
        return 0;
    }
    return 1;
}
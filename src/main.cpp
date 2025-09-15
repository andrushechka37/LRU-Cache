#include "../include/memory.h"
#include <iostream>
#include <memory.h>

int main() {
    size_t size_of_cache = 0;
    size_t size_of_data = 0;
    std::cin >> size_of_cache;
    std::cin >> size_of_data;
    std::vector<int> data;
    for (int i = 0; i < size_of_data; i++) {
        int data_object = 0;
        std::cin >> data_object;
        data.push_back(data_object);
    }

    memory_manager<int> mem(size_of_cache, data);
    int cache_hit_count = 0;
    for (int i = 0; i < size_of_data; i++) {
        // LOG_DEBUG(mem.dump_memory();)
        cache_hit_count += mem.get_data(data[i]);
    }
    std::cout << cache_hit_count;
    return cache_hit_count;
}
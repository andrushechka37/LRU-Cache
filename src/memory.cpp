#include "../include/memory.h"
#include <iostream>
#include <memory.h>
#include <sys/_types/_key_t.h>
#include "../include/log.h"

int memory::read_memory(key_t key) {
    return key;
}

bool memory::memory_lookup(key_t key) {
    return cache.cache_lookup(key);
}
void cache_t::update_cache(key_t key) {
    PRINT_DEBUG(std::cout << "cache before update for " << key << std::endl;)
    PRINT_DEBUG(dump_cache();)

    int data = storage->read_memory(key);

    cache.push_back(data);
    using list_it = std::list<int>::iterator;
    list_it new_it= cache.end();
    hash[key] = new_it;
     
    if (get_size() > capacity) {
        list_it lr_elem_it = cache.begin();
        key_t key_victim = *lr_elem_it;
        cache.pop_front();
        hash.erase(key_victim);
    }
    PRINT_DEBUG(std::cout << "cache after update" << std::endl;)
    PRINT_DEBUG(dump_cache();)
}

bool cache_t::cache_lookup(key_t key) {
    if (hash.count(key)) {
        cache.splice(cache.end(), cache, hash[key]);
        return true;
    } else {
        update_cache(key);
        return false;
    }
}

void cache_t::dump_cache() {
    std::cout << "cache size is:" << get_size() << std::endl;
    std::cout << "cache data:" << std::endl;

    for (int i : cache) {
        std::cout << i << std::endl;
    }

}

void memory::dump_memory() {
    std::cout << "------------ mem dump ---------------" << std::endl;
    std::cout << "data size is:" << data.size() << std::endl;
    for (int i = 0; i < data.size(); i++) {
        std::cout << "data[" << i << "] = " << data[i] << std::endl;
    }
    cache.dump_cache();
    std::cout << "------------ mem dump ---------------" << std::endl;
}
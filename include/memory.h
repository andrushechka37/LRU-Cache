#pragma once
#include <cstddef>
#include <list>
#include <unordered_map>
#include <vector>
#include <sys/_types/_key_t.h>

class memory;
class cache_t {
private:
    size_t capacity;
    std::list<int> cache;
    using list_it = std::list<int>::iterator; 
    std::unordered_map<int, list_it> hash;
    memory * storage;

public:
    cache_t(size_t initial_size, memory * storage): capacity(initial_size), cache(), hash(), storage(storage) {}
    bool cache_lookup(key_t key);
    size_t get_size() {return cache.size();}
    void dump_cache();
private:
    void update_cache(key_t key);
};

class memory {
private:
    std::vector<int> data;
    cache_t cache;

public:
    memory(size_t sise_of_cache, size_t size_of_data, std::vector<int> data): cache(sise_of_cache, this), data(data) {}
    bool memory_lookup(int key);
    int read_memory(int key);
    void dump_memory();
};
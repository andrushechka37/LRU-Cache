#pragma once
#include <cstddef>
#include <list>
#include <unordered_map>
#include <vector>
#include <iostream>
#include "../include/log.h"


template <typename memory_object>
class cache_t {
private: // nado?
    size_t capacity;
    std::list<memory_object> cache;
    using list_it = typename std::list<memory_object>::iterator; 
    std::unordered_map<memory_object, list_it> hash;

public:
    cache_t(size_t initial_size): capacity(initial_size), cache(), hash() {}
    size_t get_size() {return cache.size();}

    bool cache_lookup(memory_object data) {
        LOG_DEBUG(std::cout << "I am in cache_lookup looking for " << data << std::endl)
        LOG_DEBUG(dump_cache())
        if (hash.count(data)) {
            cache.splice(cache.end(), cache, hash[data]);
            LOG_DEBUG(std::cout << "Found " << data << "in cache" << std::endl)
            return true;
        } else {
            update_cache(data);
            LOG_DEBUG(std::cout << "Did not found " << data << "in cache" << std::endl)
            return false;
        }
    }

    void dump_cache() {
        std::cout << "cache capacity is: " << capacity << std::endl;
        std::cout << "cache size is: " << get_size() << std::endl;
        std::cout << "cache data: " << std::endl;

        for (int i : cache) {
            std::cout << i << std::endl;
        }
    }

private:
    void update_cache(memory_object data) {
        LOG_DEBUG(std::cout << "cache before adding " << data << std::endl)
        LOG_DEBUG(dump_cache())

        cache.push_back(data);
        using list_it = std::list<int>::iterator;
        list_it new_it= std::prev(cache.end());
        hash[data] = new_it;
        
        if (get_size() > capacity) {
            list_it lr_elem_it = cache.begin();
            memory_object key_victim = *lr_elem_it;
            cache.pop_front();
            hash.erase(key_victim);
        }
        LOG_DEBUG(std::cout << "cache after update" << std::endl)
        LOG_DEBUG(dump_cache())
    }
};


template <typename memory_object>
class request_storage {
private:
    std::vector<memory_object> data;
public:
    request_storage(std::vector<memory_object> data): data(data) {}
    void dump_storage() {
        std::cout << "------------ requests dump ---------------" << std::endl;
        std::cout << "data size is:" << data.size() << std::endl;
        for (int i = 0; i < data.size(); i++) {
            std::cout << "data[" << i << "] = " << data[i] << std::endl;
        }
        std::cout << "------------ requests dump ---------------" << std::endl;
    }
};


template <typename memory_object>
class memory_manager {
    request_storage<memory_object> data;
    cache_t<memory_object> cache;
public:
    memory_manager(size_t cache_capacity, std::vector<memory_object> request_data): data(request_data), cache(cache_capacity) {}
    bool get_data(memory_object data) {
        return cache.cache_lookup(data);
    }
};


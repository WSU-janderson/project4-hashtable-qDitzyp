#ifndef C__CODES_HASH_TABLE_H
#define C__CODES_HASH_TABLE_H
#include <iosfwd>
#include <string>
#include <vector>
#include <optional>
#include <ostream>
#include "HashTableBucket.h"

class HashTable {
    public:
        HashTable(size_t initCapacity = 8);
        bool insert(const std::string key, const size_t& value);
        bool remove(const std::string& key);
        bool contains(const std::string& key) const;
        std::optional<size_t> get(const std::string& key) const;
        size_t& operator[](const std::string& key);
        std::vector<std::string> keys() const;
        double alpha() const;
        size_t capacity() const;
        size_t size() const;
        friend std::ostream& operator<<(std::ostream& os, const HashTable& hashTable);
        int probe(std::vector<size_t> offsets, int attempt, size_t home);

    private:
    std::vector<HashTableBucket> buckets;
    std::vector<size_t> offsets;
    int amFull;
};








#endif
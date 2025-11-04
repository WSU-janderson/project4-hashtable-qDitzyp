#include "HashTable.h"
#include <string>
#include <optional>
#include <ostream>
#include "HashTableBucket.h"
using namespace std;

HashTable::HashTable(size_t initCapacity) {
    vector<HashTableBucket> buckets(initCapacity);
    std::vector<size_t> offsets(initCapacity);
    for (int i = 1; i <= initCapacity; i++) {
        int hold = (rand() % initCapacity);
        while (true) {
            if (offsets[hold] != NULL) {
                offsets[hold] = i;
                break;
            }
            hold = (rand() % initCapacity);
        }
    }
    amFull = 0;
}

bool HashTable::insert(const std::string key, const size_t &value) {
    if (contains(key) == true) {
        return false;
    }
    for (int i = 0; i < buckets.size(); i++) {
        if (buckets[probe(offsets, i, 0)].isEmpty()) {
            buckets[probe(offsets, i, 0)].setKey(key);
            buckets[probe(offsets, i, 0)].setVal(value);
            return true;
        }
    }
    buckets.push_back(HashTableBucket(key, value));
    amFull++;
    vector<size_t> temp(buckets.size());
    for (int i = 1; i <= temp.size(); i++) {
        int hold = (rand() % temp.size());
        while (true) {
            if (temp[hold] != NULL) {
                temp[hold] = i;
                break;
            }
            hold = (rand() % temp.size());
        }
    }
    offsets = temp;
    return true;
}

bool HashTable::contains(const string& key) const{
    for (int i = 0; i < buckets.size(); i++) {
        if (buckets[probe(offsets, i, 0)].getKey() == key) {
            return true;
        }
    }
    return false;
}

std::optional<size_t> HashTable::get(const std::string &key) const {
    for (int i = 0; i < buckets.size(); i++) {
        if (buckets[probe(offsets, i, 0)].getKey() == key) {
            return buckets[probe(offsets, i, 0)].getVal();
        }
    }
}

size_t& HashTable::operator[](const string& key) {

}

std::vector<std::string> HashTable::keys() const {

}


double HashTable::alpha() const{
    return (static_cast<double>(amFull) / static_cast<double>(buckets.size()));
}

size_t HashTable::capacity() const {
    return buckets.size();
}

size_t HashTable::size() const{
    return amFull;
}

ostream& operator<<(ostream& os, const HashTable& hashTable) {

}

int HashTable::probe(std::vector<size_t> offsets, int attempt, size_t home) const{

}

bool HashTable::remove(const string& key){
    for (int i = 0; i < buckets.size(); i++) {
        if (buckets[probe(offsets, i, 0)].getKey() == key){
            buckets[probe(offsets, i, 0)].emptyBucket();
            return true;
        }
    }
    return false;
}
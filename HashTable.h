#ifndef C__CODES_HASH_TABLE_H
#define C__CODES_HASH_TABLE_H
#include <iosfwd>
#include <string>

class HashTable {
    public:
    HashTable(size_t initCapacity = 8);
    bool insert(const std::string key, const size_t& value);
    bool remove(const std::string& key);
    bool contains(const string& key) const;
    std::optional<size_t> get(const string& key) const;
    size_t& operator[](const string& key);
    std::vector<std::string> keys() const;
    double alpha() const;
    size_t capacity() const;
    size_t size() const;
    friend ostream& operator<<(ostream& os, const HashTable& hashTable);
};








#endif
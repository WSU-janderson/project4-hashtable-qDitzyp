//
// Created by bendr on 11/3/2025.
//

#ifndef HASHTABLE_HASHTABLEBUCKET_H
#define HASHTABLE_HASHTABLEBUCKET_H
#include <string>

class HashTableBucket {
    public:
    HashTableBucket();
    HashTableBucket(const std::string& key, const size_t& value);
    void load(const std::string& key, const size_t& value);
    bool isEmpty() const;
    friend std::ostream& operator<<(std::ostream& os, const HashTableBucket& bucket);
    
};


#endif //HASHTABLE_HASHTABLEBUCKET_H
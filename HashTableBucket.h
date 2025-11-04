//
// Created by bendr on 11/3/2025.
//

#ifndef HASHTABLE_HASHTABLEBUCKET_H
#define HASHTABLE_HASHTABLEBUCKET_H
#include <string>

class HashTableBucket {
    enum class BucketType {NORMAL, ESS, EAR};

public:
        HashTableBucket();
        HashTableBucket(const std::string& key, const size_t& value);
        void load(const std::string& key, const size_t& value);
        bool isEmpty() const;
        friend std::ostream& operator<<(std::ostream& os, const HashTableBucket& bucket);
        int getVal() const;
        std::string getKey() const;
        void setKey(std::string newKey);
        void setVal(int newVal);
        void setStatus(int statCode);
        void emptyBucket();

    private:
        std::string key;
        int data;
        BucketType type;
};

#endif //HASHTABLE_HASHTABLEBUCKET_H
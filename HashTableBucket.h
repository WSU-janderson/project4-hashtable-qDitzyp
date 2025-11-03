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
        void getVal(int buckNum);
        void getKey(int value);
        void getVal(std::string key);
        void setKey(int val, std::string key);
        void setVal(std::string key, int newVal);
        void setVal(int buckNum, int newVal);

    private:
        std::string key;
        int data;
        int buckNum;
        BucketType type;
};

#endif //HASHTABLE_HASHTABLEBUCKET_H
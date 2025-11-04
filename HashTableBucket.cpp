//
// Created by bendr on 11/3/2025.
//

#include "HashTableBucket.h"
#include <string>

HashTableBucket::HashTableBucket() {
    type = BucketType::ESS;
}

HashTableBucket::HashTableBucket(const std::string &key, const size_t &value) {
    this->key = key;
    this->data = value;
    type = BucketType::NORMAL;
}

std::string HashTableBucket::getKey() const{
      return this->key;
}

int HashTableBucket::getVal() const{
    return this->data;
}

void HashTableBucket::load(const std::string& key, const size_t& value) {
    this->key = key;
    this->data = value;
    type = BucketType::NORMAL;
}

bool HashTableBucket::isEmpty() const {
    if (this->type == BucketType::ESS || this->type == BucketType::EAR) {
        return false;
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const HashTableBucket& bucket) {

}

void HashTableBucket::setKey(std::string newKey) {
    this->key = newKey;
}
void HashTableBucket::setVal(int newVal) {
    this->data = newVal;
};

void HashTableBucket::emptyBucket() {
    this->key.clear();
    this->data = -1;
    this->type = BucketType::EAR;
}

void HashTableBucket::setStatus(int statCode) {
    if (statCode == 1) {
        type = BucketType::ESS;
    }else if (statCode == 2) {
        type = BucketType::EAR;
    }else {
        type = BucketType::NORMAL;
    }
}




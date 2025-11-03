/**
 * HashTable.cpp
 */
#include <vector>
#include <string>
#include <ostream>
#include <list>
#include <cstring>
#include <utility>
#include "HashTable.h"

using namespace std;




    HashTable::HashTable(size_t initCapacity) {
      vector<list<pair<string, int>>> table;
        string empty = "";
        for (int i= 0; i < initCapacity; i++) {
            table[i].push_back({empty,i});
            HashTableBucket(table[i].back().first,table[i].back().second);
        }

    }
    bool HashTable::insert(std::string key, size_t value) {


    }

    bool HashTable::remove(std::string key) {

    }

    bool HashTable::contains(const std::string& key) const{

    }

    std::optional<int> HashTable::get(const std::string& key) const {

    }

    int& HashTable::operator[](const std::string& key) {

    }

    std::vector<std::string> HashTable::keys() const {

    }

    double HashTable::alpha() const {

    }

    size_t HashTable::capacity() const {

    }

    std::ostream& operator<<(std::ostream& os, const HashTable& hashTable) {

    };
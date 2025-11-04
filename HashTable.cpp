/**
 * HashTable.cpp
 */
#include <vector>
#include <string>
#include <ostream>
#include <list>
#include <cstring>
#include <utility>
#include <algorithm>
#include "HashTable.h"

#include <iostream>

using namespace std;




    HashTable::HashTable(size_t initCapacity) {

        string empty = "";
        for (int i= 0; i < initCapacity; i++) {
        HashTableBucket bucket(empty, i);
            table[i].emplace_back(bucket);
        }

    }
    bool HashTable::insert(std::string key, size_t value) {
        HashTableBucket bucket(key, value);
        /*for (int i = 0; i < table.size(); i++) {
            if (key == table[i].back().key) {
                string kstring = table[i].back().key;
            }
            }*/

            /*for (int i = 1; i < table.size(); i++) {
                if (table[i].back().key == key) {
                    table[i].emplace_back(bucket);

                }

            }*/
    int bucketsprobed = 0;
        while (bucketsprobed < table.size()) {
            if (table[value].empty()) {
                table[bucketsprobed].emplace_back(bucket);
                break;
            }
            value = (bucket.value + 1) % table.size();
            bucketsprobed++;
        }
        const auto duplicate = adjacent_find(table.begin(), table.end());
        if (duplicate != table.end()) {
            cout << "Duplicate!" << endl;
            remove(key);
            return false;
        }

        return true;

        }



    bool HashTable::remove(std::string key) {

        int bucketsprobed = 0;
        while (bucketsprobed < table.size()) {
            if (table[bucketsprobed].back().key == key) {
                table[bucketsprobed].pop_back();
                return true;
            }
            bucketsprobed++;

        }
        return false;

    }

    bool HashTable::contains(const std::string& key) const{
        int bucketsprobed = 0;
        while (bucketsprobed < table.size()) {
            if (table[bucketsprobed].back().key == key) {
            cout << table[bucketsprobed].back().value << endl;
                return true;
            }
            bucketsprobed++;

        }
        return false;
    }

    std::optional<int> HashTable::get(const std::string& key) const {
    int bucketsprobed = 0;
        while (bucketsprobed < table.size()) {
            if (table[bucketsprobed].back().key == key) {
                return table[bucketsprobed].back().value;
            }
            bucketsprobed++;
        }
        throw out_of_range("Key not found");
    }

    int& HashTable::operator[](const std::string& key) {
        vector<list<string>> keys;
        int bucketsprobed = 0;
        while (bucketsprobed < table.size()) {
                  keys[bucketsprobed].push_back(table[bucketsprobed].back().key);
        }
        return table[bucketsprobed].back().value;
    }

    std::vector<std::string> HashTable::keys() const {
        vector<string> keys;
        for (int i = 0; i < table.size(); i++) {
            keys.push_back(to_string(i));
        }
        return keys;
    }

    double HashTable::alpha() const {
    double alpha = static_cast<double>(table.size());
        return alpha;


    }

    size_t HashTable::capacity() const {
     return table.capacity();
    }
    size_t HashTable::size() const {
        return table.size();
    }

    std::ostream& operator<<(std::ostream& os, const HashTable& hashTable) {
        for(int i = 0; i < hashTable.size(); i++) {
            if (hashTable.contains(hashTable.keys()[i] = true)) {
                os << "<";
                os << hashTable.keys()[i] << endl;
                os << ">";
            }

        }
        return os;
    };
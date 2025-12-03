/**
 * HashTable.cpp
 */
#include <vector>
#include <string>
#include <ostream>

#include <cstring>
#include <utility>
#include <algorithm>
#include "HashTable.h"
#include <list>
#include <iostream>
#include <map>

using namespace std;




        HashTable::HashTable(size_t initCapacity) {
        if (initCapacity != 8) {
           for (int i = 0; i < initCapacity; i++) {
               buckets[i] = HashTableBucket(to_string(i),0);
               //buckets.push_back(bucket);
           }
            return;
        }if (initCapacity == 8){
            for (size_t i = 0; i < 8; i++) {
                HashTableBucket bucket = HashTableBucket(to_string(i),0);
                //buckets.push_back(bucket);
            }
            return;
        }

    }
        bool HashTable::insert(std::string key, size_t value) {
        HashTableBucket bucket(key, value);
            int Hash = 0;

            /*if ( > initCapacity) {
            return false;
        }while() {

        }*/

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
        size_t HashTable::size() const {

        }

        std::ostream& operator<<(std::ostream& os, const HashTable& hashTable) {


        }

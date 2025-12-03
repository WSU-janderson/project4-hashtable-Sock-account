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

            //int Hash = 0;
            int keycode = HashString(key);


            if (keycode < 0) {
                keycode = HashInt(keycode);
            }
            HashTableBucket bucket(to_string(keycode), value);

            /*if ( > initCapacity) {
            return false;
        }while() {

        }*/

    }
    int HashString(string key) {
            int hashCode = 0;
            for (char c: key) {
                hashCode += c;
            }
            return hashCode;


}
    int HashInt(int key) {
        key = abs(key);
            return key;
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

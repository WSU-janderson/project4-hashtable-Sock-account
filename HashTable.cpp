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
            buckets.resize(initCapacity);
            for (int i = 0; i < buckets.size(); i++) {
                buckets[i].type = "ESS";
            }
    } //TODO: Deal with collisions
        bool HashTable::insert(std::string key, size_t value) {

            //int Hash = 0;
            int keycode = HashString(key);


            if (keycode < 0) {
                keycode = HashInt(keycode);
            }

            HashTableBucket bucket(to_string(keycode), value);
            int hashindex = keycode % buckets.size();
            if (hashindex > buckets.size() || hashindex < 0) {
                return false;
            } if (buckets[hashindex].type == "normal") {
              cout << "There has been a collision" << endl;
                return false;
            }
            buckets[hashindex] = bucket;
            buckets[hashindex].type = "normal";
            return true;
    }
    int HashTable::HashString(string key) {
            int hashCode = 0;
            for (char c: key) {
                hashCode += c;
            }
            return hashCode;


}
    int HashTable::HashInt(int key) {
        key = abs(key);
            return key;
        }


        bool HashTable::remove(std::string key) {
            int keycode = HashString(key);
            keycode = HashInt(keycode);
            for (int i = 0; i < buckets.size(); i++) {
                if (buckets[i].key == to_string(keycode)) {
                    buckets[i].key = "";
                    buckets[i].value = 0;
                    buckets[i].type = "EAR";
                    return true;
                }
            }
        return false;
        }

        bool HashTable::contains(const std::string& key) const{
            int hashCode = 0;
            for (char c: key) {
                hashCode += c;
            }
            int bucketkey = abs(hashCode);


            for (int i = 0; i < buckets.size(); i++) {
            if (buckets[i].key == to_string(bucketkey)) {
                return true;
            }
        }
            return false;
        }

        std::optional<int> HashTable::get(const std::string& key) const {
            int hashCode = 0;
            for (char c: key) {
                hashCode += c;
            }
            int bucketkey = abs(hashCode);

            for (int i = 0; i < buckets.size(); i++) {
                if (buckets[i].key == to_string(bucketkey)) {
                    return buckets[i].value;
                }
            }
            return nullopt;
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

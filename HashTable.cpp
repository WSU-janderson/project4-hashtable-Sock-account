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
    }



            bool HashTable::insert(std::string key, size_t value) {

            int keycode = HashString(key);
            double load = this->alpha();
            bool collide = false;
            int probe = offset[0];
            int probeIndex = 0;
            if (keycode < 0) {
                keycode = HashInt(keycode);
            }

            HashTableBucket bucket(to_string(keycode), value);
            int hashindex = keycode % buckets.size();

            if (hashindex > buckets.size() || hashindex < 0) {//n times
                return false;
            } if (buckets[hashindex].type == "normal") { //n^2 times
                collide = true;
                while (collide == true) { //n^3 times
                    hashindex = (hashindex + probe) % buckets.size();
                    probeIndex++;
                    if (this->contains(buckets[hashindex].key) == true) {
                        cout << "Key " << key << " already exists" << endl;
                        return false;
                    }
                    if (buckets[hashindex].type == "ESS") {
                        buckets[hashindex] = bucket;
                        buckets[hashindex].type = "normal";
                        return true;
                    }if (buckets[hashindex].type == "normal") {
                        probe = offset[probeIndex];
                        hashindex = (hashindex + probe) % buckets.size();
                    }if (buckets[hashindex].type == "normal" && buckets[hashindex].key == to_string(keycode)) {
                        cout << "duplicate key " << key << endl;
                        return false;
                    }if (probeIndex == offset.size()) {
                        return false;
                    }
                }
            }
            buckets[hashindex] = bucket;
            buckets[hashindex].type = "normal";
            if (load >= 0.5) {
                size_t morph = buckets.size() * 2;
                this->reHash(morph);

            }
            return true;
    }
        void HashTable::reHash(size_t initCapacity) {
            buckets.resize(initCapacity);
            offset.resize(initCapacity);
            //this sets offsetprobe to equal what initCapacity was before the function call
            int offsetprobe = initCapacity / 2;
            //this prevents infinite loops
            int cloneprobe = offsetprobe;
            for (int i = 0; i < offsetprobe; i++) {
                offset[cloneprobe++] = offset[cloneprobe] + 1;
                cloneprobe++;
            }

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
            throw std::out_of_range("Key not found");
        }

        std::vector<std::string> HashTable::keys() const {
            vector<string> keys;
            for (int i = 0; i < buckets.size(); i++) {
                if (buckets[i].type == "normal") {
                    keys.push_back(buckets[i].key);
                }
            }
            return keys;
        }

        double HashTable::alpha() const {
        double load = 0.0; //O(1)
            int BucketsFilled = 0;//O(1)
            for (int i = 0; i < buckets.size(); i++) {
                if (buckets[i].type == "normal") {
                    BucketsFilled++; //O(1)
                }
            }
            load = static_cast<double>(BucketsFilled) / static_cast<double>(buckets.size()); //O(1)
            //The functions time complexity is O(1)


            return load;

        }

        size_t HashTable::capacity() const {
            size_t capacity = 0;
            for (int i = 0; i < buckets.size(); i++) {
                capacity++;
            }
            return capacity;
        }
        size_t HashTable::size() const {
        size_t size = 0;
            for (int i = 0; i < buckets.size(); i++) {
                if (buckets[i].type == "normal") {
                    size++;
                }
            }
            return size;
        }

        std::ostream& operator<<(std::ostream& os, const HashTable& hashTable) {


        }

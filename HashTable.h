/**
 * HashTable.h
 */
#include <optional>
#include <ostream>
#include <string>
#include <vector>

using namespace::std;
class HashTableBucket {

 public:
    string key;
    int value;
    string type;



    HashTableBucket(string key, int value);

    void load(std::string key, int value);

    bool isEmpty() const;

    friend ostream& operator<<(ostream& os, const HashTableBucket& bucket);
};

class HashTable {

    public:
    HashTable(size_t initCapacity = 8);

    bool insert(std::string key, size_t value);

    bool remove(std::string key);

    bool contains(const std::string& key) const;

    std::optional<int>get(const std::string& key) const;

    int& operator[](const std::string& key);

    std::vector<std::string> keys() const;

    double alpha() const;

    size_t capacity() const;

    size_t size() const;

    friend std::ostream& operator<<(std::ostream& os, const HashTable& hashTable);








};



/**
 * HashTable.h
 */
#include <optional>
#include <ostream>
#include <string>
#include <vector>
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

private:


    friend std::ostream& operator<<(std::ostream& os, const HashTable& hashTable);




};



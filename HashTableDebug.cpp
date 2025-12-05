/**
 * HashTableDebug.cpp
 *
 * Write your tests in this file
 */
#include <iostream>
#include <ranges>

#include "HashTable.h"
int main() {

    HashTable h1 = HashTable();
    h1.insert("apple",1);
    //h1.insert("apple",1);
    //h1.remove("apple");
    bool result = h1.contains("apple");
    bool result2 = h1.contains("orange");
    int got = h1.get("apple").value();
    cout << got << endl;
    h1.insert("banana",2);
   int got2 = h1.get("banana").value();
    cout << got2 << endl;
    //This is testing the operator brackets
    int op_brackets = h1["apple"];
    int op_brackets2 = h1["banana"];
    //int op_brackets3 = h1["orange"];
    vector<string> keys = h1.keys();
    double load = h1.alpha();
    size_t capacity = h1.capacity();
    size_t size = h1.size();
    return 0;
}
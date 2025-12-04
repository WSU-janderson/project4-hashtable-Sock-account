/**
 * HashTableDebug.cpp
 *
 * Write your tests in this file
 */
#include <iostream>
#include "HashTable.h"
int main() {

    HashTable h1 = HashTable();
    h1.insert("apple",1);
    //h1.remove("apple");
    bool result = h1.contains("apple");
    bool result2 = h1.contains("orange");
    int got = h1.get("apple").value();
    cout << got << endl;

    return 0;
}
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Creation of an unordered_map
    unordered_map<string, int> mapping;

    // Insertion using pair
    pair<string, int> p = make_pair("love", 25);
    pair<string, int> q("dipansh", 24);
    pair<string, int> r;

    // Modifying the pair q
    q.first = "arun";
    q.second = 21;

    // Insertion using insert function
    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);

    // Insertion using array-like syntax
    mapping["babbar"] = 51;

    // Insertion using initializer list
    mapping.insert({"john", 30});

    // Display size of the map
    cout << "Size of map: " << mapping.size() << endl;

    // Accessing elements
    cout << mapping.at("love") << endl; // Using at() method
    cout << mapping["love"] << endl;    // Using array-like syntax

    // Searching for a key
    cout << mapping.count("lover") << endl; // count() returns 0 if key is not found and 1 if found.
    cout << "Size of map: " << mapping.size() << endl;

    // Using find() method to search for a key
    if (mapping.find("babbar") != mapping.end()) {
        cout << "Found" << endl;
    } else {
        cout << "Not found" << endl;
    }

    // Display size of the map
    cout << "Size of map: " << mapping.size() << endl;

    // Accessing a non-existent key will insert it with a default value of 0
    cout << mapping["kumar"] << endl;

    // Display size of the map after inserting a new key
    cout << "Size of map: " << mapping.size() << endl;

    return 0;
}


/*
Size of map: 5
25
25
0
Size of map: 5
Found
Size of map: 5
0
Size of map: 6
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Ordered Map (sorted by key) && Unordered Map (no order, faster average)
    map<int, int> mp;
    unordered_map<int, int> ump;

    // Insertion in map
    mp[1] = 10;
    mp[2] = 20;
    mp.insert(4, 40);
    ump[1] = 100;
    ump.insert({2, 200});
   
    // Access element
    cout << mp[1] << endl;
    if (mp.find(2)!=mp.end()) cout<<"Found\n"; // Check if key exists
    cout << mp.size() << endl; // Size of map

    // Erase elements
    mp.erase(2);            // erase by key
    mp.erase(mp.begin());   // erase first element

    // Iteration over map
    for (auto it : mp) cout << it.first << " " << it.second << endl;

    // Lower bound (only for ordered map)
    auto it = mp.lower_bound(3);   // first key >= 3
    if (it != mp.end()) cout << it->first << endl;

    
    cout<<mp.count(1)<<endl; // Count (returns 0 or 1 in map)    
    mp.clear(); // Clear all elements
    if(mp.empty()) cout<<"Map is empty\n";  // Check if empty
    return 0;
}
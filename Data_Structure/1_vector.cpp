#include <bits/stdc++.h>
using namespace std;

int main() {

    // Initialization
    vector<int> v1;                  // empty
    vector<int> v2(5);               // size 5, default 0
    vector<int> v3(5, 10);           // size 5, all 10
    vector<int> v4 = {1, 2, 3};      // initializer list

    vector<pair<int,int>> vp;        // pair vector
    vector<tuple<int,int,int>> vt;   // tuple vector
    vector<vector<int>> grid(3, vector<int>(4, 0)); // 2D vector

    // Adding elements
    v1.push_back(10);
    vp.push_back({1,2});
    vt.push_back({1,2,3});

    // Access
    cout << v1[0] << endl;
    cout << v1.front() << endl;
    cout << v1.back() << endl;

    // Tuple access
    cout << get<0>(vt[0]) << endl;
    cout << get<1>(vt[0]) << endl;
    cout << get<2>(vt[0]) << endl;

    // Size 
    cout << v1.size() << endl;
    v1.resize(10);     // change size

    // Insert
    v1.insert(v1.begin() + 1, 99);

    //  Erase
    v1.erase(v1.begin());                  // remove first
    v1.erase(v1.begin(), v1.begin() + 2);  // range

    //  Delete
    v1.pop_back();
    v1.clear();

    //  Check
    if(v1.empty()) cout << "Empty\n";

    //  Iterators
    for(auto it = v4.begin(); it != v4.end(); it++) cout << *it << " ";

    cout << endl;

    // Reverse
    reverse(v4.begin(), v4.end());

    // Sorting
    sort(v4.begin(), v4.end());            // ascending
    sort(v4.rbegin(), v4.rend());          // descending

    // Searching
    auto it = find(v4.begin(), v4.end(), 2);
    if(it != v4.end()) cout << "Found\n";

    // Count
    cout << count(v4.begin(), v4.end(), 2) << endl;

    // Min / Max
    cout << *min_element(v4.begin(), v4.end()) << endl;
    cout << *max_element(v4.begin(), v4.end()) << endl;

    // Sum
    int sum = accumulate(v4.begin(), v4.end(), 0);
    cout << sum << endl;

    return 0;
}
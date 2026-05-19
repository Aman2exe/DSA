#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int> st; // ordered set (sorted, unique)
    unordered_set<int> ust; // unordered set (hashing, unique)

    st.insert(10); st.insert(5); st.insert(20); st.insert(10); // insert, duplicate ignored
    cout<<st.size()<<endl; // size
    if(st.find(5)!=st.end()) cout<<"Found\n"; // check existence
    cout<<st.count(10)<<endl; // count (0 or 1)

    st.erase(5); // erase by value
    st.erase(st.begin()); // erase first element

    for(auto x:st) cout<<x<<" "; cout<<endl; // iteration (sorted)

    auto it=st.lower_bound(10); // first >=10
    if(it!=st.end()) cout<<*it<<endl;
    it=st.upper_bound(10); // first >10
    if(it!=st.end()) cout<<*it<<endl;

    if(!st.empty()) cout<<*st.begin()<<" "<<*st.rbegin()<<endl; // min and max

    st.clear(); // clear
    if(st.empty()) cout<<"Set empty\n"; // check empty

    ust.insert(10); ust.insert(5); ust.insert(20); // insert
    cout<<ust.size()<<endl; // size
    if(ust.find(5)!=ust.end()) cout<<"Found\n"; // check existence

    ust.erase(5); // erase

    for(auto x:ust) cout<<x<<" "; cout<<endl; // iteration (no order)

    ust.clear(); // clear
    if(ust.empty()) cout<<"Unordered set empty\n"; // check empty

    return 0;
}
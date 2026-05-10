#include <bits/stdc++.h>
using namespace std;

int main() {

    // ------------------ STACK ------------------
    stack<int> st;
    st.push(10); st.push(20); st.push(30);   
    cout<<st.top()<< endl;    // Access top element  
    st.pop();  // Remove top   
    cout<<st.size()<< endl; // Size    
    if (st.empty()) cout << "Stack is empty\n"; // Check empty

    // ------------------ QUEUE ------------------
    queue<int> q; q.push(1); q.push(2); q.push(3);
    cout<<q.front()<<" "<<q.back()<<endl;  // front     
    q.pop(); // Remove front  
    cout << q.size() << endl;  // Size   
    if (q.empty()) cout << "Queue is empty\n"; // Check empty
    
    // Min and Max Heap
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {

    // ------------------ PAIR ------------------
    pair<int, int> p1; p1 = {10, 20};
    pair<int, int> p2 = {30, 40};
    cout << p1.first << " " << p1.second << endl;
    p1.first = 100; // Modify 
    p1.second = 200;

    // ------------------ TUPLE ------------------
    tuple<int, int, int> t1; t1 = {1, 2, 3};
    tuple<int, int, int> t2 = {4, 5, 6};
    cout << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1) << endl;
    get<0>(t1) = 100; // Modify

    int a, b, c;
    tie(a, b, c) = t2;
    cout << a << " " << b << " " << c << endl;

    return 0;
}
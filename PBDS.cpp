// Policy based data structure is used when we have to use a ordered set

// It is a implementation of Fenwick tree which is itself a child of Segment tree

// Blog Link : https://codeforces.com/blog/entry/11080

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update


using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;

int main()
{
    pbds X;
    X.insert(1);
    X.insert(2);
    X.insert(4);
    X.insert(8);
    X.insert(16);

    cout<<*X.find_by_order(1)<<endl; // 2                                   //finds the element at index 1 i.e 2
    cout<<*X.find_by_order(2)<<endl; // 4
    cout<<*X.find_by_order(4)<<endl; // 16
    cout<<(end(X)==X.find_by_order(6))<<endl; // true

    cout<<X.order_of_key(-5)<<endl;  // 0                                   // finds the index of element greater than or equal to -5
    cout<<X.order_of_key(1)<<endl;   // 0                                   // similar to lower bound
    cout<<X.order_of_key(3)<<endl;   // 2
    cout<<X.order_of_key(4)<<endl;   // 2
    cout<<X.order_of_key(400)<<endl; // 5


    return 0;
}


// Time Complexity:

// Insertion : O(log(N))
// Deletion  : O(log(N))
// Binary Search: O(log(N))

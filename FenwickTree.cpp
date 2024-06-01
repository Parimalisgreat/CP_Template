#This is Fenwick Tree Code For (POINT UPDATE AND RANGE QUERY)


#include <bits/stdc++.h>
using namespace std;

int n;
//Always remember bit is 1 based

vector<int>bit;

void update(int id,int val)                          //We just do reverse,now we just add that id
{                                                    // value on exponential places
    while(id<=n)
    {
        bit[id]+=val;
        id+=(id & -id);
    }
}

int query(int id)
{
    int ans=0;
    while(id>0)
    {
        ans+=bit[id];
        id-=(id & -id);
    }
    return ans;
}

int main(){

    cin>>n;

    bit = vector<int>(n+1,0);
    vector<int>a(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        update(i,a[i]);
    }

    int q;
    cin>>q;

    while(q--)
    {
        int typeOfQuery;
        cin>>typeOfQuery;


        //Find the sum in the range (L,R)

        if(typeOfQuery == 1)
        {
            int L,R;
            cin>>L>>R;

            int ans=query(R)-query(L-1);               //L and R needs to be 1-based remember

            cout<<ans<<endl;


        }
        else{                                         //Replace the value at that index (We can also add the value at that index)
            int id,val;
            cin>>id>>val;

            update(id,-a[id]);                        // First, make it back to 0

            a[id]=val;                                // Update original input array a
            update(id,a[id]);                         //Update the bit array
        }

    }

}


/*
Time Complexity:


One Update Command: log(N) => If N elements in input array => Nlog(N)
One query Command: log(N)  => If Q query commands => Qlog(N)

Space:

O(N) : bit array space


*/
#include <bits/stdc++.h>
using namespace std;
int ans1=0;
void merge(vector<int>&v,int l,int mid,int r)
{  
    int i=l;
    int j=mid+1;
    
    vector<int>ans(r-l+1);
    int k=0;
    
    while(i<=mid && j<=r)
    {
        if(v[i]<=v[j])
        {
            ans[k++]=v[i];
            i++;
        }
        else
        {
            ans1+=(mid-i+1);
            cout<<i<<" "<<mid<<" "<<j<<endl;
            ans[k++]=v[j];
            j++;
        }
        
    }
    
    while(i<=mid)
    {
        ans[k++]=v[i];
        i++;
    }
    
    while(j<=r)
    {
        ans[k++]=v[j];
        j++;
    }
    
    k=0;
    for(int i=l;i<=r;i++)
    {
        // cout<<v[i]
        v[i]=ans[k++];
    }
    
}
void mergeSort(vector<int>&v,int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int mid=(l+r)/2;
    mergeSort(v,l,mid);
    mergeSort(v,mid+1,r);
    merge(v,l,mid,r);
}
int main() {
    vector<int>v={2,3,1,5,4};
    
    mergeSort(v,0,4);
    
    // for(auto x:v)
    // {
    //     cout<<x<<" ";
    // }
    
    cout<<ans1<<endl;
}


TC: O(Nlog(N))
SC: O(N)
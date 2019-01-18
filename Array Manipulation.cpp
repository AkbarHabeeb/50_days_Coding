#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int main() 
{
    long int n,m,i,l,a,b,k,max,x=0;
    cin>>n>>m;
    vector<int> arr;
    arr.assign(n,0);
    for(i=0;i<m;i++)
    {
        cin>>a>>b>>k;
        arr[a]+=k;
        if( (b+1) <=n )
            arr[b+1]-=k;
    }
    max=0;
    for(i=0;i<n;i++)
    {
        x+=arr[i];
        if(max<x)
            max=x;
    }
    cout<<max;
    return 0;
}

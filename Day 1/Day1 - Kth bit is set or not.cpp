/*
 * 
 * Program to check wheather the kth bit is set or not 
 * 
*/

#include <iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n;
    cin>>k;
    if( n & (1<<(k-1)) )
        cout<<"The kth bit is set";
    else
        cout<<"Unset";
    return 0;
}

/*
Program to find the nearest multiple of 10
*/

#include <iostream>
using namespace std;

int main()
{
    int no;
    cin>>no;
    int a = (no / 10)*10;
    int b = a + 10;
    if(b-no > no-a)
        cout<<a;
    else
        cout<<b;
}

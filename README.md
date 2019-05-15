# 50_days_of_Coding

## Day 1
Program to find whether kth bit is set or not
## Day 2
Finding the nearest multiple of 10
## Day 3
Finding the maximum sum after array manipulation. It involves sum of array prefixing technique. [QLink](https://www.hackerrank.com/challenges/crush/problem)
## Day 4
Singly linked list insertion of node at various level
## Day 5
Singly linked list deletion of nodes based on position and element + deletion of the linked list
## Day 6
Length of a linked list + Checking whether a eleent is present in the list or not
## Day 7
**Dynamic Programming (DP)**
DP comes into the picture when the problem can be sub divided into prolems of siimilar category. It involves
- Memoization (Top Down)
Before finding the value for the node, look up into the table for values. If exist use it else compte it and add in the table
- Tabulation (Bottom Up)
Calculate the all possible values from beginning to the end. (No seperate table needed, since it itself a array of values) And it doesnt have any repeated calculation.
These techniques will improve the calculation time to a great extent Eg. [40th Fib Number](https://www.geeksforgeeks.org/overlapping-subproblems-property-in-dynamic-programming-dp-1/)
To be a DP problem, it should have
- Overlapping Subproblems
- Optimal Substructure 
## Day 8 
**Ugly Numbers**
We can solve them directly using iterative methods or use Memoization in which we use a pattern.
[Question](https://www.geeksforgeeks.org/ugly-numbers/)
```c++
#include<bits/stdc++.h>
using namespace std;
#define MAX 150

int NthUglyNumber(int n)
{
    int ugly[MAX];
    ugly[0] = 1;
    int mul_2 = 2, mul_3 = 3, mul_5 = 5;
    int i2 = 0, i3 = 0, i5 = 0;
    int i;
    for(i=1;i<n;i++)
    {
        ugly[i] = min(mul_2,min(mul_3,mul_5));
        if(ugly[i] == mul_2)
        {
            i2 = i2 + 1;
            mul_2 = ugly[i2] * 2;
        }
        if(ugly[i] == mul_3)
        {
            i3 = i3 + 1;
            mul_3 = ugly[i3] * 3;
        }
        if(ugly[i] == mul_5)
        {
            i5 = i5 + 1;
            mul_5 = ugly[i5] * 5;
        }
    }
    return ugly[i-1];
}

int main()
{
    cout<<NthUglyNumber(150);
    return 0;
}
```

Comment by a person called 'Melc' : 
i2, i3 and i5 are the accessors of overlapping subproblems here.
They are used to calculate the next ugly number of a particular factor using an already known ugly number (in array). It replaces the following code in Solution 1 which get the smallest divisor of a given multiplier (but getting an ugly number is not granted):
while (a%b == 0) 
a = a/b; 
In Solution 2 instead of repeatedly dividing by our factor (2, 3 or 5) to see if we end up with 1, we just multiply one ugly number with the factor to get the next ugly number for this factor.

For exemple let's look only i2:
In first column next_ugly_no for factor of 2, second column i2 (which is incremented before accessing array), third is corresponding ugly number stored in array (ugly[i2]), fourth is i2+1 ugly number stored in array (ugly[i2] after i2 increment) and fifth is calculated next_multiple_of_2:
nmo2 | i2 | [i2] | [i2+1] |next ([i2+1]*2]
2 | 0 | 1 | 2 | 4
4 | 1 | 2 | 3 | 6
6 | 2 | 3 | 4 | 8
8 | 3 | 4 | 5 | 10
10 | 4 | 5 | 6 | 12
12 | 5 | 6 | 8 | 16
16 | 6 | 8 | 9 | 18
18 | 7 | 9 | 10 | 20
20 | 8 | 10 | 12 | 24
24 | 9 | 12 | 15 | 30
...

You can note that some multiple of 2 are missing (14, 22, 26, 28) it is because they are not ugly numbers (only prime factors 2, 3 or 5). You can also note that [i2]*2 = nmo2 because nmo2 is the next multiple of 2 of the previous iteration. Next multiple of 2 is calculated based on previous ugly numbers (of all valid factors), non-ugly numbers cannot give ugly numbers after being multiplied by 2, 3 or 5 so we don't need to calculate for them. i2, i3 and i5 allow us to skip non-ugly numbers. Using only ugly numbers for calculation allow us to not check if they are ugly because we know they are. Note that this is working properly only when ugly array is ordered (which is the case as we fill it bottom up).

**Catalan Number**
It is similar to Fibonacci number, we can just use the formula along with DP techniques
T(n) = Summaztion of i = 0 to n (T(i) * T(n-i-1))
[GFG Link](https://www.geeksforgeeks.org/program-nth-catalan-number/)


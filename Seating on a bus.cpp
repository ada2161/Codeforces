/*
Problem link: http://codeforces.com/problemset/problem/660/B
Problem name: Seating on a bus

Consider 2n rows of the seats in a bus. n rows of the seats on the left and n rows of the seats on the right. Each row can be filled by two people. So the total capacity of the bus is 4n.

Consider that m (m ≤ 4n) people occupy the seats in the bus. The passengers entering the bus are numbered from 1 to m (in the order of their entering the bus). The pattern of the seat occupation is as below:

1-st row left window seat, 1-st row right window seat, 2-nd row left window seat, 2-nd row right window seat, ... , n-th row left window seat, n-th row right window seat.

After occupying all the window seats (for m > 2n) the non-window seats are occupied:

1-st row left non-window seat, 1-st row right non-window seat, ... , n-th row left non-window seat, n-th row right non-window seat.

All the passengers go to a single final destination. In the final destination, the passengers get off in the given order.

1-st row left non-window seat, 1-st row left window seat, 1-st row right non-window seat, 1-st row right window seat, ... , n-th row left non-window seat, n-th row left window seat, n-th row right non-window seat, n-th row right window seat.
If there are multiple answers, you may print any of them. Values of ti can be printed in any order.

Solution:
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef vector <long long> vill;

#define sc(a) scanf("%d",&a)
#define scll(a) scanf("%I64d",&a)
#define pf(a) printf("%d\n",a)
#define pfll(a) printf("%I64d\n",a)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define pb(a) push_back(a)
#define fore(i,a,b) for(i=a;i<=b;i++)

int main()
{
    long long n,m,k=0,i=1;
    vill b;
    scll(n);
    scll(m);
    set<long long> a;
    int temp;
    fore(i,0,n-1){
        sc(temp);
        a.insert(temp);
    }
    i=1;
    while(m>=0){
        if(a.find(i)==a.end()){
            a.insert(i);
            m=m-i;
            if(m<0){
                pf(k);
                break;
            }
            b.pb(i);
            k++;
        }
        i++;
    }
    fore(i,0,k-1){
        printf("%I64d ",b[i]);
    }


    return 0;
}

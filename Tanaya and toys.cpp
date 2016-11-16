/*
Problem link:   http://codeforces.com/problemset/problem/659/C
Problem name: Tanya and toys

In Berland recently a new collection of toys went on sale. This collection consists of 109 types of toys, numbered with integers from 1 to 109. A toy from the new collection of the i-th type costs i bourles.

Tania has managed to collect n different types of toys a1, a2, ..., an from the new collection. Today is Tanya's birthday, and her mother decided to spend no more than m bourles on the gift to the daughter. Tanya will choose several different types of toys from the new collection as a gift. Of course, she does not want to get a type of toy which she already has.

Tanya wants to have as many distinct types of toys in her collection as possible as the result. The new collection is too diverse, and Tanya is too little, so she asks you to help her in this.

Input
The first line contains two integers n (1 ≤ n ≤ 100 000) and m (1 ≤ m ≤ 109) — the number of types of toys that Tanya already has and the number of bourles that her mom is willing to spend on buying new toys.

The next line contains n distinct integers a1, a2, ..., an (1 ≤ ai ≤ 109) — the types of toys that Tanya already has.

Output
In the first line print a single integer k — the number of different types of toys that Tanya should choose so that the number of different types of toys in her collection is maximum possible. Of course, the total cost of the selected toys should not exceed m.

In the second line print k distinct space-separated integers t1, t2, ..., tk (1 ≤ ti ≤ 109) — the types of toys that Tanya should choose.

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

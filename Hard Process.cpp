/*
Problem link:  http://codeforces.com/problemset/problem/660/C
Problem name: Hard Process

You are given an array a with n elements. Each element of a is either 0 or 1.

Let's denote the length of the longest subsegment of consecutive elements in a, consisting of only numbers one, as f(a). You can change no more than k zeroes to ones to maximize f(a).

Input
The first line contains two integers n and k (1 ≤ n ≤ 3·105, 0 ≤ k ≤ n) — the number of elements in a and the parameter k.

The second line contains n integers ai (0 ≤ ai ≤ 1) — the elements of a.

Output
On the first line print a non-negative integer z — the maximal value of f(a) after no more than k changes of zeroes to ones.

On the second line print n integers aj — the elements of the array a after the changes.

If there are multiple answers, you can print any one of them.
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

    //freopen("in.txt","r",stdin); freopen("out.txt","w",stdout); /*uncoment for codejam*/

    int n,k,i,temp,j;
    vi a;
    sc(n);
    sc(k);
    int temp_count=k,counter=0,max_ones=0,max_ones_indx=0,cur_ones=0;

    fore(i,0,n-1){
        sc(temp);
        a.pb(temp);
    }
    fore(i,0,n-1){
        if(j<i){
        j=i;
        cur_ones=0;
        }
        while(j<n){
            temp_count=cur_ones+!a[j];
            if(k<temp_count) break;
            cur_ones+=!a[j];
            j++;
        }
        if(j-i>max_ones){
            max_ones=j-i;
            max_ones_indx=i;
        }
        if(cur_ones>0){
            cur_ones-=!a[i];
        }


    }
    pf(max_ones);
    fore(i,0,n-1){

        if(i>=max_ones_indx&&i<max_ones_indx+max_ones){
                printf("1 ");
        }else{
            printf("%d ",a[i]);
        }

    }
    return 0;
}

/*
Problem link:   http://codeforces.com/problemset/problem/465/B
Problem name: Inbox

Over time, Alexey's mail box got littered with too many letters. Some of them are read, while others are unread.

Alexey's mail program can either show a list of all letters or show the content of a single letter. As soon as the program shows the content of an unread letter, it becomes read letter (if the program shows the content of a read letter nothing happens). In one click he can do any of the following operations:

Move from the list of letters to the content of any single letter.
Return to the list of letters from single letter viewing mode.
In single letter viewing mode, move to the next or to the previous letter in the list. You cannot move from the first letter to the previous one or from the last letter to the next one.
The program cannot delete the letters from the list or rearrange them.

Alexey wants to read all the unread letters and go watch football. Now he is viewing the list of all letters and for each letter he can see if it is read or unread. What minimum number of operations does Alexey need to perform to read all unread letters?

Input
The first line contains a single integer n (1 ≤ n ≤ 1000) — the number of letters in the mailbox.

The second line contains n space-separated integers (zeros and ones) — the state of the letter list. The i-th number equals either 1, if the i-th number is unread, or 0, if the i-th letter is read.

Output
Print a single number — the minimum number of operations needed to make all the letters read.


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
    int n,time=0,i;
    sc(n);
    vi v(n);
    fore(i,0,n-1){
        sc(v[i]);
    }
    fore(i,0,n-1){
        if(v[i]==1){
            time++;
        if(i!=n-1){
            if(v[i+1]==0)
                time++;
        }
        }

    }
    if(v[n-1]==0&&time>0){
        time--;
    }
    pf(time);
    return 0;
}

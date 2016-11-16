/*
Problem link: http://codeforces.com/problemset/problem/463/B
Problem name: Caisa and Pylons

Caisa solved the problem with the sugar and now he is on the way back to home.

Caisa is playing a mobile game during his path. There are (n + 1) pylons numbered from 0 to n in this game. The pylon with number 0 has zero height, the pylon with number i (i > 0) has height hi. The goal of the game is to reach n-th pylon, and the only move the player can do is to jump from the current pylon (let's denote its number as k) to the next one (its number will be k + 1). When the player have made such a move, its energy increases by hk - hk + 1 (if this value is negative the player loses energy). The player must have non-negative amount of energy at any moment of the time.

Initially Caisa stand at 0 pylon and has 0 energy. The game provides a special opportunity: one can pay a single dollar and increase the height of anyone pylon by one. Caisa may use that opportunity several times, but he doesn't want to spend too much money. What is the minimal amount of money he must paid to reach the goal of the game?

Input
The first line contains integer n (1 ≤ n ≤ 105). The next line contains n integers h1, h2, ..., hn (1  ≤  hi  ≤  105) representing the heights of the pylons.

Output
Print a single number representing the minimum number of dollars paid by Caisa.


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

    int n,a[200000],money,energy,i;
    sc(n);
    fore(i,0,n-1){
        sc(a[i]);
    }
    energy=0;
    money=a[0];
    fore(i,0,n-2){
        if(energy+a[i]-a[i+1]<0){
            money+=a[i+1]-a[i]-energy;
            energy=0;
        }else{
            energy+=a[i]-a[i+1];
        }
    }
    pf(money);
    return 0;
}

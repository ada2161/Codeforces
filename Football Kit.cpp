/*
Problem link: http://codeforces.com/problemset/problem/432/B
Problem name: Football Kit

Consider a football tournament where n teams participate. Each team has two football kits: for home games, and for away games. The kit for home games of the i-th team has color xi and the kit for away games of this team has color yi (xi ≠ yi).

In the tournament, each team plays exactly one home game and exactly one away game with each other team (n(n - 1) games in total). The team, that plays the home game, traditionally plays in its home kit. The team that plays an away game plays in its away kit. However, if two teams has the kits of the same color, they cannot be distinguished. In this case the away team plays in its home kit.

Calculate how many games in the described tournament each team plays in its home kit and how many games it plays in its away kit.

Input
The first line contains a single integer n (2 ≤ n ≤ 105) — the number of teams. Next n lines contain the description of the teams. The i-th line contains two space-separated numbers xi, yi (1 ≤ xi, yi ≤ 105; xi ≠ yi) — the color numbers for the home and away kits of the i-th team.

Output
For each team, print on a single line two space-separated integers — the number of games this team is going to play in home and away kits, correspondingly. Print the answers for the teams in the order they appeared in the input.

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
    int n,i;
    sc(n);
    vi a(n);
    vi b(n);
    vi c(200000,0);


    fore(i,0,n-1){
        sc(a[i]);
        sc(b[i]);
        c[a[i]]++;
    }

    fore(i,0,n-1){
        printf("%d %d\n",n-1+c[b[i]],n-1-c[b[i]]);
    }

    return 0;
}

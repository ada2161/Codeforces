/*
Problem link: http://codeforces.com/problemset/problem/463/C
Problem name: Gargari and bishops

Gargari is jealous that his friend Caisa won the game from the previous problem. He wants to prove that he is a genius.

He has a n × n chessboard. Each cell of the chessboard has a number written on it. Gargari wants to place two bishops on the chessboard in such a way that there is no cell that is attacked by both of them. Consider a cell with number x written on it, if this cell is attacked by one of the bishops Gargari will get x dollars for it. Tell Gargari, how to place bishops on the chessboard to get maximum amount of money.

We assume a cell is attacked by a bishop, if the cell is located on the same diagonal with the bishop (the cell, where the bishop is, also considered attacked by it).

Input
The first line contains a single integer n (2 ≤ n ≤ 2000). Each of the next n lines contains n integers aij (0 ≤ aij ≤ 109) — description of the chessboard.

Output
On the first line print the maximal number of dollars Gargari will get. On the next line print four integers: x1, y1, x2, y2 (1 ≤ x1, y1, x2, y2 ≤ n), where xi is the number of the row where the i-th bishop should be placed, yi is the number of the column where the i-th bishop should be placed. Consider rows are numbered from 1 to n from top to bottom, and columns are numbered from 1 to n from left to right.

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
    vill v1(4000);
    vill v2(4000);
    long long n,i,j;
    static long long a[3000][3000];
    scll(n);
    fore(i,0,n-1){
        fore(j,0,n-1){
            sc(a[i][j]);
            v1[i+j]+=a[i][j];
            v2[n+i-j]+=a[i][j];
        }
    }
    long long maxscore=0,curscore,max_x,max_y;
    fore(i,0,n-1){
        fore(j,0,n-1){
            curscore=v1[i+j]+v2[n+i-j]-a[i][j];
            if(curscore>=maxscore){
                maxscore=curscore;
                max_x=i;
                max_y=j;

            }

            }
        }
    long long maxscore2=0,curscore2,max_x1,max_y1;
    fore(i,0,n-1){
        fore(j,0,n-1){
            curscore=v1[i+j]+v2[n+i-j]-a[i][j];
            if(curscore>=maxscore2 && (max_x+max_y-i-j)%2!=0){
                maxscore2=curscore;
                max_x1=i;
                max_y1=j;
            }
            }
        }
        pfll(maxscore+maxscore2);
        printf("%I64d %I64d %I64d %I64d",max_x+1,max_y+1,max_x1+1,max_y1+1);

    return 0;
}

/*
Problem link:  http://codeforces.com/problemset/problem/701/B
Problem name: Cells not under attack

Vasya has the square chessboard of size n × n and m rooks. Initially the chessboard is empty. Vasya will consequently put the rooks on the board one after another.

The cell of the field is under rook's attack, if there is at least one rook located in the same row or in the same column with this cell. If there is a rook located in the cell, this cell is also under attack.

You are given the positions of the board where Vasya will put rooks. For each rook you have to determine the number of cells which are not under attack after Vasya puts it on the board.

Input
The first line of the input contains two integers n and m (1 ≤ n ≤ 100 000, 1 ≤ m ≤ min(100 000, n2)) — the size of the board and the number of rooks.

Each of the next m lines contains integers xi and yi (1 ≤ xi, yi ≤ n) — the number of the row and the number of the column where Vasya will put the i-th rook. Vasya puts rooks on the board in the order they appear in the input. It is guaranteed that any cell will contain no more than one rook.

Output
Print m integer, the i-th of them should be equal to the number of cells that are not under attack after first i rooks are put.

Solution:
*/
#include <iostream>
#include<bits/stdc++.h>
#include <string>
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
#define fore(i,a,b) for(i=a;i<b;i++)

int main()
{
    long long i, ol=0,ow=0,n,m,r,c,att=0;
    cin>>n>>m;
    vector<long long> rw(n);
    vector<long long> cl(n);
    fore(i,0,m){
        cin>>r;
        cin>>c;
        if(rw[r-1]==0&&cl[c-1]==0){
            att+=2*n-1-2*i+ol+ow;
        }else if(rw[r-1]!=0&&cl[c-1]!=0){
            ol++;
            ow++;
        }
        else if(rw[r-1]!=0){
            ol++;
            att+=n-1-i+ol;

        }
        else if(cl[c-1]!=0){
            ow++;
            att+=n-1-i+ow;

        }

        cout<<n*n-att<<"\n";

        rw[r-1]++;
        cl[c-1]++;
    }
    att=n*n;

    return 0;
}

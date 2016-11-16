/*
Problem link: http://codeforces.com/problemset/problem/711/B
Problem name: Chris and Magic Square

ZS the Coder and Chris the Baboon arrived at the entrance of Udayland. There is a n?×?n magic grid on the entrance which is filled with integers. Chris noticed that exactly one of the cells in the grid is empty, and to enter Udayland, they need to fill a positive integer into the empty cell.

Chris tried filling in random numbers but it didn't work. ZS the Coder realizes that they need to fill in a positive integer such that the numbers in the grid form a magic square. This means that he has to fill in a positive integer so that the sum of the numbers in each row of the grid (), each column of the grid (), and the two long diagonals of the grid (the main diagonal —  and the secondary diagonal — ) are equal.

Chris doesn't know what number to fill in. Can you help Chris find the correct positive integer to fill in or determine that it is impossible?

Input
The first line of the input contains a single integer n (1?=?n?=?500) — the number of rows and columns of the magic grid.

n lines follow, each of them contains n integers. The j-th number in the i-th of them denotes ai,?j (1?=?ai,?j?=?109 or ai,?j?=?0), the number in the i-th row and j-th column of the magic grid. If the corresponding cell is empty, ai,?j will be equal to 0. Otherwise, ai,?j is positive.

It is guaranteed that there is exactly one pair of integers i,?j (1?=?i,?j?=?n) such that ai,?j?=?0.

Output
Output a single integer, the positive integer x (1?=?x?=?1018) that should be filled in the empty cell so that the whole grid becomes a magic square. If such positive integer x does not exist, output ?-?1 instead.

If there are multiple solutions, you may print any of them.

Solution:
*/

#include <bits/stdc++.h>
using namespace std;
#define pf pop_front
#define pb push_back
#define FOR(i,begin,end) for (LL i=begin;i<=end;i++)
#define rep(i,t) for (LL i=0;i<t;i++)
#define fore(i,a,b) for (i=a;i<b;i++)
#define pii pair<LL,LL>
#define X first
#define Y second
int main()
{
    long long n,i,j,ini,inj;
    cin>>n;
    long long a[n][n];
    fore(i,0,n){
        fore(j,0,n){
            cin>>a[i][j];
            if(a[i][j]==0){
                ini=i;
                inj=j;
            }
        }
    }
    if(n==1){
        cout<<2;
        return 0;
    }
    long long sum=0,isum=0;
    if(ini>0){
        fore(i,0,n){
            sum+=a[0][i];
        }
    }else{
        fore(i,0,n){
            sum+=a[1][i];
        }
    }

    fore(i,0,n){
        isum+=a[ini][i];
    }
    if(sum-isum>0){
        a[ini][inj]=sum-isum;
    }else{
        printf("-1");
        return 0;
    }
    long long csum=0,rsum=0,dsum=0,d2sum=0;
    fore(i,0,n){
        rsum=0;
        csum=0;
        fore(j,0,n){
            csum+=a[i][j];
            rsum+=a[j][i];
        }
        if(csum!=sum||rsum!=sum){
            printf("-1");
            return 0;
        }
    }
    fore(i,0,n){
        dsum+=a[i][i];
        d2sum+=a[i][n-1-i];
    }
     if(dsum!=sum||d2sum!=sum){
        printf("-1");
        return 0;
    }

    cout<<sum-isum;
    return 0;
}

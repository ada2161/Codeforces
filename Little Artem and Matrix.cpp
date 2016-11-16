/*
Problem link:  http://codeforces.com/problemset/problem/669/C
Problem name: Little Artem and Matrix

Little Artem likes electronics. He can spend lots of time making different schemas and looking for novelties in the nearest electronics store. The new control element was delivered to the store recently and Artem immediately bought it.

That element can store information about the matrix of integers size n × m. There are n + m inputs in that element, i.e. each row and each column can get the signal. When signal comes to the input corresponding to some row, this row cyclically shifts to the left, that is the first element of the row becomes last element, second element becomes first and so on. When signal comes to the input corresponding to some column, that column shifts cyclically to the top, that is first element of the column becomes last element, second element becomes first and so on. Rows are numbered with integers from 1 to n from top to bottom, while columns are numbered with integers from 1 to m from left to right.

Artem wants to carefully study this element before using it. For that purpose he is going to set up an experiment consisting of q turns. On each turn he either sends the signal to some input or checks what number is stored at some position of the matrix.

Artem has completed his experiment and has written down the results, but he has lost the chip! Help Artem find any initial matrix that will match the experiment results. It is guaranteed that experiment data is consistent, which means at least one valid matrix exists.

Input
The first line of the input contains three integers n, m and q (1 ≤ n, m ≤ 100, 1 ≤ q ≤ 10 000) — dimensions of the matrix and the number of turns in the experiment, respectively.

Next q lines contain turns descriptions, one per line. Each description starts with an integer ti (1 ≤ ti ≤ 3) that defines the type of the operation. For the operation of first and second type integer ri (1 ≤ ri ≤ n) or ci (1 ≤ ci ≤ m) follows, while for the operations of the third type three integers ri, ci and xi (1 ≤ ri ≤ n, 1 ≤ ci ≤ m,  - 109 ≤ xi ≤ 109) are given.

Operation of the first type (ti = 1) means that signal comes to the input corresponding to row ri, that is it will shift cyclically. Operation of the second type (ti = 2) means that column ci will shift cyclically. Finally, operation of the third type means that at this moment of time cell located in the row ri and column ci stores value xi.

Output
Print the description of any valid initial matrix as n lines containing m integers each. All output integers should not exceed 109 by their absolute value.

If there are multiple valid solutions, output any of them.

Output
Print m integer, the i-th of them should be equal to the number of cells that are not under attack after first i rooks are put.

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
#define MO 1000000007

int main()
{
    long long mat[101][101],val;
    int q,i,x,y,n,m;
    cin>>n>>m>>q;
    int t[q],k[q],rw[q],cl[q];
    long long va[q];
    vector<pair<pair<int,int>, long long> > a;
    fore(i,0,q-1){
        sc(t[i]);
        if(t[i]==3){
            sc(x);
            sc(y);
            cin>>va[i];
            rw[i]=x;
            cl[i]=y;

        }else{
            sc(k[i]);
        }
    }
    int j;
    fore(i,0,n-1){
        fore(j,0,m-1){
            mat[i][j]=0;
        }
    }
    int r,c,temp,b=0;
    int f=a.size()-1;
    for(i=q-1;i>=0;i--){
        if(t[i]==3){
            mat[rw[i]-1][cl[i]-1]=va[i];

       }else if(t[i]==2){
            c=k[i]-1    ;
            temp=mat[n-1][c];
            for(j=n-1;j>0;j--){
                mat[j][c]=mat[j-1][c];
            }
            mat[0][c]=temp;
        }

        else if(t[i]==1){
            r=k[i]-1;
            temp=mat[r][m-1];
            for(j=m-1;j>0;j--){
                mat[r][j]=mat[r][j-1];

            }
            mat[r][0]=temp;

        }

    }
    fore(i,0,n-1){
        fore(j,0,m-1){
                cout<<mat[i][j];
                cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

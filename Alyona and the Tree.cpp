/*
Problem link: http://codeforces.com/problemset/problem/682/C
Problem name: Alyona and the Tree

Alyona decided to go on a diet and went to the forest to get some apples. There she unexpectedly found a magic rooted tree with root in the vertex 1, every vertex and every edge of which has a number written on.

The girl noticed that some of the tree's vertices are sad, so she decided to play with them. Let's call vertex v sad if there is a vertex u in subtree of vertex v such that dist(v, u) > au, where au is the number written on vertex u, dist(v, u) is the sum of the numbers written on the edges on the path from v to u.

Leaves of a tree are vertices connected to a single vertex by a single edge, but the root of a tree is a leaf if and only if the tree consists of a single vertex — root.

Thus Alyona decided to remove some of tree leaves until there will be no any sad vertex left in the tree. What is the minimum number of leaves Alyona needs to remove?

Input
In the first line of the input integer n (1 ≤ n ≤ 105) is given — the number of vertices in the tree.

In the second line the sequence of n integers a1, a2, ..., an (1 ≤ ai ≤ 109) is given, where ai is the number written on vertex i.

The next n - 1 lines describe tree edges: ith of them consists of two integers pi and ci (1 ≤ pi ≤ n,  - 109 ≤ ci ≤ 109), meaning that there is an edge connecting vertices i + 1 and pi with number ci written on it.

Output
Print the only integer — the minimum number of leaves Alyona needs to remove such that there will be no any sad vertex left in the tree.
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
    vector<vector<pair<long long,long long> > > a;
    vector<long long> b;
    long long dist;
    int n,i,counter=0;
    void dfs(int v,long long ma){
        if(b[v]<ma)
            return;
        counter++;
        long long t=a[v].size();
        long long k;
        fore(k,0,t-1){
            dfs(a[v][k].first,max(a[v][k].second+ma,a[v][k].second));
        }
    }
    int main()
    {
    cin>>n;
    a.resize(n+1);
    b.resize(n+1);

    fore(i,1,n){
        cin>>b[i];
    }
    long long t;
    fore(i,1,n-1){
        cin>>t;
        cin>>dist;
        a[t].pb(make_pair(i+1,dist));
    }
    dfs(1,0);

    cout<<n-counter;

    return 0;
    }

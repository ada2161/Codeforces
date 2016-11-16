/*
Problem link:   http://codeforces.com/problemset/problem/427/C
Problem name: Checkposts
Your city has n junctions. There are m one-way roads between the junctions. As a mayor of the city, you have to ensure the security of all the junctions.

To ensure the security, you have to build some police checkposts. Checkposts can only be built in a junction. A checkpost at junction i can protect junction j if either i = j or the police patrol car can go to j from i and then come back to i.

Building checkposts costs some money. As some areas of the city are more expensive than others, building checkpost at some junctions might cost more money than other junctions.

You have to determine the minimum possible money needed to ensure the security of all the junctions. Also you have to find the number of ways to ensure the security in minimum price and in addition in minimum number of checkposts. Two ways are different if any of the junctions contains a checkpost in one of them and do not contain in the other.

Input
In the first line, you will be given an integer n, number of junctions (1 ≤ n ≤ 105). In the next line, n space-separated integers will be given. The ith integer is the cost of building checkpost at the ith junction (costs will be non-negative and will not exceed 109).

The next line will contain an integer m (0 ≤ m ≤ 3·105). And each of the next m lines contains two integers ui and vi (1 ≤ ui, vi ≤ n; u ≠ v). A pair ui, vi means, that there is a one-way road which goes from ui to vi. There will not be more than one road between two nodes in the same direction.

Output
Print two integers separated by spaces. The first one is the minimum possible money needed to ensure the security of all the junctions. And the second one is the number of ways you can ensure the security modulo 1000000007 (109 + 7).

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
int ft[200000]={0},visited[200000]={0},time1=1,time2=1,m,n;
long long minimum=2000000000,cost=0,ways=0,methods=1,a[200000];
vector<pair<int,int> > pi;
vector <vi> graph;
vector <vi> rev_graph;
void DFS(int k){
    int length=graph[k].size();
    int i;
    if(visited[k]!=0)
        return;

    visited[k]=time1;
    time1++;
    fore(i,0,length-1){
        if(visited[graph[k][i]]==0){
            DFS(graph[k][i]);
           }

    }
    ft[k]=time1;
    time1++;

}
void RDFS(int k){
    int length=rev_graph[k].size(),i;
    if(visited[k]!=0)
        return;

    visited[k]=1;
    fore(i,0,length-1){
        if(visited[rev_graph[k][i]]==0){
            RDFS(rev_graph[k][i]);
           }
    }
    if(a[k]<minimum){
        minimum=a[k];
        ways=0;
    }else if(a[k]==minimum){
        ways++;
    }

}
int main()
{
    int i;

    sc(n);
    fore(i,0,n-1)
        sc(a[i]);

    sc(m);
    int x,y;
    graph.resize(n);
    rev_graph.resize(n);
    pi.resize(n);
    fore(i,0,m-1)
    {
        sc(x);
        sc(y);
        graph[x-1].pb(y-1);
        rev_graph[y-1].pb(x-1);

    }


    fore(i,0,n-1){
        DFS(i);
    }
    fore(i,0,n-1){
        pi[i].first=ft[i];
        pi[i].second=i;
        visited[i]=0;
    }
    sort(rall(pi));
    fore(i,0,n-1){
        minimum=2000000000;
        RDFS(pi[i].second);
        if(minimum!=2000000000){
            cost+=minimum;
            methods=(methods*(ways+1))%1000000007 ;
            ways=0;
        }
    }

    printf("%I64d ",cost);
    printf("%I64d",methods);


    return 0;
}

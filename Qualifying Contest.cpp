/*
Problem link: http://codeforces.com/problemset/problem/659/B
Problem name: Qualifying Contest

Very soon Berland will hold a School Team Programming Olympiad. From each of the m Berland regions a team of two people is invited to participate in the olympiad. The qualifying contest to form teams was held and it was attended by n Berland students. There were at least two schoolboys participating from each of the m regions of Berland. The result of each of the participants of the qualifying competition is an integer score from 0 to 800 inclusive.

The team of each region is formed from two such members of the qualifying competition of the region, that none of them can be replaced by a schoolboy of the same region, not included in the team and who received a greater number of points. There may be a situation where a team of some region can not be formed uniquely, that is, there is more than one school team that meets the properties described above. In this case, the region needs to undertake an additional contest. The two teams in the region are considered to be different if there is at least one schoolboy who is included in one team and is not included in the other team. It is guaranteed that for each region at least two its representatives participated in the qualifying contest.

Your task is, given the results of the qualifying competition, to identify the team from each region, or to announce that in this region its formation requires additional contests.

Input
The first line of the input contains two integers n and m (2 ≤ n ≤ 100 000, 1 ≤ m ≤ 10 000, n ≥ 2m) — the number of participants of the qualifying contest and the number of regions in Berland.

Next n lines contain the description of the participants of the qualifying contest in the following format: Surname (a string of length from 1 to 10 characters and consisting of large and small English letters), region number (integer from 1 to m) and the number of points scored by the participant (integer from 0 to 800, inclusive).

It is guaranteed that all surnames of all the participants are distinct and at least two people participated from each of the m regions. The surnames that only differ in letter cases, should be considered distinct.

Output
Print m lines. On the i-th line print the team of the i-th region — the surnames of the two team members in an arbitrary order, or a single character "?" (without the quotes) if you need to spend further qualifying contests in the region.

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
    int a,b,n,score,region,m,i,j;

    sc(n);
    sc(m);

    vector<vector<pair<int,string> > > v(m);
    fore(i,1,n){
        string temp;
        cin>>temp;
        sc(region);
        sc(score);
        v[region-1].pb(make_pair(score,temp));
    }
    fore(i,0,m-1){
        sort(rall(v[i]));
    }
    fore(i,0,m-1){
            if(v[i].size()==2){
                    cout<<v[i][0].second<<" ";
                    cout<<v[i][1].second<<"\n";

            }
            else
                if(v[i][2].first==v[i][0].first || v[i][2].first==v[i][1].first){
                printf("?\n");
            }
            else {
                    cout<<v[i][0].second<<" ";
                    cout<<v[i][1].second<<"\n";

            }

        }



    return 0;
}

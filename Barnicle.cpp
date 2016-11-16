/*
Problem link:  http://codeforces.com/problemset/problem/697/B
Problem name: Barnicle

Barney is standing in a bar and starring at a pretty girl. He wants to shoot her with his heart arrow but he needs to know the distance between him and the girl to make his shot accurate.


Barney asked the bar tender Carl about this distance value, but Carl was so busy talking to the customers so he wrote the distance value (it's a real number) on a napkin. The problem is that he wrote it in scientific notation. The scientific notation of some real number x is the notation of form AeB, where A is a real number and B is an integer and x = A × 10B is true. In our case A is between 0 and 9 and B is non-negative.

Barney doesn't know anything about scientific notation (as well as anything scientific at all). So he asked you to tell him the distance value in usual decimal representation with minimal number of digits after the decimal point (and no decimal point if it is an integer). See the output format for better understanding.

Input
The first and only line of input contains a single string of form a.deb where a, d and b are integers and e is usual character 'e' (0 ≤ a ≤ 9, 0 ≤ d < 10100, 0 ≤ b ≤ 100) — the scientific notation of the desired distance value.

a and b contain no leading zeros and d contains no trailing zeros (but may be equal to 0). Also, b can not be non-zero if a is zero.

Output
Print the only real number x (the desired distance value) in the only line in its decimal notation.

Thus if x is an integer, print it's integer value without decimal part and decimal point and without leading zeroes.

Otherwise print x in a form of p.q such that p is an integer that have no leading zeroes (but may be equal to zero), and q is an integer that have no trailing zeroes (and may not be equal to zero).


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
        string n;
        cin>>n;
        string b,d;
        int i;
        char a=n[0];

        for(i=2;;i++){
            if(n[i]=='e'){
                break;
            }
            d+=n[i];
        }
        i=i+1;
        for(;i<n.length();i++){

            b+=n[i];
        }
        int k=atoi(b.c_str());
            cout<<a;
        i=0;
        if(atoi(d.c_str())!=0){
            for(i=0;i<d.length();i++){
                if(i==k){
                    cout<<".";
                }
                cout<<d[i];
            }
        }
        while(i<k){
            cout<<"0";
            i++;
        }
        return 0;
    }

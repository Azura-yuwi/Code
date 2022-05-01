#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main()
{
    int n,c; cin >> n >> c;
    ll p[c];

    for(int i = 0; i < c; i++)
    {
        p[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        p[a]++;
    }

    ll total = (n*(n-1)/2)*(n-2)/3;

    ll halfSum = 0;
    ll pairs = 0; //from different nodes
    int at = (c/2) + 1;

    for(int i = 1; i < at; i++)
    {
        pairs += p[i]*halfSum;
        halfSum += p[i];
    }

    ll sub = 0;

    for(int i = 0; i < c; i++)
    {
        //sub += pairs*p[i]; //three different points
        total -= pairs*p[i];

        if(p[i] >= 2)
        {
            // two points here and 1 point elsewhere
            //sub += p[i]*(p[i]-1)/2*(n-p[i]);
            total -= p[i]*(p[i]-1)/2*(n-p[i]);
            //total -= p[i]*(p[i]-1)/2*(halfSum);
        }
        
        if(p[i] >= 3)
        {
            //sub += p[i]*(p[i]-1)/2*(p[i]-2)/3;
            total -= p[i]*(p[i]-1)/2*(p[i]-2)/3;
        }

        //update halfSum

        if(i < c-1)
        {
            halfSum -= p[i+1];
            pairs -= p[i+1]*halfSum;
        }

        if(c%2 == 0)

        pairs += p[at]*halfSum;
        halfSum += p[at];
        at = (at+1)%c;
    }

    //total -= sub;
    cout << total;    
}
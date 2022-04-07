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
    ll cul[c+1];

    for(int i = 0; i < c; i++)
    {
        p[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        p[a]++;
    }

    cul[0] = 0;

    for(int i = 0; i < c; i++)
    {
        cul[i+1] = cul[i] + p[i];
    }

    ll ans = 0;
    int mid = c/2;

    if(c%2 == 0)
    {
        for(int i = 0; i < mid; i++)
        {
            for(int j = i + 1; j < mid; j++)
            {
                ans += p[i]*p[j]*(cul[j+mid] - cul[i+mid+1]);
            }   
        }

        for(int i = mid; i < c; i++)
        {
            for(int j = i + 1; j < c; j++)
            {
                ans += p[i]*p[j]*(cul[j-mid] - cul[i-mid+1]);
            }   
        }
    }
    else
    {
        for(int i = 0; i < mid; i++)
        {
            for(int j = i + 1; j < mid; j++)
            {
                ans += p[i]*p[j]*(cul[j+mid+1] - cul[i+mid+1]);
            }   
        }

        for(int i = mid; i < c; i++)
        {
            for(int j = i + 1; j < c; j++)
            {
                ans += p[i]*p[j]*(cul[j-mid] - cul[i-mid]);
            }   
        }
    }

    cout << ans;
}
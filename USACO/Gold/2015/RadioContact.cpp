//USACO Gold 2015 December
//DP-grid

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define f first
#define s second

int dx[4] = {0, 0, 1, -1}; //N S E W
int dy[4] = {1, -1, 0, 0};

int main()
{
    ifstream fin("radio.in");
    ofstream fout("radio.out");

    int n, m; fin >> n >> m;

    ll fx, fy, bx, by; fin >> fx >> fy >> bx >> by;

    pair<ll, ll> fpt[n+1];
    pair<ll, ll> bpt[m+1];
    
    ll dp[n+1][m+1];
    dp[0][0] = 0;

    fpt[0] = mp(fx, fy); bpt[0] = mp(bx, by);

    for(int i = 1; i <= n; i++)
    {
        char d; fin >> d;

        if(d == 'N') { fpt[i] = mp(fpt[i-1].f, fpt[i-1].s + 1); }
        else if(d == 'S') { fpt[i] = mp(fpt[i-1].f, fpt[i-1].s - 1); }
        else if(d == 'E') { fpt[i] = mp(fpt[i-1].f + 1, fpt[i-1].s); }
        else { fpt[i] = mp(fpt[i-1].f - 1, fpt[i-1].s); }

        dp[i][0] = pow(fpt[i].f - bx, 2) + pow(fpt[i].s - by, 2) + dp[i-1][0];
    }
    
    for(int i = 1; i <= m; i++)
    {
        char d; fin >> d;

        if(d == 'N') { bpt[i] = mp(bpt[i-1].f, bpt[i-1].s + 1); }
        else if(d == 'S') { bpt[i] = mp(bpt[i-1].f, bpt[i-1].s - 1); }
        else if(d == 'E') { bpt[i] = mp(bpt[i-1].f + 1, bpt[i-1].s); }
        else { bpt[i] = mp(bpt[i-1].f - 1, bpt[i-1].s); }
        
        dp[0][i] = pow(bpt[i].f - fx, 2) + pow(bpt[i].s - fy, 2) + dp[0][i-1];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            dp[i][j] = pow(fpt[i].f - bpt[j].f, 2) + pow(fpt[i].s - bpt[j].s, 2);  
            dp[i][j] += min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
        }
    }

    fout << dp[n][m];
}
//USACO Gold 2020 February
//DP

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

int main()
{
    ifstream fin("help.in");
    ofstream fout("help.out");

    int n; fin >> n;
    int mod = 1e9 + 7;
    vector<pair<int,int>> itvls;
    int ends[2*n + 1];
    int pre[2*n + 1];

    for(int i = 0; i < 2*n+1; i++)
    {
        ends[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        int a,b; fin >> a >> b;

        itvls.pb(mp(a,b));
        ends[b]++;
    }

    pre[0] = 0;

    for(int i = 1; i <= 2*n; i++)
    {
        pre[i] = ends[i] + pre[i-1];
    } 

    int sum = 0;
    sort(itvls.begin(), itvls.end());

    int power[n+1];
    power[0] = 1;

    for(int i = 1; i <= n; i++)
    {
        power[i] = power[i-1]*2;
        power[i] %= mod;
    }

    for(int i = 0; i < n; i++)
    {
        int st = itvls[i].f;
        int k = pre[st-1];
        sum *= 2; sum %= mod;
        sum += power[k]; sum %= mod;
    }

    fout << sum;

}
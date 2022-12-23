//CSES Range Queries
//Prefix Sum

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int n,q;
    cin >> n >> q;
    ll sum[n+1];
    sum[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        ll get; cin >> get;
        sum[i] = sum[i-1] + get;
    }

    for(int i = 0; i < q; i++)
    {
        int a,b;
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << endl;
    }
}
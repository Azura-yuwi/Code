#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second

int main()
{
    int W,H; cin >> W >> H;
    int n; cin >> n;
    int w[n],h[n];

    for(int i = 0; i < n; i++)
    {
        cin >> w[i] >> h[i];
    }

    ll a[W+1][H+1];

    for(int i = 0; i <= W; i++)
    {
        for(int j = 0; j <= H; j++)
        {
            a[i][j] = i*j;
        }
    }

    for(int i = 0; i < n; i++)
    {
        a[w[i]][h[i]] = 0;
    }

    for(int i = 0; i <= W; i++)
    {
        for(int j = 0; j <= H; j++)
        {
            for(int k = 0; k < i; k++)
            {
                a[i][j] = min(a[i][j], a[i-k][j] + a[k][j]);
            }

            for(int k = 0; k < j; k++)
            {
                a[i][j] = min(a[i][j], a[i][k] + a[i][j-k]);
            }
        }
    }

    cout << a[W][H] << endl;


}

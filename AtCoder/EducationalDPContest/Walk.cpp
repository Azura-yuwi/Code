//Matrix Multiplication

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pairiz
#define f first
#define s second

int n; ll k;
const ll mod = 1e9+7;
ll tot[50][50];
ll mat[62][50][50];

ll mult(int on, int r, int c)
{
    ll ret = 0;

    for(int i = 0; i < n; i++)
    {
        ret += ((mat[on][r][i] * mat[on][i][c])%mod); ret %= mod;
    }

    return ret;
}

void upd(int on)
{
    for(int r = 0; r < n; r++)
    {
        for(int c = 0; c < n; c++)
        {
            mat[on][r][c] = mult(on-1, r,c);
        }
    }
}

void add(int on)
{
    ll temp[n][n];

    for(int r = 0; r < n; r++)
    {
        for(int c = 0; c < n; c++)
        {
            temp[r][c] = 0;

            for(int at = 0; at < n; at++)
            {
                temp[r][c] += ((tot[r][at] * mat[on][at][c])%mod); temp[r][c] %= mod;
                
            }
        }
    }

    for(int r = 0; r < n; r++)
    {
        for(int c = 0; c < n; c++)
        {
            tot[r][c] = temp[r][c];
        }
    }
}

ll getAns()
{
    ll ans = 0;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ans += tot[i][j]; ans %= mod;
        }
    }

    return ans;
}

int main()
{
    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> mat[0][i][j];

            if(i == j)
            {
                tot[i][j] = 1;
            }
            else
            {
                tot[i][j] = 0;
            }
        }
    }

    int pow = 0;

    while(k > 0)
    {
        if(k%2 == 1)
        {
            add(pow);
        }

        pow++;
        k /= 2;
        upd(pow);
    }

    cout << getAns();
}

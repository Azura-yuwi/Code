//Range Update
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pairiz
#define f first
#define s second

vector<int> bit;
int sz;
const int mod = 1e9 + 7;

void upd(int i, int v)
{
    for(; i <= sz; i += i&(-i))
    {
        bit[i] = (bit[i] + v)%mod; bit[i] = (bit[i] + mod)%mod;
    }
}

int query(int i)
{
    int sum = 0;

    for(; i > 0; i -= i&(-i))
    {
        sum += bit[i]; sum %= mod;
    }

    return sum;
}


int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);

    int n,k; cin >> n >> k; sz = k+1;
    bit.assign(k+2, 0);
    upd(1,1);
    int can[n];

    for(int i = 0; i < n; i++)
    {
        cin >> can[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = k+1; j > 0; j--)
        {
            int get = query(j);
            int val = (get - query(max(0,j-can[i]-1)) + mod)%mod;
            upd(j, (-1)*((get - query(j-1)+mod))%mod);
            upd(j, val);
        }
    }

    cout << (query(k+1) - query(k) +mod)%mod;
}
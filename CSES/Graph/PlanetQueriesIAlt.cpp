//CSES Graph Algs
//USACO Guide Binary Jumping

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

int tot[200001][30];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n,q; cin >> n >> q;

    for(int i = 0; i < n; i++)
    {
        cin >> tot[i+1][0];
    }

    for(int d = 1; d < 30; d++)
    {
        for(int i = 1; i <= n; i++)
        {
            tot[i][d] = tot[tot[i][d-1]][d-1];
        }
    }

    for(int i = 0; i < q; i++)
    {
        int a,b; cin >> a >> b;
        int at = 0;

        while(b > 0)
        {
            if(b%2 == 1)
            {
                a = tot[a][at];
            }

            at++;
            b /= 2;
        }

        cout << a << endl;
    }
}
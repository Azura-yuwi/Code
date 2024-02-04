//CSES Tree Algorithms
//USACO Guide Binary Jumping

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

int calclog(int n)
{
    int ans = 0; int num = 1;

    while(num < n)
    {
        ans++; num *= 2;
    }

    return ans;
}


int main()
{
    int n,q; cin >> n >> q;
    int boss[n+1];


    int log = calclog(n+1);

    int prepros[n+1][log];

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j < log; j++)
        {
            prepros[i][j] = 0;
        }
    }

    for(int i = 1; i < n; i++)
    {
        cin >> boss[i+1];

        prepros[i+1][0] = boss[i+1];
    }

    for(int d = 1; d < log; d++)
    {
        for(int i = 1; i <= n; i++)
        {
            prepros[i][d] = prepros[prepros[i][d-1]][d-1];
        }
    }

    for(int i = 0; i < q; i++)
    {
        int a,b; cin >> a >> b;

        int at = 0; int ans = a;

        while(b > 0)
        {
            if (b%2 == 1)
            {
                ans = prepros[ans][at];
            }

            at++;
            b /= 2;
        }

        if(ans == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
}
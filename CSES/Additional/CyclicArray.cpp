//CSES Additional Problems
//USACO Guide Binary Jumping

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

const int maxn = 200002;
const int maxd = 22;
int tot[maxn][maxd];

int main()
{
    //cout << "done" << endl;
    //ifstream fin("test.in");
    int n; ll k; cin >> n >> k;
    ll arr[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll sum = 0; int p = 0;

    for(int i = 0; i < n; i++)
    {
        while(sum + arr[p%n] <= k)
        {
           sum += arr[p%n]; p++;

           if(p == n && i == 0)
           {
                cout << 1 << endl;
                return 0;
           }
        }

        tot[i][0] = p; //where the next one starts
        sum -= arr[i];
    }

    //cout << "done" << endl;

    for(int d = 1; d < maxd; d++)
    {
        for(int i = 0; i < n; i++)
        {
            tot[i][d] = tot[tot[i][d-1]%n][d-1]%n + min(n,n*(tot[i][d-1]/n)) + min(n,n*(tot[tot[i][d-1]%n][d-1]/n));
        }
    }
    
    //cout << "done" << endl;
    
    int ans = n+1;

    int mx = 1;
    
    while(mx <= n)
    {
        mx *= 2;
    }

    for(int st = 0; st < n; st++)
    {
        int at = 0;
        int get = mx/2;

        while(get > 0)
        {
            int b = at + get;
            int pow = 0;
            int a = st;

            while(b > 0)
            {
                if(b%2 == 1)
                {
                    a = tot[a%n][pow];
                }

                pow++; b /= 2;
            }

            if(a - st < n)
            {
                at += get;
            }

            get /= 2;
        }

        ans = min(ans, at+1);
    }

    cout << ans << endl;


}
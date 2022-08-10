#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main()
{   
    int n; cin >> n;
    ll h[n];

    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        int high = -1; //index of highest slope one
        int low = -1;  //index of lowest slope one

        for(int j = i+1; j < n; j++)
        {
            if(h[j] == h[i] && high == -1) //not met anythign higher or equal yet
            {
                ans++; high = j;
               // cout << "pair " << i << " " << j << endl;
            }

            if(h[j] < h[i] && high == -1)
            {
                if(low == -1 || (h[i] - h[low])*(j-i) > (h[i] - h[j])*(low-i))
                {
                    ans++;
                    //cout << "pair " << i << " " << j << endl;
                    low = j;
                }
            }

            if(h[j] > h[i])
            {
                if(high == -1 || (h[high] - h[i])*(j-i) < (h[j] - h[i])*(high-i))
                {
                    ans++;
                    //cout << "pair " << i << " " << j << endl;
                    high = j;
                }
            }
        }
    }

    cout << ans;
}
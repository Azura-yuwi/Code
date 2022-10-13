#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main()
{
    int n; cin >> n;
    int st[n];

    for(int i = 0; i < n; i++)
    {
        st[i] = -1;
    }

    for(int i = 0; i < n; i++)
    {
        int v; cin >> v; v--;

        if(st[v] == -1)
        {
            st[v] = i;
        }
        else
        {
            
        }
    }

}
//CSES Sorting and Searching Set
//sort and search...

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int n;
    cin >> n;
    int val[n];

    for(int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    sort(val, val+n);

    int tot = n;

    for(int i = 1; i < n; i++)
    {
        if(val[i] == val[i-1])
        {
            tot--;
        }
    }

    cout << tot;

}
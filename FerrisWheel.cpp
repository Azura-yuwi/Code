//CSES Sorting and Searching Set
//Two Pointer? ish

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int n, w;
    cin >> n >> w;

    int val[n];

    for(int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    sort(val, val+n);

    int point = 0;

    int i;

    for(i = n-1; i >= point; i--)
    {
        if(val[i] + val[point] <= w)
        {
            point++;
        }
    }

    cout << n-i-1;
}
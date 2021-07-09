#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;

    int steps[n+1];

    for(int i = 1; i <= n; i++)
    {
        steps[i] = INT_MAX;
    }
    steps[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        int copy = i;

        while(copy != 0)
        {
            steps[i] = min(steps[i], steps[i- (copy%10)]);
            copy = copy/10;
        }

        if(steps[i] != INT_MAX)
        {
            steps[i]++;
        }
    }

    cout << steps[n];
}
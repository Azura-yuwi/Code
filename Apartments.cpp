//CSES Sorting and Searching Set
//Sort?

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int n,m,k;
    cin >> n >> m >> k;

    int ppl[n];
    int ap[m];

    for(int i = 0; i < n; i++)
    {
        cin >> ppl[i];
    }

    for(int i = 0; i < m; i++)
    {
        cin >> ap[i];
    }

    sort(ppl, ppl + n);
    sort(ap, ap+m);

    int point = 0;
    int work = 0;

    for(int i = 0; i < n; i++)
    {
        //cout << "PERSON " << i << " " << ppl[i] << " " << point << endl;
        //cout << ap[point] << " " << ppl[i]-k << endl;

        while(point < m && ap[point] < ppl[i] - k)
        {
            point++;
        }

        //cout << point << endl;

        if(point < m && ap[point] <= ppl[i] + k)
        {
            work++;
            point++;
        }
    }

    cout << work;
}
